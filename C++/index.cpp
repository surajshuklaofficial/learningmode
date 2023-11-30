#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void handlingError() {
    try {
        int a = 0;
        cout << "Enter a number: " << endl;
        cin >> a;

        // Example 1: Division by zero error
        if (a == 0) {
            throw std::runtime_error("Division by zero is not allowed");
        }
        cout << "Result of division: " << 5 / a << endl;

        // Example 2: Accessing an array index out of bounds
        int array[3] = {1, 2, 3};
        cout << "Accessing an array element out of bounds: " << array[5] << endl;

        // Example 3: Null pointer dereference
        int* ptr = nullptr;
        cout << "Dereferencing a null pointer: " << *ptr << endl;

        // Example 4: Logic error (incorrect calculation)
        int x = 10, y = 0;
        cout << "Incorrect calculation leading to a logical error: " << x / y << endl;

        // Example 5: Throwing a custom exception
        throw std::logic_error("This is a custom logic error");

    } catch (const std::runtime_error& e) {
        cout << "Runtime Error: " << e.what() << endl;
    } catch (const std::out_of_range& e) {
        cout << "Out of Range Error: " << e.what() << endl;
    } catch (const std::logic_error& e) {
        cout << "Logic Error: " << e.what() << endl;
    } catch (const std::exception& e) {
        cout << "Generic Exception: " << e.what() << endl;
    } catch (...) {
        cout << "Unknown Exception" << endl;
    }
}

int main() {
    handlingError();
    return 0;
}
