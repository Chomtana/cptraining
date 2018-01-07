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

vector<int> E[100005];
bool visited[100005];
int n;

pii ma1[100005];
pii ma2[100005];

int dfs(int c,int p) {
    int sum = 1;

    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!visited[ne]) {
            visited[ne] = true;
            int neres = dfs(ne,c);
            sum += neres;
            //bug : if first mang most -> fail
            if (neres>ma1[c].first) {
                ma2[c] = ma1[c];
                ma1[c] = {neres,ne};
            } else {
                if (neres>ma2[c].first) {
                    ma2[c] = {neres,ne};
                }
            }
        }
    }

    int rootres = n-sum;
    if (rootres > ma1[c].first) {
        ma2[c] = ma1[c];
        ma1[c] = {rootres,p};
    } else {
        if (rootres>ma2[c].first) {
            ma2[c] = {rootres,p};
        }
    }

    return sum;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    for1(i,0,n-1) {
        int s,e; scanf("%d%d",&s,&e);
        E[s].push_back(e);
        E[e].push_back(s);
    }

    visited[1] = true;
    dfs(1,-1);

    ll res = 0;

    for1(s,1,n+1) {
        for1(j,0,E[s].size()) {
            int e = E[s][j];

            ll ress = 0;
            ll rese = 0;

            if (ma1[s].second!=e) {
                ress = ma1[s].first;
            } else {
                ress = ma2[s].first;
            }

            if (ma1[e].second!=s) {
                rese = ma1[e].first;
            } else {
                rese = ma2[e].first;
            }

            res = max(res,ress*rese);
        }
    }

    cout<<res;
	return 0;
}
