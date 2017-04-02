#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<vector<int>> E;

vector<bool> visited;

void dfs(int curr) {
    visited[curr] = true;
    cout<<curr<<' ';
    for1(i,0,E[curr].size()) {
        int next = E[curr][i];
        if (!visited[next]) dfs(next);
    }
}


int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int nv,ne; cin>>nv>>ne;
	E.resize(nv+1);

    for1(i,0,ne) {
        int s,e; cin>>s>>e;
        E[s].push_back(e);
        E[e].push_back(s);
    }

    cout<<"DFS(0) or BFS(1) mode : "; int mode; cin>>mode;

    if (mode==0) {
        //dfs
        //while (true) {
            //int start; cin>>start;
            visited.resize(nv+1,false);
            for1(i,1,nv+1) {
                if (!visited[i]) {
                    dfs(i);
                    cout<<endl;
                }
            }
            visited.clear();
        //}
    } else {
        //bfs
        //while (true) {
            //int start; cin>>start;
            visited.resize(nv+1,false);
            for1(i,1,nv+1) {
                if (!visited[i]) {
                    queue<int> q;
                    q.push(i);
                    visited[i] = true;
                    while (!q.empty()) {
                        int curr = q.front();
                        q.pop();
                        cout<<curr<< ' ';
                        for1(j,0,E[curr].size()) {
                            int next = E[curr][j];
                            if (!visited[next]) {
                                q.push(next);
                                visited[next] = true;
                            }
                        }
                    }
                    cout<<endl;
                }
            }
            visited.clear();

        //}
    }

	return 0;
}


/*
10 9
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
