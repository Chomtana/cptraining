#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;
    map<int,vector<int>> E;
    for1(i,0,n) {
        int s,e; cin>>s>>e;
        E[s].push_back(e);
        E[e].push_back(s);
    }

    while (true) {
        int start; cin>>start;
        map<int,bool> visited;
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            cout<<curr<<' ';
            for1(i,0,E[curr].size()) {
                int next = E[curr][i];
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        cout<<endl;
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
