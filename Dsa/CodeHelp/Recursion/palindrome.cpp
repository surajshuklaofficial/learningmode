#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

bool checkPalindrome(string str, int left, int right)
{
    if (left >= right)
        return true; // base case

    if (str[left] != str[right])
        return false; // base case
    else
        return checkPalindrome(str, left + 1, right - 1);
}

bool checkPalindrome(long long N)
{
    string N_str = bitset<64>(N).to_string();
    size_t firstOne = N_str.find('1');

    // Remove leading zeros
    N_str = N_str.substr(firstOne);
    int left = 0, right = N_str.length() - 1;

    while (left < right) {
        if (N_str[left] != N_str[right]) return false;
        left++;
        right--;
    }

    return true;
}
int main()
{

    string str = "suraj";
    // cout << checkPalindrome(str, 0, str.length() - 1);
    cout << checkPalindrome(7);
    return 0;
}