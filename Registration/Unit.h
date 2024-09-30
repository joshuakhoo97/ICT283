#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <cstring>

using namespace std;

// Although the usage of unsigned here is fine, usage of unsigned type can be problematic.
// Can you think of what problems can occur? --> When need to perform arithmetic operations that could
// potentially lead to negative number

const unsigned UNIT_NAME_SIZE       = 50;
const unsigned UNIT_ID_SIZE         = 10;

class Unit
{
public:

    // Constructors
    Unit();
    Unit( const char * name, const char * unitId, unsigned credits );  // nam is a pointer to char, revise ict159


    // Get Methods
    const char*     GetUnitName()   const;
    const char*     GetUnitId()     const;
    unsigned        GetCredits()    const;


    // Set Methods
    void SetUnitName(const char* newUnitName);
    void SetUnitId  (const char* newUnitId);
    void SetCredits (unsigned credits);


private: // Naming convention 'm_' for attributes

    char m_name[UNIT_NAME_SIZE];    // course name, C style string. not a C++ string object
    char m_unitId[UNIT_ID_SIZE];    // unitId, C style string. not a C++ string object
    int  m_credits;                 // number of credits
};

// Non-member functions
ostream & operator <<( ostream & os, const Unit & unit );
istream & operator >>( istream & input, Unit & unit );

#endif
