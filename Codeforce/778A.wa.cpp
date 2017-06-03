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

int G[200005]; //G[target char pos] = group of that pos
int Gs[200005];

set<int> cp[30];
set<int> Gdata[200005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	string s,t; cin>>s>>t;
	
	for1(i,0,s.size()) {
		cp[s[i]-'a'].insert(i);
		Gs[i] = -1;
	}
	
	//for(auto &x:cp[1]) cerr<<x<<' '; cerr<<endl;
	
	G[0] = 0;
	int pos = *(cp[t[0]-'a'].begin());
	Gdata[G[0]].insert(pos);
	Gs[pos] = G[0];
	cp[t[0]-'a'].erase(cp[t[0]-'a'].begin());
	for1(i,1,t.size()) {
		if (t[i]==t[i-1]) {
			G[i] = G[i-1];
		} else {
			G[i] = G[i-1]+1;
		}
		
		//cerr<<i<<' '<<G[i]<<' '<<*(cp[t[i]-'a'].begin())<<endl;
		
		int pos = *(cp[t[i]-'a'].begin());
		Gs[pos] = G[i];
		Gdata[G[i]].insert(pos);
		cp[t[i]-'a'].erase(cp[t[i]-'a'].begin());
		
	}
	
	int ng = G[t.size()-1]+1;
	
	/*for1(i,0,ng) {
		for(auto &x:Gdata[i]) {
			cerr<<x<<' ';
		}
		cerr<<endl;
	}*/
	
	//for1(i,0,s.size()) cerr<<Gs[i]<<' '; cerr<<endl;
	
	for1(i,0,s.size()) {
		//cerr<<"bbb"<<i<<endl;
		int x; scanf("%d",&x);
		x--;
		cp[s[x]-'a'].erase(x);
		if (Gs[x]!=-1) {
			Gdata[Gs[x]].erase(x);
			if (cp[s[x]-'a'].size()==0) {
				cout<<i;
				break;
			}
			int ne = *cp[s[x]-'a'].begin();
			cp[s[x]-'a'].erase(cp[s[x]-'a'].begin());
			if (Gs[x]+1<ng) {
				if (ne>*Gdata[Gs[x]+1].begin()) {
					cout<<i;
					break;
				}
			}
			Gdata[Gs[x]].insert(ne);
			Gs[ne] = Gs[x];
			Gs[x] = -1;
		}
		
	}
	
	//cerr<<"aaa";
	return 0;
}
