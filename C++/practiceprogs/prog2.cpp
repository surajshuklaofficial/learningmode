/* 
program to read a text file and display 
the number of vowels, consonants, uppercase, 
lowercase characters in the file
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream myfile("prog1.txt");
    string mytext;
    int vowels=0,consonants=0,uppercase=0,lowercase=0;
    while (getline(myfile,mytext)){
        
        for (int i=0;i<mytext.length();i++){
            // checking vowel
            if (mytext[i]=='a' || mytext[i]=='e' || mytext[i]=='i' || mytext[i]=='o' || mytext[i]=='u' || mytext[i]=='A' || mytext[i]=='E' || mytext[i]=='I' || mytext[i]=='U' || mytext[i]=='O'){
                vowels++;
            }
            if (mytext[i]=='A' || mytext[i]=='B' || mytext[i]=='C' || mytext[i]=='D' || mytext[i]=='E' || mytext[i]=='F' || mytext[i]=='G' || mytext[i]=='H' || mytext[i]=='I' || mytext[i]=='J' || mytext[i]=='K' || mytext[i]=='L' || mytext[i]=='M' || mytext[i]=='N' || mytext[i]=='O' || mytext[i]=='P' || mytext[i]=='Q' || mytext[i]=='R' || mytext[i]=='S' || mytext[i]=='T' || mytext[i]=='U' || mytext[i]=='W' || mytext[i]=='X' || mytext[i]=='Y' || mytext[i]=='Z'){
                uppercase++;
            }
            if (mytext[i]=='a' || mytext[i]=='b' || mytext[i]=='c' || mytext[i]=='d' || mytext[i]=='e' || mytext[i]=='f' || mytext[i]=='g' || mytext[i]=='h' || mytext[i]=='i' || mytext[i]=='j' || mytext[i]=='k' || mytext[i]=='l' || mytext[i]=='m' || mytext[i]=='n' || mytext[i]=='o' || mytext[i]=='p' || mytext[i]=='q' || mytext[i]=='r' || mytext[i]=='s' || mytext[i]=='t' || mytext[i]=='u' || mytext[i]=='w' || mytext[i]=='x' || mytext[i]=='y' || mytext[i]=='z'){
                lowercase++;
            }  
        }
    }
    consonants=uppercase+lowercase-vowels;
    cout<<vowels<<endl;
    cout<<consonants<<endl;
    cout<<uppercase<<endl;
    cout<<lowercase<<endl;
    myfile.close();
}
