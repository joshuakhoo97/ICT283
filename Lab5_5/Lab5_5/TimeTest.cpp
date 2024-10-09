#include <iostream>
#include "Time.h"


using namespace std;

void displayTime(const Time& time);

int main()
{
    // Test 1: Default Constructor
    Time myTime;
    displayTime(myTime);

    // Test 2: Parameterized constructor
    unsigned hour = 14;
    unsigned mins = 59;
    Time myTime2(hour, mins);
    displayTime(myTime2);

    // Test 3: Set Methods
    hour = 13;
    mins = 48;
    myTime.SetHour(hour);
    myTime.SetMins(mins);
    displayTime(myTime);

    // Test 4: Giving invalid time
    Time myTime3(25,61);

    if(myTime3.GetValidity())
    {
        displayTime(myTime3);
    }
    else
    {
        cout << "Invalid Time" << endl;
    }

    return 0;
}

void displayTime(const Time& time)
{
    cout << time.GetHour() << ":" << time.GetMins() << endl;
}
