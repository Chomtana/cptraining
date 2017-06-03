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

ll powhk[200005];

int n;
string s;

bool check(int k) {
	//cerr<<k<<endl;
	unordered_set<ll> H(1000000);
	
	ll h = 0;
	for1(i,0,k) {
		h += (s[i]-'a')*powhk[k-i-1];
	}
	
	H.insert(h);
	
	for1(i,1,s.size()-k+1) {
		h -= (s[i-1]-'a')*powhk[k-1];
		h *= hk;
		h += (s[i+k-1]-'a');
		//cerr<<k<<' '<<i<<' '<<h<<endl;
		if (H.find(h)!=H.end()) return true;
		H.insert(h);
	}
	
	return false;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n>>s;
	int l = 0; int r = n;
	powhk[0] = 1;
	for1(i,1,200005) powhk[i] = powhk[i-1]*hk;
	while (l<=r) {
		int mid = (l+r)/2;
		
		if (check(mid)) {
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	
	cout<<l-1;
	return 0;
}
