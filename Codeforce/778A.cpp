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

int rem[200005];
bool ban[200005];
string s,t;

bool check(int n) {
	for1(i,0,s.size()) ban[i] = false;
	
	for1(i,0,n) {
		ban[rem[i]] = true;
	}
	
	int curr = 0;
	for1(i,0,t.size()) {
		while (curr<s.size() && (t[i]!=s[curr] || ban[curr])) {
			curr++;
		}
		if (curr>=s.size()) return false; else curr++;
	}
	return true;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>s>>t;
	for1(i,0,s.size()) {
		scanf("%d",rem+i);
		rem[i]--;
	}
	
	int l = 0; int r = s.size();
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
