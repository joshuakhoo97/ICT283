#include "RESULT.h"


Result::Result()
{
    m_mark = 0;
}

// Get Methods
int     Result::GetMark() const
{
    return m_mark;
}

void    Result::GetUnit(Unit &unit) const
{
    unit = m_unit; // return attribute to parameter via reference

}  // Do not modify attribute


void    Result::GetDate(Date &date ) const
{
    date = m_date;
}


// Set Methods
void    Result::SetMark(int mark)
{
    m_mark = mark;
}

void    Result::SetUnit(const Unit& unit)
{
    m_unit = unit; // Assigning parameter to attribute
}  // do not modify parameter

void    Result::SetDate(const Date& date)
{
    m_date = date;
}


/*
    FUNCTIONS
*/

std::ostream & operator << (ostream & os, const Result & result)
{
    Unit unit;
    Date date;
    result.GetUnit(unit); // Use getter to access the unit
    result.GetDate(date);
    os << unit  // Assuming the Unit class overloads << for printing
       << "  Mark   : " << result.GetMark() << '\n'// Use getter to access the mark
       << "  Date   : " << date << '\n';

    return os;
}

std::istream & operator >> (istream & input, Result & result)
{
    Unit unit;

    input >> unit;
    result.SetUnit(unit);


    string tempStr;
    std::getline(input, tempStr, ',');
    result.SetMark(stoi(tempStr));

    Date newDate;

    std::getline(input, tempStr, '/');
    newDate.SetDay(stoul(tempStr));

    std::getline(input, tempStr, '/');
    newDate.SetMonth(stoul(tempStr));

    std::getline(input, tempStr);
    newDate.SetYear(stoul(tempStr));

    result.SetDate(newDate);

    return input;
}
