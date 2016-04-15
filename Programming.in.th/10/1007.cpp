/* 
 * File:   1007.cpp
 * Author: Pin
 *
 * Created on 13 มีนาคม 2558, 14:35 น.
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	int work = 1;
	int soldier = 0;
	//phaya = 1
	int year;
	cin >> year;
	while (year != -1) {
		for (int i = 0;i<year;i++) {
			int workold = work;
			int soldierold = soldier;
			work = 1+workold+soldierold;
			soldier = workold;
		}
		cout << work << " " << work+soldier+1 << "\n";
		cin >> year;
		work = 1;
		soldier = 0;
	}
	return 0;
}

