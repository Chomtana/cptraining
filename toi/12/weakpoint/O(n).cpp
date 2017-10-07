/**
Theorem: simple connected graph that has n node , m edge will has m-(n-1) cycle
            then if it has n node , n edge it will has n-(n-1) = 1 cycle

This problem can be solved by find that 1 cycle and check that if node is in same cycle don't add (only do next but don't add return value)
*/

#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(a,b,c) for(int (a)=(b);((b)<(c)?(a)<(c):(a)>=(c));(a)+=((b)<(c)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,s;
vector<vector<int>> E(500005);
bool visited[500005];
bool cycle[500005]; //exclude root of cycle because root of cycle need to add number of node in cycle
int cycleroot = 0;
int dp[500005];

int scan(int c,int p) { //scan cycle
    //if want check next visited? -> not compact
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if(visited[ne]) {
            if (ne!=p) {
                cycle[c] = true;
                return ne;
            }
        } else {
            visited[ne] = true;
            int x = scan(ne,c);
            if(x!=-1) {
                if (c!=x) {
                    cycle[c] = true;
                    return x;
                } else {
                    cycleroot = c;
                    return -1;
                }
            }
        }
    }

    return -1;
}

int dfs(int c) {
    int res = 0;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if(!visited[ne]) {
            visited[ne] = true;
            int x = dfs(ne);
            x++;
            if (cycle[c]) {
                if (!cycle[ne]) res+=x;
            } else {
                if (c==cycleroot) {
                    if (!cycle[ne]) res+=x;
                } else {
                    res += x;
                }
            }
        }
    }
    if (c==cycleroot) {
        for1(i,1,n+1) {
            if (cycle[i]) {
                res += dp[i]+1;
            }
        }
    }
    return dp[c] = res;
}


int main() {
    cin>>n>>s;
    for1(i,0,n) {
        int ss,ee; scanf("%d%d",&ss,&ee);
        E[ss].pb(ee);
        E[ee].pb(ss);
    }

    visited[s] = true;
    scan(s,-1);

    //for1(i,1,n+1) if(cycle[i]) cerr<<i<<' ';

    memset(visited,false,sizeof(visited));

    visited[s] = true;
    dfs(s);

    //for1(i,1,n+1) cerr<<dp[i]<<' ';

    int currmax = -1;
    int maxi = 0;
    for1(i,1,n+1) {
        if(i==s) continue;
        if (dp[i]>currmax) {
            currmax = dp[i];
            maxi = i;
        }
    }

    cout<<maxi<<endl<<currmax;
    return 0;
}
