/* 
 * File:   1003.cpp
 * Author: Pin
 *
 * Created on 6 มีนาคม 2558, 17:27 น.
 */

#include <iostream>
#include <string>

using namespace std;

bool result[101] = {0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,0,0,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

/*
 * 
 */
int main() {
	//Code used to generate result array
	/*bool result[101] = {0};
	for (int i = 0;i*6<=100;i++) {
		result[i*6] = true;
		for (int i2 = 0;i*6+i2*9<=100;i2++) {
			result[i*6+i2*9] = true;
			for (int i3 = 0;i*6+i2*9+i3*20<=100;i3++) {
				result[i*6+i2*9+i3*20] = true;
			}
		}
	}
	for (int i = 0;i<=100;i++) {
		if (i != 0) {
			cout << result[i];
		} else {
			cout << 0;
		}
		if (i<100) {
			cout << ",";
		}
	}*/
	int n;
	bool found = false;
	cin >> n;
	for (int i = 1;i<=n;i++) {
		if (result[i]) {
			cout << i << "\n";
			found = true;
		}
	}
	if (!found) {
		cout << "no";
	}
	return 0;
}

