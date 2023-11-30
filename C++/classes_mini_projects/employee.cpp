#include <iostream>
using namespace std;

class Employee {
    // private: // by default everything is private in cpp classes; so need to write it here
    int salary;
    int age;
    float increment;

    public : 
        string name;

        void setData(string employee_name, int employee_salary, int employee_age, float employee_increment_per);
        void getData(void); // no need to write to void
};

void Employee :: setData(string employee_name, int employee_salary, int employee_age, float employee_increment_per = 1.01){
    name = employee_name;
    salary = employee_salary;
    age = employee_age;
    increment = employee_increment_per;
}

void Employee :: getData(void){
    cout << "name of Employee: " << name << endl;
    cout << "salary of Employee: " << salary << endl;
    cout << "age of Employee: " << age << endl;
    cout << "increment of Employee: " << increment << endl;
}

int main() {
    
    Employee E1;
    
    E1.setData("Manish", 120000, 24);
    E1.getData();
    cout << "accessing class properties directly: " << E1.name << endl;
    // cout << "accessing class properties directly: " << E1.salary << endl; // this is not valid as salary is private member
    return 0;
}