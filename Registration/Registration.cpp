#include "Registration.h"

/*
Constructor
*/

Registration::Registration()
    : m_studentId(0), m_semester(0), m_count(0)
{

}

/*
Get methods
*/

unsigned    Registration::GetCount() const
{
    return m_count;
}

long        Registration::GetStudentId() const
{
    return m_studentId;
}

unsigned    Registration::GetSemester() const
{
    return m_semester;
}

unsigned    Registration::GetCredits() const
{
    unsigned sum = 0;
    Unit tempUnit; // because the GetUnit is void so we have to do this
    for(unsigned i = 0; i < m_count; i++)
    {
        m_results[i].GetUnit(tempUnit); // return attribute via reference
        sum += tempUnit.GetCredits();
    }

    return sum;
}

const       Result& Registration::GetResult (unsigned index) const  // Access an individual result
{
    static Result defaultR;
    if(index < m_count)
    {
        return m_results[index];
    }
    else
    {
        cout << "index out of bounds" << endl;
        return defaultR;
    }
}


const       Result* Registration::GetAllResults () const // Access array of results
{
    return m_results;
}

/*
Set methods
*/

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
        cout << "Error, Records limit exceed 10 " + MAX_RESULT - m_count  << endl;
    }
    else{
        m_results[m_count] = result;
        m_count++;
    }
}

void Registration::SetStudentId(long studentId)
{
    m_studentId = studentId;
}


// Over Loaded   << | >> operators

std::istream & operator >>( istream & input, Registration & registration )
{
    // To store input
    long studentId;
    unsigned semester, newCount;
    Result result;

    input >> studentId >> semester >> newCount;

    // To do:
    // Use set methods to populate objects
    registration.SetStudentId(studentId);
    registration.SetSemester(semester);

    for(unsigned i = 0; i < newCount; i++) // unsigned means an int that is positive
    {
        // track down which >> operator is called. Hint: look at what is being input.
        input >> result;

        // To do: Create Set Result method
        registration.AddResult(result);
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
