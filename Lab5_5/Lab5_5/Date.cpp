#include "Date.h"

// Constructors
Date::Date()
    : m_day(0), m_month(0), m_year(0), m_valid(IsValid()) {}

Date::Date(unsigned newDay, unsigned newMonth, unsigned newYear)
    : m_day(newDay), m_month(newMonth), m_year(newYear), m_valid(IsValid()){}

// Get Methods
unsigned Date::GetDay()   const
{
    return m_day;
}

unsigned Date::GetMonth() const
{
    return m_month;
}

unsigned Date::GetYear()  const
{
    return m_year;
}

bool Date::GetValidity() const
{
    return m_valid;
}

// Set Methods
void Date::SetDay     (unsigned newDay)
{
    m_day   = newDay;
    m_valid = IsValid();
}

void Date::SetMonth   (unsigned newMonth)
{
    m_month = newMonth;
    m_valid = IsValid();
}

void Date::SetYear    (unsigned newYear)
{
    m_year = newYear;
    m_valid = IsValid();
}

// Helper Methods
string Date::ConvertMonth(const unsigned month) const
{
    switch(month)
    {
        case 1:  return "January";
        case 2:  return "February";
        case 3:  return "March";
        case 4:  return "April";
        case 5:  return "May";
        case 6:  return "June";
        case 7:  return "July";
        case 8:  return "August";
        case 9:  return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Month Incorrect";
    }
}

// Validation Methods
bool Date::IsLeapYear() const
{
    return (m_year % 4 == 0 && m_year % 100 != 0) || (m_year & 400 == 0);
}

// To return the maximum number of days for each month
// Checking for the year as well for case 2
int Date::DaysInMonth() const {
    switch (m_month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
//      IsLeapYear True or False ? T  : F
            return IsLeapYear()  ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

bool Date::IsValid() const
{
    if(m_month < 1 || m_month > 12)
    {
        return false;
    }

    if (m_day < 1 || m_day > DaysInMonth())
    {
        return false;
    }

    return true;
}
