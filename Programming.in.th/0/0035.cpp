/* 
 * File:   0035.cpp
 * Author: Pin
 *
 * Created on March 21, 2015, 9:33 PM
 */

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

struct point {
	float x;
	float y;
};

float abs(float f) {
	if (f<0) {
		return -f;
	} else {
		return f;
	}
}

float calarea(point p1,point p2,point p3) {
	return abs(p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.y*p2.x - p2.y*p3.x - p3.y*p1.x)/2;
}

/*
 * 
 */
int main() {
	int n;
	cin >> n;
	point p[n];
	for (int i = 0;i<n;i++) {
		cin >> p[i].x;
		cin >> p[i].y;
	}
	
	float currmax = -1;
	for (int i = 0;i<n;i++) {
		for (int i2 = i+1;i2<n;i2++) {
			for (int i3 = i2+1;i3<n;i3++) {
				float a = calarea(p[i],p[i2],p[i3]);
				if (a > currmax) {
					currmax = a;
				}
			}
		}
	}
	printf("%.3f",currmax);
	return 0;
}

