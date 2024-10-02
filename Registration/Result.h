#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include <iostream>
#include "Unit.h"
#include "Date.h"

using std::string;
using std::ostream;
using std::istream;

    /**
     * \class Result
     * \brief Represents the result of a student for a specific unit, including the mark and date of the result.
     *
     * The Result class stores information related to a student's performance in a unit, including the
     * unit details, the mark received, and the date when the result was recorded.
     *
     * \author Joshua Khoo
     * \date   30/09/2024
     * \version 1.0 started
     *
     * \author Joshua Khoo
     * \date   02/10/2024
     * \version 2.0 updated, changed mark to float.
     */
class Result
{
public:
    /**
     * \brief Default constructor for the Result class.
     *
     * Initializes the Result object with default values.
     * The unit is constructed with the default Unit constructor, the mark is set to 0.0,
     * and the date is initialized with the default Date constructor.
     */
    Result();

    /**
     * \brief Parameterized constructor to initialize the result.
     *
     * Initializes the Result object with a specific unit, mark, and date.
     *
     * \param unit The Unit object associated with the result.
     * \param mark The mark received for the unit as a float.
     * \param date The Date object representing when the result was recorded.
     */
    Result(const Unit &unit, float mark, const Date &date);

    /**
     * \brief Retrieves the mark associated with the result.
     *
     * \return The mark as a float.
     */
    float GetMark() const;

    /**
     * \brief Retrieves the Unit associated with the result.
     *
     * This method populates the provided Unit object with the unit data associated with this result.
     *
     * \param unit Reference to a Unit object to populate.
     */
    void GetUnit(Unit &unit) const;

    /**
     * \brief Retrieves the Date associated with the result.
     *
     * This method populates the provided Date object with the date when the result was recorded.
     *
     * \param date Reference to a Date object to populate.
     */
    void GetDate(Date &date) const;

    /**
     * \brief Sets the Unit associated with the result.
     *
     * This method allows updating the unit information associated with the result.
     *
     * \param unit The Unit object to set.
     */
    void SetUnit(const Unit& unit);

    /**
     * \brief Sets the mark associated with the result.
     *
     * This method allows updating the mark for the unit in the result.
     *
     * \param mark The new mark as a float to set.
     */
    void SetMark(float mark);

    /**
     * \brief Sets the Date associated with the result.
     *
     * This method allows updating the date when the result was recorded.
     *
     * \param date The Date object to set.
     */
    void SetDate(const Date& date);

private:
    Unit    m_unit;  ///< The unit associated with the result.
    float   m_mark;  ///< The mark received for the unit, stored as a float.
    Date    m_date;  ///< The date when the result was recorded.
};

    /**
     * \brief Overloaded insertion operator for printing Result objects.
     *
     * Outputs the details of the result, including the unit, mark, and date, to the output stream.
     *
     * \param os The output stream object.
     * \param result The Result object to print.
     * \return The modified output stream object.
     */
ostream& operator<<(ostream& os, const Result& result);

    /**
     * \brief Overloaded extraction operator for reading Result objects.
     *
     * Reads the details of the result, including the unit, mark, and date, from the input stream.
     *
     * \param input The input stream object.
     * \param result The Result object to populate.
     * \return The modified input stream object.
     */
istream& operator>>(istream& input, Result& result);

#endif // RESULT_H_INCLUDED
