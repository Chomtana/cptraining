#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
	int n,k; cin>>n>>k;
	int d[n];
	for1(i,0,n) {
		cin>>d[i];
	}

	int x = d[k-1];
	int c = 0;

	for1(i,0,n) {
		if (d[i]>=x && d[i]>0) c++;
	}

	cout<<c;

	return 0;
}
