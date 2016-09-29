#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n; cin>>n;
	double data[n];
	for1(i,0,n) {
		cin>>data[i];
	}
	sort(data,data+n);
	if (n%2==0) {
		double d = (data[n/2]+data[n/2-1])/2;
		printf("%.1lf", d);
	} else {
		printf("%.1lf", data[n/2]);
	}
	return 0;
}
