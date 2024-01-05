#include <iostream>
using namespace std;

bool checkPalindrome(string str, int left, int right) {
    if (left >= right) return true; // base case

    if (str[left] != str[right]) return false; // base case
    else return checkPalindrome(str, left + 1, right - 1); 
}

int main() {

    string str = "suraj";
    cout << checkPalindrome(str, 0, str.length() - 1);
    return 0;
}