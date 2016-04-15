#include <stdio.h>
#include <iostream>
#include <string>
#define FindError 4294967295

using namespace std;

int main() {
    string text;
    getline(cin,text);
    bool low = false;
    bool up = false;
    for (int i = 65;i<=90;i++) {
        if (text.find((char)i,0) != FindError) {
            up = true;
        }
    }
    for (int i = 97;i<=122;i++) {
        if (text.find((char)i,0) != FindError) {
            low = true;
        }
    }
    if (low && up) {
        cout << "Mix";
    } else if (up) {
        cout << "All Capital Letter";
    } else if (low) {
        cout << "All Small Letter";
    }
    return 0;
}

