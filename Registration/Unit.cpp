// COURSE.CPP - Course class implementation
#include "UNIT.h"

/*
Constructors
*/

Unit::Unit()
{
    m_name   = "Default";
    m_unitId = "Default";
    m_credits = 0;
}

Unit::Unit( const string& name, const string& unitId, unsigned credits )

{
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
    unit.SetCredits(stoul(tempStr));

    return input;
}


std::ostream & operator <<( ostream & os, const Unit & unit )
{
    os << "  Unit   : " << unit.GetUnitName()   << '\n'
       << "  Unit Id: " << unit.GetUnitId()     << '\n'
       << "  Credits: " << unit.GetCredits()    << '\n';

    return os;
}

