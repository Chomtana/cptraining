#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
    char in[102];
    string result = "";
    gets(in);
    for (int i = 0;i<strlen(in);i++) {
        result += in[i];
        if (in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u') {
            i += 2;
        }
    }
    cout << result;
    return 0;
}

