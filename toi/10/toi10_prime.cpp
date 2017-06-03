#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

//vector<int> pl;
bool isp[10000005];

void sieve() {
	for1(i,0,10000000) isp[i] = true;
	isp[0] = false;
	isp[1] = false;
	for1(i,2,sqrt(10000000)) {
		if (isp[i]) {
			for(ll j = ll(i)*ll(i);j<10000000;j+=ll(i)) {
				isp[j] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;
	sieve();
	
	//cout<<pl[n-1]; //MLE
	
	int c = 0;
	for1(i,2,10000000) {
		if (isp[i]) {
			c++;
			if (c==n) {
				cout<<i; return 0;
			}
		}
	}
	return 0;
}
