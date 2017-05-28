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
vector<vector<int>> Et;
vector<int> T;
vector<bool> visited;
vector<int> G; //count of scc in each group
int cg = 0;
int ct = 0;

void ksrj(int c) {
    if(visited[c]) return;
    visited[c] = true;

    ct++;
    for1(i,0,Et[c].size()) ksrj(Et[c][i]);
    T[c] = ct++;
}

void engroup(int c) {
    if (visited[c]) return;
    visited[c] = true;

    G[cg]++;
    for1(i,0,E[c].size()) engroup(E[c][i]);
}

void scc() {
    for1(i,0,n) {
        if(!visited[i]) ksrj(i);
    }

    for1(i,0,n) visited[i] = false;

    vector<pii> Ti;
    Ti.reserve(n);
    for1(i,0,n) {
        Ti.push_back(mp(T[i],i));
    }

    sort(all(Ti),greater<pii>());

    for1(i,0,n) {
        int node = Ti[i].second;
        if (!visited[node]) {
            G.push_back(0);
            engroup(node);
            cg++;
        }
    }

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;

    E.resize(n);
    Et.resize(n);
    T.resize(n);
    visited.resize(n,false);

    for1(i,0,n) {
        int m; scanf("%d",&m);
        for1(j,0,m) {
            int e; scanf("%d",&e);
            E[i].push_back(e);
            Et[e].push_back(i);
        }
    }

    scc();

    sort(all(G));
    for1(i,0,G.size()) printf("%d ",G[i]);

    E.clear();
    Et.clear();
    T.clear();
    visited.clear();
	return 0;
}
