#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;

struct djnode {
	int parent;
	int rank = 0;
};

djnode djset[3005];

int find(int i) {
	if (djset[i].parent==i) return i;
	return djset[i].parent = find(djset[i].parent);
}

void un(int a,int b) {
	a = find(a);
	b = find(b);
	if (djset[a].rank<djset[b].rank) {
		djset[a].parent = b;
		djset[b].rank++;
	} else {
		djset[b].parent = a;
		djset[a].rank++;
	}
}



piii El[1000005];

int dist[3005];

vector<vector<pii>> E(3005);
vector<bool> visited(3005,false);

int reals,reale,p;

int res = 1E9;

/*bool dfs(int curr) {
	
	if (curr==reale) return true;
	
	if (visited[curr]) return false;
	visited[curr] = true;
	
	
	for1(i,0,E[curr].size()) {
		if (dfs(E[curr][i].first)) {
			res = min(res,E[curr][i].second);
			return true;
		}
	}
	return false;
}*/

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	for1(i,0,3005) djset[i].parent = i;
	
	int n,m; cin>>n>>m;
	for1(i,0,m) {
		int s,e,w; scanf("%d%d%d",&s,&e,&w);
		//s--; e--;
		El[i] = mp(w,mp(s,e));
		
	}
	
	sort(El,El+m,greater<piii>());
	
	vector<int> select;
	int selectsize = 0;
	
	for1(i,0,m) {
		int s = El[i].second.first;
		int e = El[i].second.second;
		int w = El[i].first;
		
		if (find(s)!=find(e)) {
			un(s,e);
			select.push_back(i);
			E[s].push_back(mp(e,w));
			E[e].push_back(mp(s,w));
			selectsize++;
		}
	}
	//cerr<<selectsize<<endl
	
	/*for1(i,0,select.size()) {
		cerr<<select[i]<<' ';
	}
	cerr<<endl;*/
	
	scanf("%d%d%d",&reals,&reale,&p);
	//reals--; reale--;
	
	//dfs(reals);
	
	//memset(dist,1000,sizeof(dist));
	for1(i,0,3005) dist[i] = 1E9;
	queue<int> q;
	q.push(reals);
	dist[reals] = 1E9;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		
		for1(i,0,E[curr].size()) {
			int ne = E[curr][i].first;
			if (dist[ne]==1E9) {
				dist[ne] = min(dist[curr],E[curr][i].second);
				q.push(ne);
			}
		}
	}
	
	int res = dist[reale];
	
	//cerr<<res<<endl;
	//cap 3 human 9 -> 3 round
	//cap x , r round , human p+r -> (p+r)/x round
	//(p+r)/x = r
	//p = r(x-1)
	//r = p/(x-1)
	
	cout<<(p%(res-1)==0?p/(res-1):p/(res-1)+1);
	
	return 0;
}
