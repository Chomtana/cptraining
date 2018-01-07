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

int n,m;
int S[50005];
int E[50005];

bool pairfirstcomp(const pii a,const pii b) {
	return a.first<b.first;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n>>m;
	for1(i,0,n) {
		scanf("%d %d",S+i,E+i);
	}
	sort(S,S+n);
	sort(E,E+n);
	ll res = 0;
	while(m--) {
		int x; scanf("%d",&x);
		int gr = lower_bound(S,S+n,x)-S;
		int grc = n-gr;
		int lt = upper_bound(E,E+n,x)-E;
		lt--;
		int ltc = lt+1;

		res += n-grc-ltc;
		res %= 2007;
	}
	cout<<res;
	return 0;
}
