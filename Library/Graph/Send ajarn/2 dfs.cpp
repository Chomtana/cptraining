#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


map<int,vector<int>> E;
map<int,bool> visited;

void dfs(int curr) {
    visited[curr] = true;
    cout<<curr<<' ';
    for1(i,0,E[curr].size()) {
        int next = E[curr][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;

    for1(i,0,n) {
        int s,e; cin>>s>>e;
        E[s].push_back(e);
        E[e].push_back(s);
    }

    while (true) {
        int start; cin>>start;
        dfs(start);
        cout<<endl;
        visited.clear();
    }


	return 0;
}


/*
14
1 2
1 3
2 4
2 5
4 8
4 9
5 10
5 11
3 6
3 7
6 12
6 13
7 14
7 15
*/
