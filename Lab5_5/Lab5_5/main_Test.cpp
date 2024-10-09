#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <cctype>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::cerr;


// Structs
typedef struct
{

    Date d;
    Time t;
    float speed;

    float getSpeedInKm() const
    {
        return speed * 3.6f;
    }

} WindRecType;

// Realised Vector of WindRecType named WindLogType
typedef Vector<WindRecType> WindLogType;

//FUNCTIONS

// Utility Functions
ifstream openFile(const string& fileName);

Vector<string> splitLine(const string& line, char delimiter);

int returnIndex(const Vector<string>& columnHeaders, string& columnHeader);

template <typename T> void printContentsVec (const Vector<T>& vec );

void printWRT(const Vector<WindRecType>& windLog, size_t index);


// Processing Functions
void processLine(const string& line, size_t indexDateTime, size_t indexWindSpeed, Vector<string>& rowData, Vector<string>& datePartsVec,
                 Vector<string>& timePartsVec, Vector<string>& windSpeedVec);

void storeWRT(WindLogType& windLog, const string& dateParts, const string& timeParts, const string& windSpeedStr);

// Validation Functions
bool equalsIgnoreCase(const string& str1, const string& str2);


// Modifying Functions
void modifyDate(Date& date, const std::string& dateString);


void modifyTime(Time& time, const std::string& timeString);


void modifyWRT(WindRecType& wrt, const Date& date, const Time& time, const float windSpeed);



int main()
{

    /* To do:
       1) Read Data /
       2) Process Lines
       3) Create Objects
       4) Store Objects and ensure speed stored is in km/h
       5) Print Objects
       6)
    */

    // 1) Read Data
    // Using a relative file path to access data folder and correct file
    string fileName = "data\\MetData_Mar01-2014-Mar01-2015-ALL.csv";
    ifstream file = openFile(fileName);


//    // Debug Line: Test the result of openFile(fileName);
//    int testLines = 3;
//    string line;
//
//    for (int i = 0; i < testLines; i++)
//    {
//        getline(file, line);
//        cout << line << endl;
//    }

//========================== END OF READ FILE ==========================

    // 2) Get Column index for processing

    // Store line in file
    string line;
    // Get 1st line of column headers
    getline(file, line);

    // Vector to store each row's data
    Vector<string> rowData = splitLine(line, ',');

    // string to store headers associations
    string dateTime = "WAST";
    string windSpeed = "S";

    // size_t to ensure consistent data types when comparing in for loop
    int indexDateTime = returnIndex(rowData, dateTime);
    int indexWindSpeed = returnIndex(rowData, windSpeed);

    // Debug Line: Test the result of equalsIgnoreCase(str1, str2);

    // Debug Line: Test the result of returnIndex()
//    cout << indexDateTime << " & " << indexWindSpeed << endl;

//========================== END OF GET COLUMN INDEX ==========================

    // 3) Get Subsequent Row Data corresponding to indexes and create objects accordingly

    // Debug Line: Check if the pointer is pointing at the next line for reading
//    getline(file, line);
//
//    cout << line << endl;

    string dateTimeUnsplit;
    Vector<string> tempVec;
    Vector<string> datePartsVec;
    Vector<string> timePartsVec;
    Vector<string> windSpeedVec;

    // While loop to get the rest of the lines
    // Processing 1 line at a time
    while(getline(file, line))
    {
        processLine(line, indexDateTime, indexWindSpeed, rowData, datePartsVec, timePartsVec, windSpeedVec);
    }


    // Debug Line: Test if split line was successful to derive
    // 1) at position 0 date
    // 2) at position 1 time
    // Out side of while loop so as to print only one set for testing
//    cout << temp.at(0) << endl;
//    cout << temp.at(1) << endl;

    // Debug Line: Print contents of Vector
//    printContentsVec(datePartsVec);
//    printContentsVec(timePartsVec);
//    printContentsVec(windSpeedVec);

//========================== END OF GET ALL RELEVANT DATA ==========================

    // 4) Process data and create objects

    // Create WindLogType vector
    WindLogType windLog;

    // i can be pegged against any of the 3 data vectors as all of their sizes should match
    // however dates would be the most accurate
    for(size_t i = 0; i < datePartsVec.getSize(); i++)
    {
        storeWRT(windLog, datePartsVec.at(i), timePartsVec.at(i), windSpeedVec.at(i));
    }

    for(size_t i = 0; i < 3; i++)
    {
        printWRT(windLog, i);
    }

//========================== STORE WINDRECTYPE OBJECTS IN VECTOR ==========================

    // 5) Write to outfile "testoutput.csv"

    string outfileName = "testoutput.csv";

    ofstream outFile(outfileName);

    if(!outFile.is_open())
    {
        cerr << "Failed to open file: " << outfileName << endl;
        return 1;
    }

    outFile << "Date,Time,Wind Speed (km/h)" << endl;

    for(size_t i = 0; i < 5; i++)
    {
        // Write date in dd/mm/yyyy format
        outFile << windLog.at(i).d.GetDay() << "/"
                   << windLog.at(i).d.ConvertMonth(windLog.at(i).d.GetMonth()) << "/"
                   << windLog.at(i).d.GetYear() << ",";

        // Write time in hh:mm format
        outFile << windLog.at(i).t.GetHour() << ":"
                   << windLog.at(i).t.GetMins() << ",";

        // Write wind speed
        outFile << windLog.at(i).getSpeedInKm() << std::endl;
    }



    outFile.close();

    return 0;
}




// Utility Functions
ifstream openFile(const string& fileName)
{

    ifstream file(fileName);

    if(file.is_open())
    {
        cout << "File read success" << endl;
    }

    if (!file.is_open())
    {
        cerr << "Failed to open file: " << fileName << endl;
    }



    return file;  // Return the file stream (opened or empty)
}


Vector<string> splitLine(const string& line, char delimiter)
{
    Vector<string> result;
    stringstream ss(line);
    string item;

    while (getline(ss, item, delimiter))
    {
        result.push_back(item);
    }

    return result;
}


int returnIndex(const Vector<string>& columnHeaders, string& columnHeader)
{
    for(size_t i = 0; i < columnHeaders.getSize(); i++)
    {
        // compares the columnHeaders at(position i) against columnHeader
        // using own equalsIgnoreCase function to compare strings
        if(equalsIgnoreCase(columnHeaders.at(i),columnHeader))
        {
            // Returns index if found
            return i;
        }
    }

    return -1;
}


template <typename T>
void printContentsVec (const Vector<T>& vec )
{
    for(size_t i = 0; i < vec.getSize(); i++)
    {
        cout <<  vec.at(i) << " ";
    }

    cout << endl;
}


void printWRT(const Vector<WindRecType>& windLog, size_t index)
{
    // Check if there is data: this check ensures windLog is correctly populated
    if(windLog.getCapacity() == 0 )
    {
        cout << "No Data" << endl;
    }
    else if(index > windLog.getSize())
    {
        cout << "Index out of range" << endl;
    }

    // Date
    cout << windLog.at(index).d.GetDay() << "/"
         << windLog.at(index).d.ConvertMonth(windLog.at(index).d.GetMonth()) << "/"
         << windLog.at(index).d.GetYear() << ",";

    // Time
    cout << windLog.at(index).t.GetHour() << ":"
         << windLog.at(index).t.GetMins() << ",";

    // WindSpeed
    cout << windLog.at(index).getSpeedInKm() << "km/h" << endl;
}


// Processing Functions
void processLine(const string& line,
                 size_t indexDateTime, size_t indexWindSpeed,
                 Vector<string>& rowData,
                 Vector<string>& datePartsVec,
                 Vector<string>& timePartsVec,
                 Vector<string>& windSpeedVec)
{
    rowData = splitLine(line, ',');  // Split the line by commas

    // Extract and split date-time
    string dateTimeUnsplit = rowData.at(indexDateTime);
    Vector<string> tempVec = splitLine(dateTimeUnsplit, ' ');  // Split by space

    // Store date and time parts
    datePartsVec.push_back(tempVec.at(0));  // dd/mm/yyyy
    timePartsVec.push_back(tempVec.at(1));  // hh:mm

    // Store wind speed
    windSpeedVec.push_back(rowData.at(indexWindSpeed));
}


void storeWRT(WindLogType& windLog, const string& dateParts, const string& timeParts, const string& windSpeedStr)
{
    // Default objects
    Date date;
    Time time;
    WindRecType wrt;

    // Modify
    modifyDate(date, dateParts);
    modifyTime(time, timeParts);
    modifyWRT(wrt, date, time, stof(windSpeedStr));

    windLog.push_back(wrt);
}


// Validation Functions
bool equalsIgnoreCase(const string& str1, const string& str2)
{

    if (str1.size() != str2.size())
    {

        return false;
    }

    for (size_t i = 0; i < str1.size(); ++i)
    {
        // static_cast<unsigned char> to safely convert each character to its
        // unsigned acii value
        if (std::tolower(static_cast<unsigned char>(str1[i])) !=
                std::tolower(static_cast<unsigned char>(str2[i])))
        {


            return false;
        }
    }
    return true;
}


// Modifying Functions
void modifyDate(Date& date, const std::string& dateString) {

    Vector<std::string> dateParts;

    dateParts = splitLine(dateString, '/');

    // Use accessors to modify date
    date.SetDay     (stoul(dateParts.at(0)));
    date.SetMonth   (stoul(dateParts.at(1)));
    date.SetYear    (stoul(dateParts.at(2)));

}


void modifyTime(Time& time, const std::string& timeString) {

    Vector<std::string> timeParts;

    timeParts = splitLine(timeString, ':');

    // Use accessors to modify time
    time.SetHour(stoul(timeParts.at(0)));
    time.SetMins(stoul(timeParts.at(1)));
}


void modifyWRT(WindRecType& wrt, const Date& date, const Time& time, const float windSpeed)
{
    wrt.d       = date;
    wrt.t       = time;
    wrt.speed   = windSpeed;
}



