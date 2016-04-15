/* 
 * File:   0034.cpp
 * Author: Pin
 *
 * Created on April 1, 2015, 12:12 PM
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	int A,B,C;
	cin >> A >> B >> C;
	vector<int> a,b,c,d;
	
	//Calculate A = ac
	for (int i = 1;i<=abs(A);i++) {
		if (A%i == 0) {
			if (A < 0) { //i = c
				a.push_back(A/i);
				c.push_back(i);
			} else { //i = a (6 -> a = 1,2,3,6 b = 6,3,2,1)
				a.push_back(i);
				c.push_back(A/i);
			}
		}
	}
	
	//Calculate C = bd
	for (int i = 1;i<=abs(C);i++) {
		//i = d 
		if (C%i == 0) {
			if (C < 0) { //i = d
				b.push_back(C/i);
				d.push_back(i);
			} else { //i = b (6 -> b = 1,2,3,6 d = 6,3,2,1)
				b.push_back(i);
				d.push_back(C/i);
			}
		}
	}
	
	//Check all condition (A = ac B = ad+bc C = bd)
	for (int i = 0;i<a.size();i++) {
		for (int i2 = 0;i2<b.size();i2++) {
			for (int i3 = 0;i3<c.size();i3++) {
				for (int i4 = 0;i4<d.size();i4++) {
					if (B == (a[i]*d[i4])+(b[i2]*c[i3]) && A == a[i]*c[i3] && C == b[i2]*d[i4]) {
						cout << a[i] << " " << b[i2] << " " << c[i3] << " " << d[i4];
						return 0;
					}
				}
			}
		}
	}
	cout << "No Solution";
	return 0;
}

