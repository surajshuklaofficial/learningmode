/*
program to create read a text file and remove all the lines 
that contain the character 'a' in a file and write them to 
another file
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream myfile("prog1.txt");
    ofstream myfile2("prog5_2.txt");
    ofstream myfile3("prog5_3.txt");
    string mytext;
    
    while (getline(myfile,mytext)){
        bool aexist=false;
        for (int i=0;i<mytext.length();++i){
            if (mytext[i]=='a'){
                myfile2<<mytext<<endl;
                aexist=true;
                break;                
            }            
        }
        if (aexist==false){
            myfile3<<mytext<<endl;
        } 
        
    }
    myfile.close();
    myfile2.close();
    myfile3.close();
}