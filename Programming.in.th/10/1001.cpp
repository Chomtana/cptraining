/* 
 * File:   1001.cpp
 * Author: Pin
 *
 * Created on 5 มีนาคม 2558, 21:25 น.
 */

#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main() {
	int w,h;
	cin >> h;
	cin >> w;
	int block[21] = {0};
	char data[h][w];
	//int number[w] = {0};
	for (int i = 0;i<h;i++) {
		cin >> data[i];
		for (int i2 = 0;i2<w;i2++) {
			if (data[i][i2] == 'O') {
				if (block[i2] == 0) {
					block[i2] = i+1;
				}
			}
		}
	}
	for (int i = 0;i<w;i++) {
		int num;
		cin >> num;
		int blockagent = 0;
		if (block[i] == 0) {
			blockagent = h-1;
		} else {
			blockagent = block[i]-2;
		}
		if (block[i] != 1) {
			for (int i2 = blockagent;i2>blockagent-num;i2--) {
				data[i2][i] = '#';
				if (i2 == 0) {
					break;
				}
			}
		}
		//cout << block[i] << "\n";
	}
	for (int i = 0;i<h;i++) {
		for (int i2 = 0;i2<w;i2++) {
			cout << data[i][i2];
		}
		cout << "\n";
	}
	return 0;
}

