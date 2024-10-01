#include "Registration.h"

/*
Constructor
*/

Registration::Registration()
{
    m_studentId = 000000;
    m_semester  = 0;
    m_count     = 0;
}

/*
Get methods
*/

long        Registration::GetStudentId() const
{
    return m_studentId;
}

unsigned    Registration::GetSemester() const
{
    return m_semester;
}

unsigned    Registration::GetCount() const
{
    return m_count;
}

unsigned    Registration::GetCredits() const
{
    unsigned sum = 0;
    // because the GetUnit returns by reference
    Unit tempUnit;
    for(unsigned i = 0; i < m_count; i++)
    {
        // GetUnit to return attribute via reference
        m_results[i].GetUnit(tempUnit);
        sum += tempUnit.GetCredits();
    }

    return sum;
}

// Access an individual result
const       Result& Registration::GetResult (unsigned index) const
{
    static Result defaultR;
    if(index < m_count)
    {
        return m_results[index];
    }
    else
    {
        std::cout << "index out of bounds" << std::endl;
        return defaultR;
    }
}

// Access the array of results
const       Result* Registration::GetAllResults () const
{
    return m_results;
}

/*
Set methods
*/

void Registration::SetStudentId(long studentId)
{
    m_studentId = studentId;
}

void Registration::SetSemester  (unsigned semester)
{
    m_semester = semester;
}

void Registration::SetCount     (unsigned newCount)
{
    m_count = newCount;
}

void Registration::AddResult    (const Result& result)
{
    if(m_count >= MAX_RESULT){
        std::cout << "Error, Records limit exceed 10 " + MAX_RESULT - m_count  << std::endl;
    }
    else{
        m_results[m_count] = result;
        m_count++;
    }
}


// Over Loaded   << | >> operators
std::istream & operator >>( istream & input, Registration & r )
{
    // To store 1st line
    string tempStr;
    std::getline(input, tempStr, ','); // stores 102234
    r.SetStudentId(stol(tempStr));

    std::getline(input, tempStr, ','); // stores 9
    r.SetSemester(stoul(tempStr));

    std::getline(input, tempStr); // stores 4
    unsigned newCount = stoul(tempStr);

    // To do:
    // Use set methods to populate objects

    Result newResult;

    for(unsigned i = 0; i < newCount; i++) // unsigned means an int that is positive
    {
        input >> newResult;
        r.AddResult(newResult);
    }

    return input;
}

std::ostream & operator << ( ostream & os, const Registration & registration )
{

    os << "Student ID: " << registration.GetStudentId() << '\n'
       << "Semester:   " << registration.GetSemester()  << '\n'
       << "Unit Count: " << registration.GetCount()     << '\n';

    for(unsigned i = 0; i < registration.GetCount(); i++)
    {
        os << registration.GetResult(i) << '\n';
    }

    return os;
}
