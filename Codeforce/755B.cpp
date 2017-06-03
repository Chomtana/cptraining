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

string a[1005];
string b[1005];
map<string,int> c;

bool compfunc(const string &i,const string &j) {
	return c[i]>c[j];
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n,m; cin>>n>>m;
	
	for1(i,0,n) {
		cin>>a[i];
		c[a[i]]++;
	}
	for1(i,0,m) {
		cin>>b[i];
		c[b[i]]++;
	}
	sort(a,a+n,compfunc);
	sort(b,b+m,compfunc);
	set<string> speaked;
	bool turn = true; //true = poland(a)
	int ait=0,bit=0;
	while(true) {
		if (turn) {
			while(ait<n && speaked.find(a[ait])!=speaked.end()) ait++;
			if (ait==n) break;
			speaked.insert(a[ait]);
			ait++;
			
		} else {
			while(bit<m && speaked.find(b[bit])!=speaked.end()) bit++;
			if (bit==m) break;
			speaked.insert(b[bit]);
			bit++;
		}
		
		turn = !turn;
	}
	
	cout<<(turn==0?"YES":"NO");
	return 0;
}
