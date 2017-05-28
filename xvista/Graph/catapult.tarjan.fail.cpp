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

int n;
vector<vector<int>> E;
vector<int> T;
vector<int> L;
vector<bool> visited;
//vector<bool> inst;
int ct = 0;
vector<int> G;
int cg = 0;
//stack<int> st;

void tarjan(int c,int p) {
    T[c] = L[c] = ct++;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!visited[ne]) {
            visited[ne] = true;
            tarjan(ne,c);

            if (ne!=p) L[c] = min(L[c],L[ne]);
        } else {
            if (ne!=p) L[c] = min(L[c],T[ne]);
        }
    }
}

void engroup(int c) {
    if (visited[c]) return;
    visited[c] = true;

    G[cg]++;

    for1(i,0,E[c].size()) engroup(E[c][i]);
}

int scc() {
    for1(i,0,n) {
        if(!visited[i]) {
            visited[i] = true;
            tarjan(i,-1);
        }
    }

    for1(i,0,n) visited[i] = false;

    for1(i,0,n) {
        if(T[i]==L[i] && !visited[i]) {
            G.push_back(0);
            engroup(i);
            cg++;
        }
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    E.resize(n);
    T.resize(n);
    L.resize(n);
    visited.resize(n,false);
    //inst.resize(n,false);

    for1(i,0,n) {
        int m; scanf("%d",&m);
        for1(j,0,m) {
            int e; scanf("%d",&e);
            E[i].push_back(e);
        }
    }

    scc();

    sort(all(G));
    for1(i,0,G.size()) {
        printf("%d ",G[i]);
    }

    E.clear();
    T.clear();
    L.clear();
    visited.clear();
    //inst.clear();
	return 0;
}
