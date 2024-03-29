#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

unsigned long long int powerCalc(int x, int p)
{
    if (p == 0)
        return 1; // base case
    if (p == 1)
        return x;

    unsigned long long int temp = powerCalc(x, p / 2) * powerCalc(x, p / 2); // processing

    if (p % 2 == 0)
        return temp; // for even
    else
        return x * temp; // for odd
}

unsigned long long int power(int x, int p)
{
    unsigned long long int product = 1;
    while (p > 0)
    {
        product = product * x;
        p--;
    }

    return product;
}

int main()
{

    int x, p;
    cout << "Enter base and exponent to be calculated: " << endl;
    cin >> x >> p;

    auto start = high_resolution_clock::now();
    unsigned long long int result1 = powerCalc(x, p);
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop - start);

    cout << "Result using powerCalc: " << result1 << endl;
    cout << "Time taken by powerCalc: " << duration1.count() << " nanoseconds" << endl;

    start = high_resolution_clock::now();
    unsigned long long int result2 = power(x, p);
    stop = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop - start);

    cout << "Result using power: " << result2 << endl;
    cout << "Time taken by power: " << duration2.count() << " nanoseconds" << endl;
    return 0;
}