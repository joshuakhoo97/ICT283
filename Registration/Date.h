#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>

using std::ostream;
using std::istream;
using std::string;

    /**
     * \class Date
     * \brief Represents a date with day, month, and year.
     *
     * The Date class encapsulates the information related to a specific date, including
     * the day, month, and year. It provides utility functions for setting and retrieving
     * these values, as well as converting a numeric month value to its corresponding name.
     *
     * \author Joshua Khoo
     * \date   30/09/2024
     * \version 1.0 started
     *
     * \author Joshua Khoo
     * \date   01/10/2024
     * \version 2.0 updated
     *
     * \author Joshua Khoo
     * \date   02/10/2024
     * \version 3.0 final
     */
class Date
{
public:
    /**
     * \brief Default constructor for the Date class.
     *
     * Initializes the Date object with default values.
     * The default day is 0, the default month is 0, and the default year is 9999.
     */
    Date();

    /**
     * \brief Parameterized constructor to initialize the date.
     *
     * This constructor initializes a Date object with the given day, month, and year values.
     *
     * \param newDay The day of the date.
     * \param newMonth The month of the date.
     * \param newYear The year of the date.
     */
    Date(unsigned newDay, unsigned newMonth, unsigned newYear);

    /**
     * \brief Retrieves the day of the date.
     *
     * \return The day as an unsigned integer.
     */
    unsigned GetDay() const;

    /**
     * \brief Retrieves the month of the date.
     *
     * \return The month as an unsigned integer.
     */
    unsigned GetMonth() const;

    /**
     * \brief Retrieves the year of the date.
     *
     * \return The year as an unsigned integer.
     */
    unsigned GetYear() const;

    /**
     * \brief Sets the day of the date.
     *
     * \param newDay The new day to set.
     */
    void SetDay(unsigned newDay);

    /**
     * \brief Sets the month of the date.
     *
     * \param newMonth The new month to set.
     */
    void SetMonth(unsigned newMonth);

    /**
     * \brief Sets the year of the date.
     *
     * \param newYear The new year to set.
     */
    void SetYear(unsigned newYear);

    /**
     * \brief Converts a numeric month value to its string representation.
     *
     * Converts a month value (1-12) to its corresponding string representation
     * (e.g., 1 = January, 2 = February).
     *
     * \param month The numeric month value to convert.
     * \return The corresponding month name as a string.
     */
    string ConvertMonth(const unsigned month) const;

private:
    unsigned m_day;   ///< The day of the date.
    unsigned m_month; ///< The month of the date.
    unsigned m_year;  ///< The year of the date.
};

    /**
     * \brief Overloaded extraction operator for reading Date objects.
     *
     * Reads the day, month, and year from the input stream into the Date object.
     *
     * \param is The input stream object.
     * \param date The Date object to populate.
     * \return The modified input stream object.
     */
std::istream& operator>>(std::istream& is, Date& date);

    /**
     * \brief Overloaded insertion operator for printing Date objects.
     *
     * Outputs the day, month (as a string), and year of the Date object to the output stream.
     *
     * \param os The output stream object.
     * \param date The Date object to print.
     * \return The modified output stream object.
     */
std::ostream& operator<<(std::ostream& os, const Date& date);

#endif // DATE_H_INCLUDED
