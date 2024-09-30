#include <iostream>
#include "Result.h"
#include "Unit.h"

int main ()
{

    Result myResult;
    cout << "-- Test 1: Constructor of Result" << endl;
    cout << myResult << endl << endl;


    Result myResult2;
    cout << "-- Test 2: Set Unit " << endl;
    Unit myUnit("Project Management", "ICT285", 3);
    myResult2.SetUnit(myUnit);
    myResult2.SetMark(90);
    cout << myResult2 << endl;

    return 0;
}
