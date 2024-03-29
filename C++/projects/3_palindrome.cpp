// a programm to check whether a given string is palindrome or not

#include <iostream>
using namespace std;

void check_palindrome(string word) {
    string rev_word;
    for ( int i = 1; i < word.length() + 1; i++) {
        rev_word += word[word.length() - i];
    }

    if ( word == rev_word) {
        cout << "It is palindrome." << endl;
    } else {
        cout << "It is not a Palindrome." << endl;
    }
}

int main() {
    
    string word;
    cout << "Enter a word: ";
    cin >> word;

    check_palindrome(word);
    return 0;
}