#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    if (x>y) {
        cout << 2;
    } else {
    if (y%x != 0) {
        cout << (y/x)+1;
    } else {
        cout << y/x;
    }
    }
    return 0;
}

