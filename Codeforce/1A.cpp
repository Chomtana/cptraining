#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
	long long n,m,a; cin>>n>>m>>a;
	long long nn = n/a;
	long long mm = m/a;
	cout<<((nn+(n%a!=0))*(mm+(m%a!=0)));
	return 0;
}
