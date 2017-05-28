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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; cin>>nr>>nc;
    char data[nr+5][nc+5];
    for1(i,0,nr) scanf("%s",data[i]);
    int sr,sc,er,ec; cin>>sr>>sc>>er>>ec;
    sr--; sc--; er--; ec--;

    int dist[1005][1005];
    for1(i,0,1005) {
        for1(j,0,1005) dist[i][j] = 1E9;
    }
    queue<pii> q;
    q.push(mp(sr,sc));
    dist[sr][sc] = 0;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        int dr[] = {2,2,-2,-2,1,-1,1,-1};
        int dc[] = {1,-1,1,-1,2,2,-2,-2};
        for1(i,0,8) {
            int ner = cr + dr[i];
            int nec = cc + dc[i];
            if (ner>=0&&nec>=0&&ner<nr&&nec<nc&&dist[ner][nec]==1E9&&data[ner][nec]=='.') {
                dist[ner][nec] = dist[cr][cc]+1;
                q.push(mp(ner,nec));
            }
        }
    }

    if (dist[er][ec]==1E9) cout<<-1; else
    cout<<dist[er][ec];

	return 0;
}
