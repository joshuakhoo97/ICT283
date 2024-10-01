#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED
#include <iostream>
#include "Unit.h"
#include "Date.h"

using std::string;
using std::ostream;
using std::istream;

class Result
{
public:

    // Constructors (default)
    Result();

    // Get Methods
    int     GetMark() const;
    void    GetUnit(Unit &unit ) const;
    void    GetDate(Date &date ) const;

    // Set Methods
    void    SetUnit(const Unit& unit);
    void    SetMark(int mark);
    void    SetDate(const Date& date);

private:
    Unit    m_unit; // Construct a unit with default constructor
    int     m_mark;
    Date    m_date;
};

ostream & operator << (ostream & os, const Result & result);
istream & operator >>( istream & input, Result & result ); // function

#endif // RESULT_H_INCLUDED
