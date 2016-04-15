#include <iostream>

using namespace std;

int result[5] = {0,0,0,0,0};
//i,v,x,l,c
//1,5,10,50,100

void genroman(int n) {
    if (n<4) {
        result[0] += n;
    } else if (n==4) {
        result[0] += 1;
        result[1] += 1;
    } else if (n<9) {
        result[0] += n-5;
        result[1] += 1;
    } else if (n==9) {
        result[0] += 1;
        result[2] += 1;
    } else if (n<40) {
        result[2] += n/10;
        genroman(n%10);
    } else if (n>=40 && n<50) {
        result[2] += 1;
        result[3] += 1;
        genroman(n%10);
    } else if (n<90) {
        result[3] += 1;
        result[2] += (n-50)/10;
        genroman(n%10);
    } else if (n>=90 && n<100) {
        result[2] += 1;
        result[4] += 1;
        genroman(n%10);
    } else {
        result[4] += n/100;
        genroman(n%100);
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1;i<=n;i++) {
        genroman(i);
    }
    for (int i = 0;i<5;i++) {
        cout << result[i] << " ";
    }
    return 0;
}