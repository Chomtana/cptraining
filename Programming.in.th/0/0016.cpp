#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int max (int a,int b) {
    if (a>b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int n;
    char in[102];
    int score0 = 0;
    int score1 = 0;
    int score2 = 0;
    int high = 0;
    char answer[3][6];
    scanf("%d",&n);
    scanf("%s",&in);
    answer[0][0] = 'A';
    answer[0][1] = 'B';
    answer[0][2] = 'C';
    answer[1][0] = 'B';
    answer[1][1] = 'A';
    answer[1][2] = 'B';
    answer[1][3] = 'C';
    answer[2][0] = 'C';
    answer[2][1] = 'C';
    answer[2][2] = 'A';
    answer[2][3] = 'A';
    answer[2][4] = 'B';
    answer[2][5] = 'B';
    for (int i = 0;i<n;i++) {
        if (in[i] == answer[0][i%3]) {
            score0++;
        }
        if (in[i] == answer[1][i%4]) {
            score1++;
        }
        if (in[i] == answer[2][i%6]) {
            score2++;
        }
    }
    high = max(max(score0,score1),score2);
    cout << high << "\n";
    if (high == score0) {
        cout << "Adrian" << "\n";
    }
    if (high == score1) {
        cout << "Bruno" << "\n";
    }
    if (high == score2) {
        cout << "Goran" << "\n";
    }
    return 0;
}

