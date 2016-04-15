/* 
 * File:   republic.cpp
 * Author: Pin
 *
 * Created on 6 กันยายน 2557, 10:35 น.
 */

#include <stdio.h>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	int n,k;
	scanf("%d %d",&n,&k);
	int ban[200000] = {0};
	int current = -1;
	for (int i = 0;i<n-1;i++) {
		for (int i2=0;i2<k;i2++) {
			current++;
			if (current > n-1) {
				current = 0;
			}
			if (ban[current] == 1) {
				i2--;
			}
		}
		ban[current] = 1;
		k=current+1;
	}
	for (int i = 0;i<n;i++) {
		if (ban[i] == 0) {
			cout << i+1;
		}
	}
	return 0;
}

