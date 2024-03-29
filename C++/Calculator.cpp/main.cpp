#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    float real_part;
    float img_part;

    public:
        Complex(float, float );

        void displayNum(void);

        double mod();
        double arg();
        void congugate();

        friend Complex add(Complex, Complex);
        friend Complex sub(Complex, Complex);
        friend Complex mul(Complex, Complex);
        friend Complex div(Complex , Complex);

        // not defined
        double polarForm();
        void exp(Complex, int pow);
        void root(Complex, int root);
        void log(Complex, int base);

};

Complex::Complex( float re = 0, float img = 0){
    real_part = re;
    img_part = img;
}

void Complex::displayNum(void) {

    if (img_part>=0) {
        cout  << real_part << " + " << img_part << "i" << endl;
    } else {
        cout  << real_part << " - " << -img_part << "i" << endl;
    }
}

Complex add(Complex C1, Complex C2) {
    Complex C3((C1.real_part + C2.real_part), (C1.img_part + C2.img_part));
    return C3;
}

Complex sub(Complex C1, Complex C2) {
    Complex C3((C1.real_part - C2.real_part), (C1.img_part - C2.img_part));
    return C3; 
}

Complex mul(Complex C1, Complex C2) {
    float real_part = ((C1.real_part * C2.real_part) - (C1.img_part * C2.img_part));
    float img_part = ((C1.real_part * C2.img_part) + (C1.img_part * C2.real_part));
    
    Complex C3(real_part, img_part);
    return C3;
}

double Complex::mod() {
    return pow((pow(real_part, 2) + pow(img_part, 2)), 0.5);
}

/* 
    Formula used for division :.
        let a+ib & c+id are complex numbers

        div_result_numerator = ( a + ib ) * ( c - id ) = ( ac + bd ) + i( -ad + bc );
        div_result_denominator = ( c + id ) * ( c - id ) = c^2 + d^2;
*/
Complex div(Complex C1, Complex C2) {
    float real_part = ((C1.real_part * C2.real_part) + (C1.img_part * C2.img_part))/pow(C2.mod(), 2);
    float img_part = ( -1 * (C1.real_part * C2.img_part) + (C1.img_part * C2.real_part))/pow(C2.mod(), 2);

    Complex C3(real_part, img_part);
    return C3;
}


// it will return arg in radians
double Complex::arg() {
    return atan(img_part/real_part);  
}

// it will change the original Complex number into it's conjugate
void Complex::congugate() {
    img_part = -img_part;
}

double Complex::polarForm() {

}

void Complex::exp(Complex, int pow) {

}

void Complex::root(Complex, int root) {

}

void Complex::log(Complex, int base) {

}

int main() {
    
    Complex C1(2, 4);
    Complex C2 = Complex(34, 14);
    Complex C3; // c3 is declared like this iff default parameters are present in constructor
    C1.displayNum();
    C2.displayNum();
    C3.displayNum();

    Complex C4 = add(C1, C2);
    cout << "addition result of C1 and C2 is ";
    C4.displayNum();

    C4 = sub(C1, C2);
    cout << "subtraction result of C1 and C2 is ";
    C4.displayNum();

    C4 = mul(C1, C2);
    cout << "multiplication result of C1 and C2 is ";
    C4.displayNum();

    cout << "modulus of C1: " << C1.mod() << endl;
    cout << "argument of C1: " << C1.arg() << endl;

    C1.congugate();
    cout << "Conjugate of C1: ";
    C1.displayNum();

    C4 = div(C1, C2);
    cout << "division of result of C1 & C2: ";
    C4.displayNum(); 
    return 0;
}