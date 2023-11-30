#include <iostream>
#include "../index.h"
using namespace std;

// problem number - 186 of leetcode
void reverse_word_in_char_arry(char* arr) {

    int char_index_pointer = 0;
    int start = 0;
    do {
        if (arr[char_index_pointer] != ' ' && arr[char_index_pointer] != '\0') {
            char_index_pointer++;
        } else {
            int end = char_index_pointer - 1;
            while (start < end) {
                swap(arr[start++], arr[end--]);
            }
            start = ++char_index_pointer;
        }
    } while (arr[char_index_pointer - 1] != '\0');
}

int main() {
    
    char s[20] = { 'T', 'H', 'E', ' ', 'S', 'k', 'Y', ' ', 'I', 'S', ' ', 'B', 'L', 'U', 'E', '\0'};
    printArray(s);

    reverse_word_in_char_arry(s);
    printArray(s);
    return 0;
}