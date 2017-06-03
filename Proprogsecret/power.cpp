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

ll n;



ll powmod(ll x,ll y) {
	//x^y = (x^(y/2))^2 ; y is even
	//x^y = (x^(y/2))^2 * x ; y is odd (y/2 = floor(y/2) = (y-1)/2)
	if (y==1) return x%n;
	ll xy2 = powmod(x,y/2);
	xy2 *= xy2;
	if (y%2==1) xy2*=x;
	return xy2%n;
	
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; while(t--) {
		int x,y; scanf("%d%d%d",&x,&y,&n);
		printf("%lld\n",powmod(x,y));
	}
	return 0;
}
