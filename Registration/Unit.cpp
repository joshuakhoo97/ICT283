// COURSE.CPP - Course class implementation
#include "UNIT.h"

/*
Constructors
*/

Unit::Unit()
{
    // Arrays (C-style strings) need to be initialized in the constructor body
    m_name   = " "; // it is a char * string, not a C++ string object.
    m_unitId = " ";
    m_credits = 0;
}

Unit::Unit( const string& name, const string& unitId, unsigned credits )
//m_name = name, m_unitId = unitId, m_credits = 0
{
//    // Arrays (C-style strings) need to be initialized in the constructor body
//    strncpy(m_name, name, UNIT_NAME_SIZE);  //strncpy needed from string.h
//    strncpy(m_unitId, unitId, UNIT_ID_SIZE);

    m_name      = name;
    m_unitId    = unitId;
    m_credits   = credits;
}


/*
Get Methods
*/

string     Unit::GetUnitName()   const
{
    return m_name;
}

string     Unit::GetUnitId()     const
{
    return m_unitId;
}

unsigned    Unit::GetCredits()   const
{
    return m_credits;
}


/*
Set Methods
*/
void Unit::SetUnitName(const string &newUnitName)
{
    m_name = newUnitName;
}

void Unit::SetUnitId  (const string  &newUnitId)
{
    m_unitId = newUnitId;
}

void Unit::SetCredits( unsigned credits )
{
    m_credits = credits;
}


/*
Non-Member functions
*/
std::istream & operator >>( istream & input, Unit & unit)
{
    // Destination to store input temporarily
    string tempStr;

    // Unit Name
    std::getline(input, tempStr, ',');
    unit.SetUnitName(tempStr);

    // Unit Id
    std::getline(input, tempStr , ',');
    unit.SetUnitId(tempStr);

    // Credits
    std::getline(input, tempStr, ',');
    unit.SetCredits(stoi(tempStr));

    return input;
}


std::ostream & operator <<( ostream & os, const Unit & unit )
{
    os << "  Unit   : " << unit.GetUnitName()   << '\n'
       << "  Unit Id: " << unit.GetUnitId()     << '\n'
       << "  Credits: " << unit.GetCredits()    << '\n';

    return os;
}

