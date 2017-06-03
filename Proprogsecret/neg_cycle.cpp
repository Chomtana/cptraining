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
typedef pair<int,pii> piii;
typedef vector<int> vi;

piii El[2005];
int dist[1005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; while(t--) {
		int n,m; scanf("%d%d",&n,&m);
		
		//E.resize(n+5);
		
		for1(i,0,m) {
			int s,e,w; scanf("%d%d%d",&s,&e,&w);
			El[i] = mp(w,mp(s,e));
		}
		
		dist[0] = 0;
		for1(i,1,n+5) dist[i] = 1E9;
		
		for1(i,0,n-1) {
			for1(j,0,m) {
				int s = El[j].second.first;
				int e = El[j].second.second;
				int w = El[j].first;
				dist[e] = min(dist[e],dist[s]+w);
			}
		}
		
		bool neg = false;
		
		for1(j,0,m) {
			int s = El[j].second.first;
			int e = El[j].second.second;
			int w = El[j].first;
			if (dist[s]+w<dist[e]) {
				neg = true;
				break;
			}
		}
		
		if (neg) printf("possible\n"); else printf("not possible\n");
		
		//E.clear();
	}
	return 0;
}
