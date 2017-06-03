#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

#define hk 205

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

string want,base;
ll powhk[100005];

bool check(int p) {
	for1(i,p,p+want.size()) {
		if (base[i]!=want[i-p]) return false;
	}
	return true;
}

bool rabin() {
	ll wanthash = 0;
	ll basehash = 0; //base hash (hash of base substring size = want.size())
	for1(i,0,want.size()) {
		wanthash += want[i]*powhk[want.size()-i-1];
		basehash += base[i]*powhk[want.size()-i-1];
	}
	
	if (basehash==wanthash) {
		if (check(0)) return true;
	}
	
	for1(i,1,base.size()-want.size()+1) {
		basehash -= base[i-1]*powhk[want.size()-1];
		basehash *= hk;
		basehash += base[i+want.size()-1];
		//cerr<<basehash<<' '<<wanthash<<endl;
		if (basehash==wanthash && check(i)) return true;
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	powhk[0] = 1;
	for1(i,1,100005) powhk[i] = powhk[i-1]*hk;
	int t; cin>>t; while(t--) {
		cin>>want>>base;
		if (want.size()>base.size()) {
			printf("No\n");
			continue;
		}
		if (rabin()) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}
