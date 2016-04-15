/* 
 * File:   0033.cpp
 * Author: Pin
 *
 * Created on April 1, 2015, 10:42 AM
 */

#include <iostream>
#include <vector>

using namespace std;

int max(vector<int> n) {
	int currmax = -1;
	for (int i = 0;i<n.size();i++) {
		if (n[i] > currmax) {
			currmax = n[i];
		}
	}
	return currmax;
}

/*
 * 
 */
int main(int argc, char** argv) {
	int n;
	cin >> n;
	vector<int> count(10001);
	for (int i = 0;i<n;i++) {
		int in;
		cin >> in;
		count[in]++;
	}
	
	int maxcount = max(count);
	
	for (int i = 0;i<10001;i++) {
		if (count[i] == maxcount) {
			cout << i << " ";
		}
	}
	return 0;
}

