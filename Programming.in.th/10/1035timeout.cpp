//to_string is not compatible with old compiler .... use sprintf instead
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

int oddpa = 1;
int oddcenter = 0; //0-9
int evenpa = 1;
int digit = 1;

int nextPalindrome() {

}

bool isPalindrome(int n) {
    int len = log10(n)+1;
    if (len%2 == 0) {
        return n%11==0;
    } else {
        //101 -> len = 3
        //11 = (int)(101/100)*10+(101%10) = (int)(101/10^2)*10^1+(101%10^1) = (int)(n/10^p)*10^[p-1]+(n%10^[p-1]);p=ceil(len/2)
        int p = ceil((double)len/2);
        int _n = (int)(n/(int)pow(10,p))*(int)pow(10,p-1)+(n%(int)pow(10,p-1));
        //cout << n << " " << _n << "\n";
        return _n%11==0;
    }
    return false;
}

bool isPrime(int n) {
    bool result = true;
    for (int i = 2;i<n;i++) {
        if (n%i == 0) {
            result = false;
        }
    }
    return result;
}

int main() {
    int n; cin >> n;
    digit = log10(n)+1;
    if (digit%2 == 0) {

    }

    while (!(isPrime(n) && isPalindrome(n))) {
        n++;
    }
    cout << n;
    return 0;
}
