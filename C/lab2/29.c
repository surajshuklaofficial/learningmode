#include <stdio.h>

#define PI 3.14159

float calculateCircleArea(float radius) {
    return PI * radius * radius;
}

float calculateCirclePerimeter(float radius) {
    return 2 * PI * radius;
}

float calculateRectangleArea(float length, float width) {
    return length * width;
}

float calculateRectanglePerimeter(float length, float width) {
    return 2 * (length + width);
}

float calculateSquareArea(float side) {
    return side * side;
}

float calculateSquarePerimeter(float side) {
    return 4 * side;
}

float calculateTriangleArea(float base, float height) {
    return (base * height) / 2;
}

float calculateTrianglePerimeter(float side1, float side2, float side3) {
    return side1 + side2 + side3;
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int choice;
    float radius, length, width, side, base, height;
    float area, perimeter;

    printf("Geometry Calculator\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Square\n");
    printf("4. Triangle\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            area = calculateCircleArea(radius);
            perimeter = calculateCirclePerimeter(radius);
            printf("Circle Area: %.2f\n", area);
            printf("Circle Perimeter: %.2f\n", perimeter);
            break;
        case 2:
            printf("Enter the length and width of the rectangle: ");
            scanf("%f %f", &length, &width);
            area = calculateRectangleArea(length, width);
            perimeter = calculateRectanglePerimeter(length, width);
            printf("Rectangle Area: %.2f\n", area);
            printf("Rectangle Perimeter: %.2f\n", perimeter);
            break;
        case 3:
            printf("Enter the side length of the square: ");
            scanf("%f", &side);
            area = calculateSquareArea(side);
            perimeter = calculateSquarePerimeter(side);
            printf("Square Area: %.2f\n", area);
            printf("Square Perimeter: %.2f\n", perimeter);
            break;
        case 4:
            printf("Enter the base and height of the triangle: ");
            scanf("%f %f", &base, &height);
            printf("Enter the three sides of the triangle: ");
            float side1, side2, side3;
            scanf("%f %f %f", &side1, &side2, &side3);
            area = calculateTriangleArea(base, height);
            perimeter = calculateTrianglePerimeter(side1, side2, side3);
            printf("Triangle Area: %.2f\n", area);
            printf("Triangle Perimeter: %.2f\n", perimeter);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
