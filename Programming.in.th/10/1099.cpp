/* 
 * File:   1099.cpp
 * Author: Pin
 *
 * Created on 11 มีนาคม 2558, 20:00 น.
 */

#include <iostream>

using namespace std;

int min(int a,int b) {
	if (a<b) {
		return a;
	} else {
		return b;
	}
}

/*
 * 
 */
int main(int argc, char** argv) {
	int r,g;
	cin >> r;
	cin >> g;
	int n = min(r,g);
	int nold = n;
	int highresult[100000] = {0};
	int highresultlen = 0;
	for (int i = 1;i<=n;i++) {
		if (nold%i == 0) {
			n = nold/i;
			if (n > i && r%n == 0 && g%n == 0) {
				highresult[highresultlen] = n;
				highresultlen++;
			}
			
			//After set highresult because case 500 9000 : last number must set before this block run
			if (i != highresult[highresultlen-1] && r%i == 0 && g%i == 0) {
				cout << i << " " << r/i << " " << g/i << "\n";
			}
		}
	}
	for (int i = highresultlen-1;i>=0;i--) {
		cout << highresult[i] << " " << r/highresult[i] << " " << g/highresult[i] << "\n";
	}
	return 0;
}

