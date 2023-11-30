#include <stdio.h>

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   float length, breadth, radius;
   float rectangleArea, rectanglePerimeter, circleArea, circleCircumference;

   printf("Enter the length of the rectangle: ");
   scanf("%f", &length);

   printf("Enter the breadth of the rectangle: ");
   scanf("%f", &breadth);

   printf("Enter the radius of the circle: ");
   scanf("%f", &radius);

   rectangleArea = length * breadth;
   rectanglePerimeter = 2 * (length + breadth);
   circleArea = 3.1415 * radius * radius;
   circleCircumference = 2 * 3.1415 * radius;

   printf("Area of rectangle: %.2f\n", rectangleArea);
   printf("Perimeter of rectangle: %.2f\n", rectanglePerimeter);
   printf("Area of circle: %.2f\n", circleArea);
   printf("Circumference of circle: %.2f\n", circleCircumference);

   return 0;
}
