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
int n;
vector<int> T;
vector<bool> visited;
int ct = 0;

void ksrj(int c) { //kosaraju's time dfs
    if (visited[c]) return;
    ct++;
    visited[c] = true;
    for1(i,0,E[c].size()) {
        ksrj(E[c][i]);
    }
    T[c] = ct++;
}

void toposort() {
    for1(i,0,n) {
        if (!visited[i]) ksrj(i);
    }

    vector<pii> Ti(n);
    for1(i,0,n) {
        Ti[i].first = T[i];
        Ti[i].second = i;
    }
    sort(all(Ti),greater<pii>());

    for1(i,0,n) {
        printf("%d ",Ti[i].second);
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
     cin>>n;
    E.resize(n);
    visited.resize(n);
    T.resize(n);
    for1(i,0,n) {
        int nn; scanf("%d",&nn);
        while (nn--) {
            int x; scanf("%d",&x);
            E[x].push_back(i);
        }
    }

    toposort();
	return 0;
}
