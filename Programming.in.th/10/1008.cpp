/* 
 * File:   1008.cpp
 * Author: Pin
 *
 * Created on 13 มีนาคม 2558, 20:19 น.
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
	int n;
	cin >> n;
	int blockh[255] = {0};
	int maxpos = 0;
	for (int i = 0;i<n;i++) {
		int start,h,end;
		cin >> start >> h >> end;
		if (end > maxpos) {
			maxpos = end;
		}
		for (int i = start;i<end;i++) {
			if (h > blockh[i]) {
				blockh[i] = h;
			}
		}
	}
	int lastprint = 0;
	for (int i = 0;i<maxpos;i++) {
		if (blockh[i] != lastprint) {
			cout << i << " " << blockh[i] << " ";
			lastprint = blockh[i];
		}
	}
	cout << maxpos << " " << 0;
	return 0;
}

