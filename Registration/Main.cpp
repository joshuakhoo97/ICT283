#include "Registration.h"  // Registration class declaration/interface

// The library header files
#include <iostream>
#include <fstream>


using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

// Main Program Functions


void PrintFileContent(ifstream &infile); ///< used for debugging to ensure ifstream reads input file correctly

int main()
{

    // In file
    ifstream infile( "rinput.txt" );
    // Check if File Opens
    if( !infile )
    {
        cout << "Check File Name or if file is in the same folder as code: " endl;
    }

    // Create Registration Object
    Registration r;
    // Use overloaded operators to populate data
    infile >> r;

    // Out file
    ofstream ofile( "routput.txt" );

    // write to out file
    // using overloaded operators to write contents of registration object
    ofile << r
          // As shown in Lab 4
          << "Number of courses = " << r.GetCount() << '\n'
          << "Total credits     = " << r.GetCredits() << '\n';

    // Print to check Contents of r --> Registration object
    // Commented out but can remove '//' on line 46 or before cout to reveal
    // cout << r << endl;

    return 0;
}

// Main Program Functions

void PrintFileContent(ifstream &infile)
{
    cout << "File Content: " << endl;
    string line;
    while(getline(infile, line))
    {
        cout << line << endl;
    }
}
