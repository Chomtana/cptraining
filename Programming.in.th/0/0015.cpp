/* 
 * File:   0015.cpp
 * Author: Pin
 *
 * Created on 5 มีนาคม 2558, 20:27 น.
 */

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int max (int a,int b) {
	if (a>b) {
		return a;
	} else {
		return b;
	}
}

int min (int a,int b) {
	if (a<b) {
		return a;
	} else {
		return b;
	}
}

/*
 * 
 */
int main() {
	int a,b,c;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << max(abs(a-b)-1,abs(b-c)-1);
	return 0;
}

