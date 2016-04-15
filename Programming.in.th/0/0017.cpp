#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int max (int a,int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
    return 0;
}

int min (int a,int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
    return 0;
}

int main() {
    int i1 = -1;
    int i2 = -1;
    int n[4],up,right,bottom;
    bool upf = false;
    bool rf = false;
    scanf("%d %d %d %d",&n[0],&n[1],&n[2],&n[3]);
    up = max(max(max(n[0],n[1]),n[2]),n[3]);
    right = min(min(min(n[0],n[1]),n[2]),n[3]);
    for (int i = 0;i < 4;i++) {
        if ((up != n[i] && right != n[i]) || ((up == n[i] && upf) || (right == n[i] && rf))) {
            if (i1 != -1) {
                i2 = i;
            } else {
                i1 = i;
            }
        }
        if (up == n[i]) {
            upf = true;
        }
        if (right == n[i]) {
            rf = true;
        }
    }
    bottom = max(n[i1],n[i2]);
    cout << bottom*right;
    return 0;
}

