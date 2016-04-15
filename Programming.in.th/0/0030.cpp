#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string in;
    int data = 0;
    cin >> in;
    for (int i = 0;i<(in.length()/2)+(in.length()%2);i++) {
        if (i == 0) {
            if (in.length()%2 == 0) {
                data += atoi(in.substr(0,2).c_str());
            } else {
                data += atoi(in.substr(0,1).c_str());
            }
        } else {
            if (in.length()%2 == 0) {
                data += atoi(in.substr((i*2),2).c_str());
            } else {
                data += atoi(in.substr(((i-0.5)*2),2).c_str());
            }
        }
    }
    printf("%d %d",data%3,data%11);
    return 0;
}

