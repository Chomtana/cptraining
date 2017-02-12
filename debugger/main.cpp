#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<vi> E;
vector<bool> visited;
vector<int> dp; //caching of dfs(s)

int currmax = 0;
int res = 0;

int dfs(int s) {
    //cerr<<s<<endl;
    visited[s] = true;
    int sum = 1;
    for1(i,0,E[s].size()) {
        int e = E[s][i];
        if (!visited[e]) {
            sum += dfs(e);
        }
    }
    return dp[s] = sum;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        cout<<"Case "<<_<<": ";
        int n; cin>>n;
        E.resize(n+1,vi());
        visited.resize(n+1);
        dp.resize(n+1,1E9);
        int root = 1E9;
        for1(i,0,n) {
            int s,e; cin>>s>>e;
            E[s].push_back(e);
            root = min(root,s);
        }


        //dfs(3);

        for1(i,1,n+1) {
            if (dp[i]==1E9) {
                fill(all(visited),false);
                dfs(i);
            }
        }

        //for1(i,0,dp.size()) cerr<<dp[i]<<' ';
        //cerr<<endl;

        int currmax = 0;
        int res = 0;
        for1(i,1,dp.size()) {
            if (dp[i]!=1E9 && dp[i]>currmax) {
                currmax=dp[i];
                res=i;
            }
        }

        cout<<res<<endl;

        E.clear();
        visited.clear();
        dp.clear();
        currmax = 0;
        res = 0;
    }
	return 0;
}
