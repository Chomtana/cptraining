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

int start,endd;

stack<int> res;

bool dfs(int curr) {
    visited[curr] = true;
    if (curr==endd) {
        res.push(curr);
        return true;
    }
    for1(i,0,E[curr].size()) {
        int next = E[curr][i];
        if (!visited[next]) if(dfs(next)) {res.push(curr); return true;}
    }
    return false;
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

    cin>>start>>endd;

    //cout<<"DFS(0) or BFS(1) mode : "; int mode; cin>>mode;

    //if (mode==0) {
        //dfs
        //while (true) {
            //int start; cin>>start;
            visited.resize(nv+1,false);
            //for1(i,1,nv+1) {
                //if (!visited[i]) {
                    dfs(start);
                    //cout<<endl;
                //}
            //}
            visited.clear();
            while (!res.empty()) {
                cout<<res.top()<<' ';
                res.pop();
            }
        //}
    /*} else {
        //bfs is too hard to do this problem
        //while (true) {
            //int start; cin>>start;
            visited.resize(nv+1,false);
            //for1(i,1,nv+1) {
                //if (!visited[i]) {
                    queue<int> q;
                    q.push(start);
                    visited[start] = true;
                    while (!q.empty()) {
                        int curr = q.front();
                        q.pop();
                        cout<<curr<< ' ';
                        if (curr==endd) break;
                        for1(j,0,E[curr].size()) {
                            int next = E[curr][j];
                            if (!visited[next]) {
                                q.push(next);
                                visited[next] = true;
                            }
                        }
                    }
                    //cout<<endl;
                //}
            //}
            visited.clear();

        //}
    }*/

	return 0;
}


/*
16 15
3 4
2 3
1 2
1 5
5 6
6 7
7 11
11 10
11 15
15 16
16 12
12 8
10 14
14 13
13 9
3 14
*/
