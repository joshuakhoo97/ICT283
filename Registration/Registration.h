#ifndef REGIST_H
#define REGIST_H

#include "Result.h"     //#include your own files first
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

const unsigned MAX_RESULT = 10;

    /**
     * \class Registration
     * \brief Represents a student's registration details including results of enrolled units.
     *
     * The Registration class stores information about a student's registration details, such as
     * their student ID, semester, and results for different courses. It provides methods to add,
     * retrieve, and manipulate results.
     *
     * \author Joshua Khoo
     * \date   30/09/2024
     * \version 1.0 started
     *
     * \author Joshua Khoo
     * \date   02/10/2024
     * \version 2.0 final
     */
class Registration
{
public:
    /**
     * \brief Default constructor for the Registration class.
     *
     * Initializes a Registration object with default values for the student ID, semester, and results.
     */
    Registration();

    /**
     * \brief Parameterized constructor to initialize the Registration object.
     *
     * Initializes the Registration object with a specific student ID, semester, number of results, and an array of results.
     *
     * \param studentId The student's ID number.
     * \param semester The semester in which the student is enrolled.
     * \param newCount The number of results (units) for this registration.
     * \param results An array of Result objects representing the student's results.
     */
    Registration(long studentId, unsigned semester, unsigned newCount, const Result results[]);

    /**
     * \brief Retrieves the number of results (units) the student has registered for.
     *
     * \return The number of units the student is registered for.
     */
    unsigned GetCount() const;

    /**
     * \brief Retrieves the student's ID number.
     *
     * \return The student's ID number as a long integer.
     */
    long GetStudentId() const;

    /**
     * \brief Retrieves the semester number for this registration.
     *
     * \return The semester as an unsigned integer.
     */
    unsigned GetSemester() const;

    /**
     * \brief Calculates and retrieves the total number of credits from all registered units.
     *
     * \return The total number of credits from all results.
     */
    unsigned GetCredits() const;

    /**
     * \brief Retrieves an individual result based on the index.
     *
     * If the index is valid, the method returns the Result at that index.
     * If the index is out of bounds, it returns a default result and prints an error message.
     *
     * \param index The index of the result to retrieve.
     * \return A reference to the Result object at the given index.
     */
    const Result& GetResult(unsigned index) const;

    /**
     * \brief Retrieves all the results.
     *
     * Returns a pointer to the array of results.
     *
     * \return A pointer to an array of Result objects.
     */
    const Result* GetAllResults() const;

    /**
     * \brief Sets the number of units (results) the student is registered for.
     *
     * \param newCount The new number of results to set.
     */
    void SetCount(unsigned newCount);

    /**
     * \brief Sets the student's ID number.
     *
     * \param studentId The student's ID number to set.
     */
    void SetStudentId(long studentId);

    /**
     * \brief Sets the semester for the student's registration.
     *
     * \param semester The semester number to set.
     */
    void SetSemester(unsigned semester);

    /**
     * \brief Adds a new result to the student's registration.
     *
     * Adds a result to the list of results for this registration, if the maximum limit of results has not been exceeded.
     *
     * \param result The Result object to add.
     */
    void AddResult(const Result& result);

private:
    long      m_studentId;            ///< The student's ID number.
    unsigned  m_semester;             ///< The semester the student is registered in.
    unsigned  m_count;                ///< The number of units the student is registered for.
    Result    m_results[MAX_RESULT];  ///< An array of results (up to MAX_RESULT).
};

    /**
     * \brief Overloaded insertion operator for printing Registration objects.
     *
     * Outputs the details of the registration, including student ID, semester, and results, to the output stream.
     *
     * \param os The output stream object.
     * \param registration The Registration object to print.
     * \return The modified output stream object.
     */
ostream& operator<<(ostream& os, const Registration& registration);

    /**
     * \brief Overloaded extraction operator for reading Registration objects.
     *
     * Reads the details of the registration, including student ID, semester, and results, from the input stream.
     *
     * \param input The input stream object.
     * \param registration The Registration object to populate.
     * \return The modified input stream object.
     */
istream& operator>>(istream& input, Registration& registration);

#endif // REGIST_H
