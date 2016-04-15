#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char s[51];
    int pos = 1;
    scanf("%s",&s);
    for (int i = 0;i<strlen(s);i++) {
        switch (s[i]) {
            case 'A':
                if (pos == 1) {
                    pos = 2;
                } else if (pos == 2) {
                    pos = 1;
                }
                break;
            case 'B':
                if (pos == 2) {
                    pos = 3;
                } else if (pos == 3) {
                    pos = 2;
                }
                break;
            case 'C':
                if (pos == 1) {
                    pos = 3;
                } else if (pos == 3) {
                    pos = 1;
                }
                break;
        }
    }
    cout << pos;
    return 0;
}

