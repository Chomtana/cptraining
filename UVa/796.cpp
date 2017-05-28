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
vector<int> T;
vector<int> L;
vector<bool> visited;
vector<vector<bool>> B;
int t = 0;

void dfs(int c,int p) {
    int nec = 0;

    T[c] = L[c] = t++;

    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!visited[ne]) {
            visited[ne] = true;
            nec++;
            dfs(ne,c);
            if (T[c]<L[ne]) {
                B[c][ne] = true;
            }
            if (ne!=p) L[c] = min(L[c],L[ne]);
        } else {
            if (ne!=p) L[c] = min(L[c],T[ne]);
        }
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n;
    while (cin>>n) {
        if (n==0) {
            printf("%d critical links\n\n",0);
            continue;
        }

        E.resize(n);
        T.resize(n);
        L.resize(n);
        visited.resize(n,false);
        B.resize(n,vector<bool>(n,false));
        t = 0;

        for1(i,0,n) {
            int s,m; scanf("%d (%d)",&s,&m);
            for1(j,0,m) {
                int e; scanf("%d",&e);
                E[s].push_back(e);
                E[e].push_back(s);
            }
        }

        for1(i,0,n) {
            if (!visited[i]) dfs(i,-1);
        }

        /*for1(i,0,n) {
            cerr<<T[i]<<' '<<L[i]<<endl;
        }*/

        vector<pii> res;

        for1(i,0,n) {
            for1(j,0,n) {
                if(B[i][j]) {
                    res.push_back(mp(min(i,j),max(i,j)));
                }
            }
        }

        sort(all(res));

        printf("%d critical links\n",res.size());
        for1(i,0,res.size()) {
            printf("%d - %d\n",res[i].first,res[i].second);
        }
        printf("\n");

        E.clear();
        T.clear();
        L.clear();
        visited.clear();
        B.clear();
    }
	return 0;
}
