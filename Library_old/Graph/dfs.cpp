#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


map<int,vector<int>> E; //input kuan teen chai tua nee , ta mai kuan teem chai vector<vector<int>>
map<int,bool> visited; //input kuan teen chai tua nee , ta mai kuan teem chai vector<bool>

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
        visited.clear(); //if you declear as global you must reset
    }


	return 0;
}


/*
9
1 5
5 4
2 6
6 3
5 6
7 8
7 9
8 9
7 10
*/
