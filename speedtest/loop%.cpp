#include <bits/stdc++.h>

using namespace std;

int main() {
	long long x = 0;
	for (long long i = 0;i<100000000;i++) {
		x+=1000;
		x%=1000000007;
	}
	cout<<x;
	//super very slower than loop++only
	return 0;
}