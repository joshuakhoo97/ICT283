#include "Date.h"
#include <iostream>


using namespace std;

// Display date
void displayDate(const Date& date);

int main()
{

    cout << "-- Test 1: Default Constructor" << endl;
    Date date;
    displayDate(date);

    cout << '\n' << endl;

    cout << "-- Test 2: Parameterized Constructor" << endl;
    Date date2(1,1,1997);
    displayDate(date2);

    cout << '\n' << endl;

    cout << "-- Test 3: Set Functions" << endl;
    date2.SetDay(30);
    date2.SetMonth(12);
    date2.SetYear(2024);
    displayDate(date2);

    cout << '\n' << endl;

    cout << "-- Test 4: Invalid day" << endl;
    date2.SetDay(32);

    if(date2.GetValidity())
    {
        displayDate(date2);
    }
    else
    {
        cout << "Invalid date" << endl;
    }

    return 0;
}

// Output not handled by Data Structure
void displayDate(const Date& date)
{
    cout << date.GetDay() << "/" << date.ConvertMonth(date.GetMonth()) << "/" << date.GetYear() << endl;
}
