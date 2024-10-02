#include "Date.h"
#include <iostream>


using namespace std;

int main()
{

    cout << "-- Test 1: Default Constructor" << endl;
    Date date;
    cout << date << endl;

    cout << '\n' << endl;

    cout << "-- Test 2: Parameterized Constructor" << endl;
    Date date2(1,1,1997);
    cout << date2 << endl;

    cout << '\n' << endl;

    cout << "-- Test 3: Set Functions" << endl;
    date2.SetDay(30);
    date2.SetMonth(12);
    date2.SetYear(2024);
    cout << date2 << endl;


    return 0;
}
