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

vector<vector<int>> E;
int n,m;
bool res = false;
vector<bool> visited;

void dfs(int c,int p) {
    if (visited[c]) {
        res = true;
        return;
    }
    visited[c] = true;

    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (ne!=p) dfs(ne,c);
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while (t--) {
        scanf("%d%d",&n,&m);
        E.resize(n+5);
        res = false;
        visited.resize(n+5,false);

        for1(i,0,m) {
            int s,e; scanf("%d%d",&s,&e);
            E[s].push_back(e);
            E[e].push_back(s);
        }

        for1(i,0,n) {
            if (!visited[i]) dfs(i,-1);
            if (res) break;
        }

        if (res) printf("YES\n"); else printf("NO\n");

        E.clear();
        visited.clear();
    }
	return 0;
}
