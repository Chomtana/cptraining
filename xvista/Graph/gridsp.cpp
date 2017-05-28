/**
grid graph -> undirected graph (only connect , no weight) -> use bfs to find shortest path
*/

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

char data[105][105];
int d[105][105]; //auto init to 0

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; cin>>nr>>nc;
    for1(i,0,nr) scanf("%s",data[i]);

    for1(i,0,nr) for1(j,0,nc) d[i][j] = 1E9;

    queue<pii> q;
    q.push(mp(0,0));
    d[0][0] = 0;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (cr==nr-1&&cc==nc-1) break;

        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};
        for1(i,0,4) {
            int ner = cr+dr[i];
            int nec = cc+dc[i];

            if (ner>=0&&nec>=0&&ner<nr&&nec<nc&&d[ner][nec]==1E9&&data[ner][nec]=='.') {
                d[ner][nec] = d[cr][cc]+1;
                q.push(mp(ner,nec));
            }
        }
    }

    if (d[nr-1][nc-1]==1E9) cout<<-1; else cout<<d[nr-1][nc-1];


	return 0;
}
