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

vector<int> E[500005];
bool cy[500005];
bool visited[500005];
int dp[500005];
int cycleroot;

//docycle return root of cycle (point that revisited)
int docycle(int c,int p) {
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!visited[ne]) {
            visited[ne] = true;
            int cyroot = docycle(ne,c);
            if (cyroot=-1) {
                cy[c] = true;
                if (c == cyroot) {
                    cycleroot = cyroot;
                    return -1;
                } else return cyroot;
            }
        } else if (ne!=p) {
            cy[c] = true;
            return ne;
        }
    }
    return -1;
}

int dfs(int c) {
    int res = 1;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!visited[ne]) {
            visited[ne] = true;
            int sub = dfs(ne);
            if (!cy[ne]) {
                res += sub;
            } else {
                if (!cy[c]) {
                    res += sub;
                }
            }
        }
    }
    if (c==cycleroot) {
        for1(i,1,n+1) {
            if (cy[i] && i!=c) {
                res+=dp[i];
            }
        }
    }
    dp[c] = res;
    return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n>>m;
    for1(i,0,n) {
        int s,e; scanf("%d%d",&s,&e);
        E[s].push_back(e);
        E[e].push_back(s);
    }

    visited[m] = true;
    docycle(m,-1);

    /*for1(i,1,n+1) {
        if (cy[i]) {
            cerr<<i<<' ';
        }
    }*/

    fill(visited,visited+n+5,false);
    visited[m] = true;
    dfs(m);

    int currmax = -1E9;
    int maxi = -1;
    for1(i,1,n+1) {
        if (i!=m) {
            if (dp[i]>currmax) {
                currmax = dp[i];
                maxi = i;
            }
        }
    }
    printf("%d\n%d",maxi,currmax-1);
	return 0;
}
