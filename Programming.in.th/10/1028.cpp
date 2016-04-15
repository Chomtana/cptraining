#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

bool is_number(const std::string& s) {
    if (s.substr(0,1) == "-") {
        return true;
    }
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string convertInt(int number) {
   stringstream ss;
   ss << number;
   return ss.str();
}

int main() {
    int data[27] = {0};
    string out = "";
    while (true) {
        string input;
        getline(cin,input);
        if (input.substr(0,1) == "=") {
            /*if (data[input.substr(2,1).c_str()[0]-65] > 32767) {
                data[input.substr(2,1).c_str()[0]-65] = 0;
            }*/
            if ( is_number(input.substr(4,input.length()-4)) ) {
                data[input.substr(2,1).c_str()[0]-65] = atoi(input.substr(4,input.length()-4).c_str());
            } else {
                data[input.substr(2,1).c_str()[0]-65] = data[input.substr(4,input.length()-4).c_str()[0]-65];
            }
        }
        else if (input.substr(0,1) == "+") {
            /*if (data[input.substr(2,1).c_str()[0]-65] > 32767) {
                data[input.substr(2,1).c_str()[0]-65] = 0;
            }*/
            if ( is_number(input.substr(4,input.length()-4)) ) {
                data[input.substr(2,1).c_str()[0]-65] += atoi(input.substr(4,input.length()-4).c_str());
            } else {
                data[input.substr(2,1).c_str()[0]-65] += data[input.substr(4,input.length()-4).c_str()[0]-65];
            }
        }
        else if (input.substr(0,1) == "-") {
            /*if (data[input.substr(2,1).c_str()[0]-65] > 32767) {
                data[input.substr(2,1).c_str()[0]-65] = 0;
            }*/
            if ( is_number(input.substr(4,input.length()-4)) ) {
                data[input.substr(2,1).c_str()[0]-65] -= atoi(input.substr(4,input.length()-4).c_str());
            } else {
                data[input.substr(2,1).c_str()[0]-65] -= data[input.substr(4,input.length()-4).c_str()[0]-65];
            }
        }
        else if (input.substr(0,1) == "*") {
            /*if (data[input.substr(2,1).c_str()[0]-65] > 32767) {
                data[input.substr(2,1).c_str()[0]-65] = 0;
            }*/
            if ( is_number(input.substr(4,input.length()-4)) ) {
                data[input.substr(2,1).c_str()[0]-65] *= atoi(input.substr(4,input.length()-4).c_str());
            } else {
                data[input.substr(2,1).c_str()[0]-65] *= data[input.substr(4,input.length()-4).c_str()[0]-65];
            }
        }
        else if (input.substr(0,1) == "/") {
            /*if (data[input.substr(2,1).c_str()[0]-65] > 32767) {
                data[input.substr(2,1).c_str()[0]-65] = 0;
            }*/
            if ( is_number(input.substr(4,input.length()-4)) ) {
                data[input.substr(2,1).c_str()[0]-65] /= atoi(input.substr(4,input.length()-4).c_str());
            } else {
                data[input.substr(2,1).c_str()[0]-65] /= data[input.substr(4,input.length()-4).c_str()[0]-65];
            }
        }
        else if (input.substr(0,1) == "#") {
            /*if (data[input.substr(2,1).c_str()[0]-65] > 32767) {
                data[input.substr(2,1).c_str()[0]-65] = 0;
            }*/
            out += convertInt(data[input.substr(2,1).c_str()[0]-65])+"\n";
        }
        else if (input == "!") {
            out += "!";
            break;
        }
    }
    cout << out;
    return 0;
}

