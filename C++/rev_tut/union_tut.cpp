#include <iostream>
using namespace std;

union Employee {
    // string name; // string is not a trivial datatype therefore it is creating a problem
    char division;
    int EId;
    float salary;
    bool leaveStatus; // true means on leave
} E2;

// using typedef
typedef union Employee2 {
    // string name; 
    char division;
    int EId;
    float salary;
    bool leaveStatus; // true means on leave
} EP;

int main() {
    // union Employee E1; // this is also a way to intialise structures
    Employee E1;
    // E1.name = "suraj shukla";
    E1.division = 'A';
    E1.EId = 1003;
    E1.salary = 120000;
    E1.leaveStatus = true;

    E2.EId = 1004;

    EP E3;
    E3.EId = 1005;

    // cout << "name of Employee E1: " << E1.name << endl;
    cout << "division of Employee E1: " << E1.division << endl;
    cout << "EId of Employee E1: " << E1.EId << endl;
    cout << "salary of Employee E1: " << E1.salary << endl;
    cout << "leave status of Employee E1: " << E1.leaveStatus << endl;
    // cout << "leave status of Employee E1: " << E1 << endl; // cause an error

    cout << "EId of Employee E2: " << E2.EId << endl;

    cout << "EId of Employee E3: " << E3.EId << endl;
    return 0;
}