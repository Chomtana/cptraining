#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<vector<int>> E;
bool visited[500005];

int currse;

int n,root;

int res = 0;

void docount(int curr) {
    if (visited[curr]) return;
    visited[curr] = true;
    res++;

    for1(i,0,E[curr].size()) {
        int ne = E[curr][i];
        docount(ne);
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>root;
    E.resize(n+5);

    for1(i,0,n) {
        int s,e,w; scanf("%d%d",&s,&e);
        E[s].push_back(e);
        E[e].push_back(s);
    }

    int currmax = 0;
    int maxi = 0;

    for1(i,1,n+1) {
        if (i==root) continue;
        currse = i;
        for1(j,0,n+1) visited[j] = false;
        res = 0;
        visited[i] = true;
        docount(root);
        res = n-res-1;
        if (res>currmax) {
            currmax = res;
            maxi = i;
        }
    }

    cout<<maxi<<endl<<currmax;
	return 0;
}
