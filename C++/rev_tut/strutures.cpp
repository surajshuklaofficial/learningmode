#include <iostream>
using namespace std;

struct Employee {
    string name;
    char division;
    int EId;
    float salary;
    bool leaveStatus; // true means on leave
} E2;

// using typedef
typedef struct Employee2 {
    string name;
    char division;
    int EId;
    float salary;
    bool leaveStatus; // true means on leave
} EP;

int main() {
    // struct Employee E1; // this is also a way to intialise structures
    Employee E1;
    E1.name = "suraj shukla";
    E1.division = 'A';
    E1.EId = 1003;
    E1.salary = 120000;
    E1.leaveStatus = true;

    E2.name = "manish";

    EP E3;
    E3.name = "gagan";

    cout << "name of Employee E1: " << E1.name << endl;
    cout << "division of Employee E1: " << E1.division << endl;
    cout << "EId of Employee E1: " << E1.EId << endl;
    cout << "salary of Employee E1: " << E1.salary << endl;
    cout << "leave status of Employee E1: " << E1.leaveStatus << endl;
    // cout << "leave status of Employee E1: " << E1 << endl; // cause an error

    cout << "name of Employee E2: " << E2.name << endl;

    cout << "name of Employee E3: " << E3.name << endl;
    return 0;
}