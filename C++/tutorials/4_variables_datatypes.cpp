#include <iostream>
#include <string> // to use strings
using namespace std;

int main() {
    int num1 = -5;
    double num2,num3; // declaring more than one variable of same type
    num2,num3 = 5.6; // one value to multiple variables
    char letter = 'S';
    const int num4=45e3; // unchangeable ; read only ; scientific number
    string word = "Hello World"; // able to use string without using header file of line-2 of the code
    bool value1 = true, value2 = false;
    cout<<num1<<"\n"<<num2<<"\n"<<letter<<"\n"<<word<<"\n"<<value1<<"\n"<<num4;
}

/*
All C++ variables must be identified with unique names.
These unique names are called identifiers.
*/

/*
The general rules for naming variables are:

    Names can contain letters, digits and underscores
    Names must begin with a letter or an underscore (_)
    Names are case sensitive (myVar and myvar are different variables)
    Names cannot contain whitespaces or special characters like !, #, %, etc.
    Reserved words (like C++ keywords, such as int) cannot be used as names
*/

/*
Basic Data Types
The data type specifies the size and type of information the variable will store:

Data Type	Size	          Description
boolean	    1 byte	          Stores true or false values
char	    1 byte	          Stores a single character/letter/number, or ASCII values
string                        Stores a sequence of characters ; not built in type
int	        2 or 4 bytes	  Stores whole numbers, without decimals
float	    4 bytes	          Stores fractional numbers, containing one or more decimals. Sufficient for storing 7 decimal digits;
double	    8 bytes	          Stores fractional numbers, containing one or more decimals. Sufficient for storing 15 decimal digits
*/

/*
float vs. double

The precision of a floating point value indicates 
how many digits the value can have after the decimal point. 
The precision of float is only six or seven decimal digits, 
while double variables have a precision of about 15 digits. 
Therefore it is safer to use double for most calculations.
*/