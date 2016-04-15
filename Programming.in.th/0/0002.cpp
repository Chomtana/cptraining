#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    int max = -2000000000;
    int min = 2000000000;
    scanf("%d",&n);
    for (int i = 0;i<n;i++) {
        int i2;
        scanf("%d",&i2);
        if (i2 > max) {
            max = i2;
        }
        if (i2 < min) {
            min = i2;
        }
    }
    cout << min << "\n" << max;
    return 0;
}

