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

vector<vector<pii>> E;
int dist[20005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; for1(_,1,t+1) {
		int n,m,reals,reale; scanf("%d%d%d%d",&n,&m,&reals,&reale);
		
		E.resize(n);
		
		for1(i,0,m) {
			int s,e,w; scanf("%d%d%d",&s,&e,&w);
			E[s].push_back(mp(e,w));
			E[e].push_back(mp(s,w));
		}
		
		priority_queue<pii,vector<pii>,greater<pii>> q;
		q.push(mp(0,reals));
		fill(dist,dist+20005,1E9);
		dist[reals] = 0;
		while(!q.empty()) {
			int curr = q.top().second;
			q.pop();
			
			for1(i,0,E[curr].size()) {
				int next = E[curr][i].first;
				if (dist[curr]+E[curr][i].second < dist[next]) {
					dist[next] = dist[curr]+E[curr][i].second;
					q.push(mp(dist[next],next));
				}
			}
		}
		
		if (dist[reale]>=1E9) {
			printf("Case #%d: unreachable\n",_);
		} else
		printf("Case #%d: %d\n",_,dist[reale]);
		
		E.clear();
	}
	return 0;
}
