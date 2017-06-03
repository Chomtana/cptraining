#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool isp[1000005];

void sieve() {
	for1(i,0,1000003) isp[i] = true;
	isp[0] = false;
	isp[1] = false;
	for1(i,0,sqrt(1000003)) {
		if (isp[i]) {
			for(ll j = (ll)i*(ll)i;j<1000003;j+=(ll)i) {
				isp[j] = false;
			}
		}
	}
	
	
}



int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	sieve();
	int n;
	while(scanf("%d",&n),n!=0) {
		int res = 0;
		for1(i,1,sqrt(n)+1) {
			if (n%i==0) {
				res += isp[i];
				res += isp[n/i];
				if (i==n/i && isp[i]) {
					res--;
				}
			}
		}
		printf("%d : %d\n",n,res);
	}
	return 0;
}
