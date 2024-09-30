// COURSE.CPP - Course class implementation
#include "UNIT.h"

/*
Constructors
*/

Unit::Unit()
    :  m_credits(0)
{
    // Arrays (C-style strings) need to be initialized in the constructor body
    m_name[0]   = '\0'; // it is a char * string, not a C++ string object.
    m_unitId[0] = '\0';
}

Unit::Unit( const char * name, const char * unitId, unsigned credits )
    : m_credits(credits)
{
    // Arrays (C-style strings) need to be initialized in the constructor body
    strncpy(m_name, name, UNIT_NAME_SIZE);  //strncpy needed from string.h
    strncpy(m_unitId, unitId, UNIT_ID_SIZE);
}


/*
Get Methods
*/

const char*     Unit::GetUnitName()   const
{
    return m_name;
}

const char*     Unit::GetUnitId()     const
{
    return m_unitId;
}

unsigned Unit::GetCredits() const
{
    return m_credits;
}


/*
Set Methods
*/
void Unit::SetUnitName(const char* newUnitName)
{
    strncpy(m_name, newUnitName, UNIT_NAME_SIZE - 1);
    m_name[UNIT_NAME_SIZE - 1 ] = '\0';
}

void Unit::SetUnitId  (const char* newUnitId)
{
    strncpy(m_unitId, newUnitId, UNIT_ID_SIZE - 1);
    m_unitId[UNIT_ID_SIZE - 1] = '\0';
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
    char unitName[UNIT_NAME_SIZE];
    char unitId  [UNIT_ID_SIZE];
    int  credits;

    input >> unitName >> unitId >> credits;

    unit.SetUnitName(unitName);
    unit.SetUnitId(unitId);
    unit.SetCredits(credits);

    return input;
}


std::ostream & operator <<( ostream & os, const Unit & unit )
{
    os << "  Unit   : " << unit.GetUnitName()   << '\n'
       << "  Unit Id: " << unit.GetUnitId()     << '\n'
       << "  Credits: " << unit.GetCredits()    << '\n';

    return os;
}

