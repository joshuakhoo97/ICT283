#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED
#include <iostream>
#include "Unit.h"

using std::ostream;
using std::istream;

class Result
{
public:

    // Constructors (default)
    Result();

    // Get Methods
    int     GetMark() const;
    void    GetUnit(Unit &unit ) const;    // Do not modify attribute

    // Set Methods
    void    SetUnit(const Unit& unit);     // do not modify parameter
    void    SetMark(int mark);

private:
    Unit    m_unit; // Construct a unit with default constructor
    int     m_mark;
};

ostream & operator << (ostream & os, const Result & result);
istream & operator >>( istream & input, Result & result ); // function

#endif // RESULT_H_INCLUDED
