#include <iostream>
#include "Unit.h"

using namespace std;

int main()
{

    Unit myUnit;

    cout << "-- Test 1: Default Constructor --" << endl;
    cout << myUnit << endl;

    Unit secondUnit("Data Structures", "ICT283", 3);
    cout << "-- Test 2: Parameterised Constructor --" << endl;
    cout << secondUnit << endl;

    cout << "-- Test 3: Set Name to pass Exam --" << endl;
    myUnit.SetUnitName("Pass Exam");
    cout << myUnit << endl;


    return 0;
}
