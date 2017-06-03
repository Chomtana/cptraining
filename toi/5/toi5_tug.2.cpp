#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;
	int a[n];
	int b[n];
	for1(i,0,n) scanf("%d",a+i);
	for1(i,0,n) scanf("%d",b+i);
	sort(a,a+n);
	sort(b,b+n);
	int res = 0;
	for1(i,0,n) {
	    res += abs(a[i]-b[i]);
	}
	cout<<res;
	return 0;
}
