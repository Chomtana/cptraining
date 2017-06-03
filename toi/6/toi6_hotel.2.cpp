#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;
	int res = (n/15)*3000;
	n %= 15;
	int xxx[16];
	xxx[0] = 0;
	xxx[1] = 500;
	xxx[2 ] = 800;
	xxx[3 ] = 1300;
	xxx[4 ] = 1500;
	xxx[5 ] = 1500;
	xxx[6 ] = 2000;
	xxx[7 ] = 2300;
	xxx[8 ] = 2800;
	xxx[9 ] = 3000;
	xxx[10] =  3000;
	xxx[11] =  3000;
	xxx[12] =  3000;
	xxx[13] =  3000;
	xxx[14] =  3000;
	xxx[15] =  3000;
	cout<<res+xxx[n];
	return 0;
}
