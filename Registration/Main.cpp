#include "Registration.h"  // Registration class declaration/interface

// The library header files
#include <iostream>
#include <fstream>


using namespace std;  // check textbook for detials of the namespace concept

// Main Program Functions
void PrintFileContent(ifstream &infile);

int main()
{

    ifstream infile( "rinput.txt" ); //infile is an object on runtime stack
    if( !infile ) return -1;

    // Debug Line --> Only use this commenting out everything from line 22 onwards to line before 'return 0;'
//    PrintFileContent(infile);
//    cout << " " << endl;

    Registration r;
    infile >> r;    // operator function
    // call the input stream operator from Registration

    ofstream ofile( "routput.txt" );

    // Use a debugger and track down the calls made "behind the scene"
    ofile << r       // also a subroutine call. Can you guess what it means?
          << "Number of courses = " << r.GetCount() << '\n'
          << "Total credits     = " << r.GetCredits() << '\n';


    return 0;
}

// Main Program Functions

void PrintFileContent(ifstream &infile)
{
    cout << "File Content: " << endl;
    string line;
    while(getline(infile, line))
    {
        cout << line << endl;
    }
}
