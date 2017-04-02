#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<vector<char>> data;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc;
    while (cin>>nr>>nc,nr!=0) {
        data.resize(nr,vector<char>(nc));
        for1(i,0,nr) for1(j,0,nc) cin>>data[i][j];

        ll res = 0;

        //bfs start (0,0)
        queue<pii> q;
        q.push(mp(0,0));
        bool visited[nr][nc];
        for1(i,0,nr) for1(j,0,nc) visited[i][j] = false;
        visited[0][0] = true;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dr[4] = {0,0,1,-1};
            int dc[4] = {1,-1,0,0};
            for1(i,0,4) {
                int nextr = r+dr[i];
                int nextc = c+dc[i];
                if (nextr>=0 && nextr<nr && nextc>=0 && nextc<nc && !visited[nextr][nextc]) {
                    if (data[nextr][nextc]=='.') {
                        q.push(mp(nextr,nextc));
                        visited[nextr][nextc] = true;
                    } else if (data[nextr][nextc]=='H') {
                        res++;
                    }
                }
            }
        }

        cout<<res<<endl;

        data.clear();
    }


	return 0;
}
