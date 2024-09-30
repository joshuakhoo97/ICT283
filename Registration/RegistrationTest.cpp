#include <iostream>
#include "Registration.h"
#include "Result.h"
#include "Unit.h"

using namespace std;

int main() {
    // Test 1: Create a Registration object
    Registration registration;

    // Test 2: Create some Unit objects
    Unit unit1("Data_Structures", "ICT283", 3);
    Unit unit2("Computer_Graphics", "ICT289", 4);
    Unit unit3("Cyber_Security", "ICT287", 3);

    // Test 3: Create some Result objects with units and marks
    Result result1;
    result1.SetUnit(unit1);
    result1.SetMark(85);

    Result result2;
    result2.SetUnit(unit2);
    result2.SetMark(90);

    Result result3;
    result3.SetUnit(unit3);
    result3.SetMark(95);

    // Test 4: Add results to the Registration object
    registration.AddResult(result1);
    registration.AddResult(result2);
    registration.AddResult(result3);

    // Test 5: Check the number of results (count)
    cout << "Number of Results: " << registration.GetCount() << endl;

    // Test 6: Check the total credits
    cout << "Total Credits: " << registration.GetCredits() << endl;

    // Test 7: Check individual results using GetResult()
    cout << "Results:\n";
    for (unsigned i = 0; i < registration.GetCount(); i++) {
        const Result& res = registration.GetResult(i);
        cout << res << endl;  // Assuming operator<< is overloaded for Result
    }

    return 0;
}
