#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

    /**
     * \class Unit
     * \brief Represents a course unit, storing the unit name, ID, and credit information.
     *
     * The Unit class encapsulates the information related to a course unit, including the
     * course name, unit ID, and the number of credits associated with it.
     *
     * \author Joshua Khoo
     * \date   30/09/2024
     * \version 1.0 started
     *
     * \author Joshua Khoo
     * \date   30/09/2024
     * \version 2.0 updated
     *
     * \author Joshua Khoo
     * \date   2/10/2024
     * \version 3.0 final
     */
class Unit
{
public:
    /**
     * \brief Default constructor for the Unit class.
     *
     * Initializes the Unit object with default values.
     */
    Unit();

    /**
     * \brief Parameterized constructor to initialize attributes.
     *
     * This constructor allows setting all the attributes of the Unit object:
     * the course name, unit ID, and the number of credits.
     *
     * \param name The name of the course unit.
     * \param unitId The identifier of the course unit.
     * \param credits The number of credits the course unit is worth.
     */
    Unit(const string& name, const string& unitId, unsigned credits);

    /**
     * \brief Retrieves the name of the course unit.
     *
     * \return A string containing the name of the unit.
     */
    string GetUnitName() const;

    /**
     * \brief Retrieves the unit ID.
     *
     * \return A string containing the ID of the unit.
     */
    string GetUnitId() const;

    /**
     * \brief Retrieves the number of credits for the unit.
     *
     * \return The number of credits as an unsigned integer.
     */
    unsigned GetCredits() const;

    /**
     * \brief Sets the name of the course unit.
     *
     * \param newUnitName The new name of the unit.
     */
    void SetUnitName(const string &newUnitName);

    /**
     * \brief Sets the unit ID.
     *
     * \param newUnitId The new unit ID.
     */
    void SetUnitId(const string &newUnitId);

    /**
     * \brief Sets the number of credits for the unit.
     *
     * \param credits The number of credits as an unsigned integer.
     */
    void SetCredits(unsigned credits);

private:
    string m_name;    ///< The name of the course unit.
    string m_unitId;  ///< The unit ID.
    unsigned m_credits; ///< The number of credits associated with the unit.
};

    /**
     * \brief Overloaded insertion operator for printing Unit objects.
     *
     * Outputs the details of a Unit object to the output stream.
     *
     * \param os The output stream object.
     * \param unit The Unit object to be printed.
     * \return The modified output stream object.
     */
ostream& operator<<(ostream& os, const Unit& unit);

    /**
     * \brief Overloaded extraction operator for reading Unit objects.
     *
     * Reads the details of a Unit object from the input stream.
     *
     * \param input The input stream object.
     * \param unit The Unit object to be populated.
     * \return The modified input stream object.
     */
istream& operator>>(istream& input, Unit& unit);

#endif // UNIT_H
