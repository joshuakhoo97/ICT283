#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>

using std::ostream;
using std::istream;
using std::string;

class Date
{
public:
    // Constructors
    Date();
    Date(unsigned newDay, unsigned newMonth, unsigned newYear);


    // Get Methods
    unsigned GetDay()   const;
    unsigned GetMonth() const;
    unsigned GetYear()  const;

    // Set Methods
    void SetDay     (unsigned newDay);
    void SetMonth   (unsigned newMonth);
    void SetYear    (unsigned newYear);

    // Helper Methods
    string ConvertMonth(const unsigned month) const;

private:
    unsigned m_day;
    unsigned m_month;
    unsigned m_year;
};

std::istream& operator>>(std::istream& is, Date& date);
std::ostream& operator<<(std::ostream& os, const Date& date);

#endif // DATE_H_INCLUDED
