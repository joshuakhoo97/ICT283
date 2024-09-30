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

// Set Methods
void    Result::SetMark(int mark)
{
    m_mark = mark;
}

void    Result::SetUnit(const Unit& unit)
{
    m_unit = unit; // Assigning parameter to attribute
}  // do not modify parameter


std::ostream & operator << (ostream & os, const Result & result)
{
    Unit unit;
    result.GetUnit(unit); // Use getter to access the unit
    os << unit  // Assuming the Unit class overloads << for printing
       << "  Mark    : " << result.GetMark() << '\n'; // Use getter to access the mark

    return os;
}

std::istream & operator >> (istream & input, Result & result)
{
    Unit unit;
    int mark;

    input >> unit >> mark;  // Assuming Unit class supports >> operator for input

    // Set Methods to populate Result object
    result.SetUnit(unit);   // Use setter to update the unit
    result.SetMark(mark);   // Use setter to update the mark

    return input;
}
