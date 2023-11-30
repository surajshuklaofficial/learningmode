#include <iostream>
using namespace std;

// first version
// string removeOccurrences(string s, string part) {
//         int part_matched = 0;
//         int size_of_part = part.length(), index = 0;
//         int size;
//         string temp;

//         while (true) {
//             size = s.length();
//             for (int i = 0; i < size; i++) {
//                 index = i;
//                 for (int j = i, z = 0; z < size_of_part; z++, j++) {
//                     if  (s[j] != part[z]) break;
//                     else part_matched++; 
//                 }
//                 if (part_matched == size_of_part) {
//                     break;
//                 } else {
//                     part_matched = 0;
//                 }
//             }

//             if (part_matched == size_of_part) {
//                 for (int i = 0; i < size; i++) {
//                     if (!( i >= index && i < (index + size_of_part))) {
//                         temp.push_back(s[i]);
//                     }
//                 }
//                 s = temp;
//                 temp = "";
//                 part_matched = 0;
//                 cout << s << endl;
//             } else break;
            
//         }
//         return s;
//     }

// second version
string removeOccurrences(string s, string part) {
    int part_matched = 0;
    int size_of_part = part.length();
    int size = s.length();
    for (int i = 0; i < size; i++) {
        for (int j = i, z = 0; z < size_of_part; z++, j++) {
            if  (s[j] != part[z]) break;
            else part_matched++; 
        }
        if (part_matched == size_of_part) {
            for (int j = 0; j < size_of_part; j++) {
                s[i + j] = '';
            }
            size = s.length();
        } else {
            part_matched = 0;
        }
    }
        
    return s;
}

int main() {
    s = ""
    return 0;
}