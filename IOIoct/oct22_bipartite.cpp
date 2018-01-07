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

int n,m;
int color[100005];
vector<int> E[100005];
bool visited[100005];

bool dfs(int c) {
    if (visited[c]) return true;
    visited[c] = true;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (color[c]==0 && color[ne]==0) {
            color[c] = 1;
            color[ne] = 2;
        } else if (color[c]==0) {
            if (color[ne]==1) color[c]=2; else color[c]=1;
        } else if (color[ne]==0) {
            if (color[c]==1) color[ne]=2; else color[ne]=1;
        } else {
            //return color[c]!=color[ne];
			if (color[c]==color[ne]) return false;
        }

        if(!dfs(E[c][i])) return false;
    }

    return true;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; while(t--) {
        scanf("%d%d",&n,&m);
        for1(i,0,m) {
            int s,e; scanf("%d%d",&s,&e);
            E[s].push_back(e);
            E[e].push_back(s);
        }

        bool res = true;
        for1(i,1,n+1) {
            if (!visited[i]) {
                bool dfsres = dfs(i);
                //cerr<<"aaa "<<dfsres<<endl;
                if(!dfsres) {
                    res = false;
                    break;
                }
            }
        }

        if (res) printf("yes\n"); else printf("no\n");

        for1(i,1,n+3) {
            E[i].clear();
            color[i] = 0;
            visited[i] = false;
        }
	}
	return 0;
}
