/*
Rabin karp can be randomize algorithm if we only check hash equal
because hash equal -> value not always equal
but very low chance
-----> can do this because high change we check hash equal will mean value equal
*/

#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

#define hk 53

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll powhk[100005];
string want,base;

bool check(int p) {
	for1(i,p,p+want.size()) {
		if (want[i-p]!=base[i]) return false;
	}
	return true;
}

int rabin() {
	int wanthash = 0;
	int basehash = 0;
	for1(i,0,want.size()) {
		wanthash += want[i]*powhk[want.size()-1-i];
		basehash += base[i]*powhk[want.size()-1-i];
	}
	
	int res = 0;
	
	if (wanthash==basehash) res++;//res+=check(0);
	
	for1(i,1,base.size()-want.size()+1) {
		basehash -= base[i-1]*powhk[want.size()-1];
		basehash *= hk;
		basehash += base[i+want.size()-1];
		
		if (wanthash==basehash) res++;//res+=check(i);
	}
	
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	powhk[0] = 1;
	for1(i,1,100005) powhk[i] = powhk[i-1]*hk;
	int t; cin>>t; while (t--) {
		cin>>want>>base;
		cout<<rabin()<<endl;
	}
	return 0;
}
