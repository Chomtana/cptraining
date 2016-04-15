#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char s[201];
    int level = 0;
    int count = 0;
    scanf("%s",&s);
    for (int i = 0;i < strlen(s);i++) {
        if (s[i] == ')') {
            level--;
        } else if (s[i] == '(') {
            level++;
        }
        if (level < 0) {
            level = 0;
            count++;
        }
    }
    cout << count+level;
    return 0;
}

