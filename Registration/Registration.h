// REGIST.H - Registration class definition/interface
// author KRI
// modified smr

#ifndef REGIST_H
#define REGIST_H
#include "Result.h"     //#include your own files first
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;


const unsigned MAX_RESULT = 10;

class Registration
{
public:

  // Constructors
  Registration();


  // Get Methods
  unsigned  GetCount()      const;
  long      GetStudentId()  const;
  unsigned  GetSemester()   const;
  unsigned  GetCredits()    const;
  const     Result& GetResult   (unsigned index) const;  // Access an individual result
  const     Result* GetAllResults  ()               const;  // Access all results in the array


  // Set Methods
  void SetCount     (unsigned newCount);
  void SetStudentId (long studentId);
  void SetSemester  (unsigned semester);

  // Add Method
  void AddResult    (const Result& result); // Result is created, modified by Result class

private:
  long      m_studentId;            // student ID number
  unsigned  m_semester;             // semester year, number
  unsigned  m_count;                // number of courses
  Result    m_results[MAX_RESULT];  // array of courses
};

ostream & operator << ( ostream & os, const Registration & registration);    // function
istream & operator >> ( istream & input, Registration & registration );      // function

#endif
