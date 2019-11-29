#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;
#define debug1(a) cout<<(a)<<endl;
#define debug2(a,b) cout<<(a)<<' '<<(b)<<endl;
#define debug3(a,b,c) cout<<(a)<<' '<<(b)<<' '<<(c)<<endl;
#define debug4(a,b,c,d) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<' '<<(e)<<endl;
#define until(x) while(!x)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,m;
vector<int> P;
vector<pii> C;
map<int,int> Pmap;
vector<vector<int>> C2P;
vector<vector<int>> P2C;

deque<int> player;

bool deleted[1000005];

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
	cin>>n>>m;

	C2P.resize(m+5);
	P2C.resize(n+5);

	for1(i,0,1000005) { Pmap[i] = -1; deleted[i] = false; }

	for1(i,0,n) {
		int x; scanf("%d", &x);
		P.push_back(x);
		Pmap[x] = i;
		player.push_back(i);
	}

	for1(i,0,m) {
		int x,t; scanf("%d %d", &x, &t);
		C.push_back({x,t});
		for(int j = x-t;j<=x+t;j++) {
			//cerr<<Pmap[j]<<endl;
			if (Pmap[j] != -1) {
				C2P[i].push_back(Pmap[j]);
				P2C[Pmap[j]].push_back(i);
			}
		}
	}

	int res = 0;

	while (player.size() > 0) {
		sort(all(player), [](int a,int b) {
			return P2C[a].size() < P2C[b].size();
		});

		while (P2C[player[0]].size() == 0 && player.size() > 0) player.pop_front();
		if (player.size() == 0) break;

		int todel = -1;
		for(int i = 0;i<P2C[player[0]].size();i++) {
			int x = P2C[player[0]][i];
			if (!deleted[x]) {
				todel = x;
				break;
			}
		}

		if (todel == -1) {
			player.pop_front();
			continue;
		}

		deleted[todel] = true;
		player.pop_front();
		res++;
	}

	cout<<res;
	return 0;
}

/*
3 5
1
3
5
-6 7
10 6
11 3
-2 2
-4 5
*/
