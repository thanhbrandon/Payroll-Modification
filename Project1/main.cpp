#include <iostream>
#include <iomanip>
#include <vector>
#include <cctype>
#include "PAYLIST.h"
using namespace std;



// Function Prototypes
vector<double> getEmployeeInfo(vector<int>);
bool reRun(); // function prototype for reRun function

int main()
{

    bool programOn = true;
    do {
        int emID;
        PayList empList;
        vector<int> emIDVec;

        cout << "Enter an employee ID number(0-999999): ";
        cin >> emID; // Gets employee ID
        emIDVec.push_back(emID);

        // Asks user if they want to add another employee
        char anotherOne = 'Y';
        while (anotherOne != 'N') {
            cout << "Do you want to enter another one? (Y/N)";
            cin >> anotherOne;
            if (toupper(anotherOne) == 'N') {
                break;
            }
            else if (toupper(anotherOne) == 'Y') {
                cout << "Enter an employee ID number(0-999999): ";
                cin >> emID;
                emIDVec.push_back(emID);
            }
            else {
                cout << "Not a valid response!\n";
            }
        }
    
        vector<double> payList = getEmployeeInfo(emIDVec);

        for (int i = 0; i < emIDVec.size(); i++) {
            int empIDtemp = emIDVec[i];
            double empPaytemp = payList[i];
            empList.appendNode(empIDtemp, empPaytemp);
        }

        empList.displayList();
        programOn = reRun(); // Asks user if they want to run the program again

        empList.~PayList();
        emIDVec.~vector();
        payList.~vector();
    } while (programOn == true);

    return 0;
}

// ********************************************************
// The getEmployeeInfo function receives four parallel    *
// arrays as arguments. The 1st array contains employee   *
// IDs to be displayed in prompts. It asks for input and  *
// stores hours worked and pay rate information in the    *
// 2nd and 3rd arrays. This information is used to        *
// calculate gross pay, which it stores in the 4th array. *
// ********************************************************
vector<double> getEmployeeInfo(vector<int> emIDs)
{
    vector<double> payVec;
    cout << "Enter the requested information "
        << "for each employee.\n";
    for (const int& i : emIDs) {
        // Get the information for each employee.

        cout << "\nEmployee #" << i << endl;

        // Get this employee's hours worked.
        cout << "\tHours worked: ";
        int hrs;
        cin >> hrs;

        // Validate hours worked.
        while (hrs < 0)
        {
            cout << "Hours worked must be 0 or more. "
                << "Please re-enter: ";
            cin >> hrs;
        }

        // Get this employee's pay rate.
        cout << "\tPay rate: $";
        double rate;
        cin >> rate;

        // Validate the pay rate.
        while (rate < 6.00)
        {
            cout << "Pay rate must be 6.00 or more. "
                << "Please re-enter: $";
            cin >> rate;
        }

        // Calculate this employee's gross pay.
        double pay = hrs * rate;

        payVec.push_back(pay);
    }
    return payVec;
}

bool reRun()
{
    bool result; 	// true to end program, false to run again
    char runAgain;	// prompt for re-running program

    // prompt to run program again
    cout << "\n\nWould you like to run program again (Y/N) ? ";
    cin >> runAgain;

    // validate input for Y, y, N, or n
    while (toupper(runAgain) != 'Y' && toupper(runAgain) != 'N')
    {
        cout << "\n **  Invalid entry  **  Please enter 'Y' or 'N'\n\n";
        cout << "Would you like to run program again (Y/N) ? ";
        cin.ignore();  // clear keybard cache
        cin >> runAgain;
    }

    if (toupper(runAgain) == 'Y')
    {
        result = true;
        system("CLS"); // Clears console
    }
    else
        result = false;

    return result;
}