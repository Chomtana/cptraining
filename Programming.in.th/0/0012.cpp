#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main() {
    string in;
    string line1 = ".";
    string line2 = ".";
    string line3 = "#";
    string line4 = ".";
    string line5 = ".";
    getline(cin,in);
    for (int i = 0;i<in.length();i++) {
        if (i%3 != 2) {
            line1 += ".#..";
            line2 += "#.#.";
            line3 += "."+in.substr(i,1)+".";
            line4 += "#.#.";
            line5 += ".#..";
            if ((i+1)%3 != 2 || i == in.length()-1) {
                line3 += "#";
            } else {
                line3 += "*";
            }    
        } else if (i%3 == 2) {
            line1 += ".*..";
            line2 += "*.*.";
            line3 += "."+in.substr(i,1)+".*";
            line4 += "*.*.";
            line5 += ".*..";
        }    
        
    }
    cout << line1+"\n"+line2+"\n"+line3+"\n"+line4+"\n"+line5;  
    //system("pause");
    return 0;
}

