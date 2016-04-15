#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int min (int a,int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
    return -1;
}

int max (int a,int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
    return -1;
}

int main() {
    int i[3];
    int a,b,c;
    char s[4];
    scanf("%d %d %d",&i[0],&i[1],&i[2]);
    scanf("%s",&s);
    a = min(min(i[0],i[1]),i[2]);
    c = max(max(i[0],i[1]),i[2]);
    if (i[0] != a && i[0] != c) {
        b = i[0];
    } else if (i[1] != a && i[1] != c) {
        b = i[1];
    } else if (i[2] != a && i[2] != c) {
        b = i[2];
    }
    for (int i = 0;i < 3;i++) {
        if (s[i] == 'A') {
            cout << a;
        } else if (s[i] == 'B') {
            cout << b;
        } else if (s[i] == 'C') {
            cout << c;
        }
        cout << ' ';
    }
    return 0;
}

