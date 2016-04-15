#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string in1 = "";
    string in2 = "";
    string result = "";
    char ope[2];
    cin >> in1;
    scanf("%s",&ope);
    cin >> in2;
    if (ope[0] == '+') {
        if (in1.length() > in2.length()) {
            result = in1.substr(0,in1.length()-in2.length())+in2;
        } else if (in1.length() == in2.length()) {
            result = "2"+in1.substr(1,in1.length());
        } else {
            result = in2.substr(0,in2.length()-in1.length())+in1;
        }
    } else {
        if (in1.length() > in2.length()) {
            result = in1+in2.substr(1,in2.length());
        } else {
            result = in2+in1.substr(1,in1.length());
        }
    }
    cout << result;
    return 0;
}

