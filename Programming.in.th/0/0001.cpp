#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int i[4];
    scanf("%d %d %d",&i[0],&i[1],&i[2]);
    i[3] = i[0]+i[1]+i[2];
    if (i[3] >= 80) {
        cout << "A";
    } else if (i[3] >= 75) {
        cout << "B+";
    } else if (i[3] >= 70) {
        cout << "B";
    } else if (i[3] >= 65) {
        cout << "C+";
    } else if (i[3] >= 60) {
        cout << "C";
    } else if (i[3] >= 55) {
        cout << "D+";
    } else if (i[3] >= 50) {
        cout << "D";
    } else {
        cout << "F";
    }
    return 0;
}

