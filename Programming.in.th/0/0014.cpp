#include <stdio.h>
#include <iostream>

using namespace std;

int min(int a,int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
    return 0;
}

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    for (int i = min(a,b);i >= 1;i--) {
        if (a%i == 0) {
            if (b%i == 0) {
                cout << i;
                break;
            }
        }
    }
    return 0;
}

