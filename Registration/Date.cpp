#include "Date.h"

// Constructors
Date::Date()
{
    m_day   = 0;
    m_month = 0;
    m_year  = 9999;
}

Date::Date(unsigned newDay, unsigned newMonth, unsigned newYear)
{
    m_day   = newDay;
    m_month = newMonth;
    m_year  = newYear;
}

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

// Set Methods
void Date::SetDay     (unsigned newDay)
{
    m_day = newDay;
}

void Date::SetMonth   (unsigned newMonth)
{
    m_month = newMonth;
}

void Date::SetYear    (unsigned newYear)
{
    m_year = newYear;
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
        default: return "Invalid Month";
    }
}

std::istream& operator>>(std::istream& input, Date& date)
{
    string tempStr;

    std::getline(input, tempStr, '/');
    date.SetDay(stoul(tempStr));

    std::getline(input, tempStr, '/');
    date.SetMonth(stoul(tempStr));

    std::getline(input, tempStr);
    date.SetYear(stoul(tempStr));

    return input;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.GetDay() << " " << date.ConvertMonth(date.GetMonth()) << " " << date.GetYear();

    return os;
}
