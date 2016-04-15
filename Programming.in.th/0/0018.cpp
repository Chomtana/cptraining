/* 
 * File:   0018.cpp
 * Author: Pin
 *
 * Created on March 22, 2015, 12:28 PM
 */

#include <iostream>

using namespace std;

int n,k;
bool killed[1001] = {false};
int current = 1; //n = 10 k = 1 ; result = 2 (ตัวแรก)

void dokill() {
	//Find first not killed value (start at 2)
	int base = 0; //First not killed value
	for (int i = 2;i<=n;i++) {
		if (!killed[i]) {
			base = i;
			break;
		}
	}
	for (int i = 1;base*i<=n;i++) {
		if (killed[base*i]) {
			continue;
		}
		killed[base*i] = true;
		if (k == current) {
			cout << base*i;
			return;
		}
		current++;
	}
	dokill();
}

/*
 * 
 */
int main() {
	cin >> n >> k;
	dokill();
	
	return 0;
}

