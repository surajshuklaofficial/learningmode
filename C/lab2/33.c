#include <stdio.h>

struct Person {
    char name[50];
    int age;
    float salary;
};

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    struct Person person;

    FILE *file = fopen("emp.txt", "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    printf("Enter name: ");
    fgets(person.name, sizeof(person.name), stdin);

    printf("Enter age: ");
    scanf("%d", &person.age);

    printf("Enter salary: ");
    scanf("%f", &person.salary);

    fprintf(file, "Name: %sAge: %d\nSalary: %.2f", person.name, person.age, person.salary);

    fclose(file);

    printf("Information written to file successfully.\n");

    return 0;
}
