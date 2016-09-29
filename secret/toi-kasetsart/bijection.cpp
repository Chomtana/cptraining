#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n; cin>>n;
	vector<bool> found(n,false);
	for1(i,0,n) {
		int in; cin>>in;
		if (in < 1 || in > n) {
			cout<<"NO";
			return 0;
		}
		in--; //input start 1 -> index start 0
		if (found[in]) {
			cout<<"NO";
			return 0;
		}
		found[in] = true;
	}

	//bool res = true;
	for1(i,0,n) {
		if (!found[i]) {
			//res = false;
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}
