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
vector<bool> visited;
vector<bool> A;
vector<vector<bool>> B;
vector<int> T;
vector<int> L;

int t = 0;

void dfs(int c,int p) { //c = curr , p = parent
    T[c] = t;
    L[c] = t;
    
    t++;
    
    int nec = 0;
    
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!visited[ne]) {
            visited[ne] = true;
            nec++;
            dfs(ne,c);
            if (T[c]<=L[ne] && p!=-1) {
                A[c] = true;
            }
            if (T[c]<L[ne]) {
                B[c][ne] = true;
            }
            if (ne!=p) L[c] = min(L[c],L[ne]);
        } else {
            if (ne!=p) L[c] = min(L[c],T[ne]);
        }
    }
    
    if (p==-1 && nec>1) A[c] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m; cin>>n>>m;
    E.resize(n);
    A.resize(n,false);
    visited.resize(n,false);
    B.resize(n,vector<bool>(n,false));
    T.resize(n);
    L.resize(n);
    
    for1(i,0,m) {
        int s,e; cin>>s>>e;
        E[s].push_back(e);
        E[e].push_back(s);
    }
    
    visited[0] = true;
    dfs(0,-1);

    int Ac = 0;
    for1(i,0,A.size()) {
        if (A[i]) Ac++;
    }
    cout<<Ac<<endl;
    for1(i,0,A.size()) if(A[i]) cout<<i<<' ';
    cout<<endl;
    
    int Bc = 0;
    for1(i,0,n) for1(j,0,n) Bc+=B[i][j];
    cout<<Bc<<endl;
    for1(i,0,n) {
        for1(j,0,n) if(B[i][j]) cout<<i<<' '<<j<<endl;
    }
    
    /*for1(i,0,n) {
        cout<<T[i]<<' ';
    }
    cout<<endl;
    for1(i,0,n) {
        cout<<L[i]<<' ';
    }*/
    
    E.clear();
    A.clear();
    B.clear();
    T.clear();
    L.clear();
    visited.clear();
	return 0;
}
