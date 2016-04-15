#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int d,m;
    int result = 3;
    scanf("%d %d",&d,&m);
    for (int i = 1;i<m;i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            d += 31;
        } else if (i == 2) {
            d += 28;
        } else {
            d += 30;
        }
    }
    result += d;
    result = result%7;
    switch (result) {
        case 0: cout << "Sunday"; break;
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
    }
    return 0;
}

