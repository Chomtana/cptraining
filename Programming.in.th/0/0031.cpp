#include <stdio.h>
#include <iostream>

using namespace std;

int max(int a,int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int n[3];
    int count = 0;
    scanf("%d %d %d",&n[0],&n[1],&n[2]);
    while (!(n[0] == 1 && n[1] == 1 && n[2] == 1)) {
        int i;
        i = max(max(n[0],n[1]),n[2]);
        if (i == n[0]) {
            i = 0;
        } else if (i == n[1]) {
            i = 1;
        } else if (i == n[2]) {
            i = 2;
        }
        if (n[i]%2!=0) {
            n[i] = n[i]-1;
        }
        n[i] = n[i]/2;
        count++;
    }
    cout << count;
    return 0;
}

