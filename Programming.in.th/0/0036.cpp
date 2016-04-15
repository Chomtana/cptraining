/* 
 * File:   0036.cpp
 * Author: Pin
 *
 * Created on April 1, 2015, 3:14 PM
 */

#include <iostream>
#include <math.h>

using namespace std;

long long multiplydown(long long n,long long count) { //5*4 count = 2
	long long result = 1;
	for (long long i = 0;i<count;i++) {
		result *= n;
		n--;
	}
	return result;
}

long long factorial(long long n) {
	if (n == 0) {
		return 1;
	}
	return multiplydown(n,n-1);
}

long long combination(long long n,long long r) {
	return multiplydown(n,r)/factorial(r);
}

/*
 * 
 */
int main(int argc, char** argv) {
	long long n;
	cin >> n;
	if (n%2 == 0) {
		cout << combination(n,n/2); //C4,2 = 6 * C2,2 = 1 ... 6*1 = 6
	} else {
		cout << combination(n,floor(n/2))+combination(n,ceil(n/2));
	}
	return 0;
}

