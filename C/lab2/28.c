#include <stdio.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    struct Employee employee;

    printf("Enter employee name: ");
    scanf("%s", employee.name);

    printf("Enter employee age: ");
    scanf("%d", &employee.age);

    printf("Enter employee salary: ");
    scanf("%f", &employee.salary);

    printf("\nEmployee Details\n");
    printf("Name: %s\n", employee.name);
    printf("Age: %d\n", employee.age);
    printf("Salary: %.2f\n", employee.salary);

    return 0;
}
