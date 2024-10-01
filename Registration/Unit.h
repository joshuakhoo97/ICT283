#ifndef UNIT_H
#define UNIT_H

#include <iostream>

using std::string;
using std::ostream;
using std::istream;


/**
 * \class Unit
 * \brief Represents a course unit, storing unit name, ID, and credit information.
 */
class Unit
{
public:

    // Constructors
    Unit();

    /** \brief --> Parameterized Constructor to initialize attirbutes
     *
     * \param name initializes m_name
     * \param unitId initialized m_unitId
     * \param credits initializes m_credits
     *
     *
     */
    Unit( const string& name, const string& unitId, unsigned credits );  // nam is a pointer to char, revise ict159


    // Get Methods

    string      GetUnitName()   const;
    string      GetUnitId()     const;

    /** \brief Retrieves the Credits
     *
     * \return credits obtained
     *
     */
    unsigned    GetCredits()    const;


    // Set Methods
    void SetUnitName(const string &newUnitName);
    void SetUnitId  (const string &newUnitId); // parameter is read only
    void SetCredits (unsigned credits);


private: // Naming convention 'm_' for attributes

    string  m_name;    // course name, C style string. not a C++ string object
    string  m_unitId;    // unitId, C style string. not a C++ string object
    int     m_credits;                 // number of credits
};

// Non-member functions
ostream & operator <<( ostream & os, const Unit & unit );
istream & operator >>( istream & input, Unit & unit );

#endif

//use doxyblocks on top panel use block comment in the header file;
//
//doxywizard
//
//-> select folder the current folder
//--> project name everything
//--> Mode --> select 2 and 3 radio button
//    - second portion select 2nd radio button
//
//    Output
//--> Html - 2 and 4
//--> 2nd part 1st radio button and the 2nd part checked
//
//Diagrams
//--> 3rd and everything onwards radio button
//
//
//Expert tab
//--> Dot - everything square box checked
//
//DOT_PATH ==> Locate Graphviz bin folder; C - programfiles x86 - graphviz - bin
//
//Go to run --> run doxygen
//
//- Show html output
