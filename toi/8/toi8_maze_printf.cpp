#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc,sr,sc,er,ec; scanf("%d %d %d %d %d %d",&nr,&nc,&sr,&sc,&er,&ec);
    sr--; sc--; er--; ec--;
    int data[nr][nc]; for1(i,0,nr) for1(j,0,nc) scanf("%d",&data[i][j]);
    int dist1[nr][nc]; for1(i,0,nr) for1(j,0,nc) dist1[i][j] = 1E9;
    int dist2[nr][nc]; for1(i,0,nr) for1(j,0,nc) dist2[i][j] = 1E9;
    dist1[sr][sc] = 0;
    dist2[er][ec] = 0;

    queue<pii> q;
    q.push(mp(sr,sc));
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        for1(i,0,4) {
            int nextr = r+dr[i];
            int nextc = c+dc[i];
            if (nextr>=0 && nextr<nr && nextc>=0 && nextc<nc && dist1[nextr][nextc]==1E9 && data[nextr][nextc]==1) {
                q.push(mp(nextr,nextc));
                dist1[nextr][nextc] = dist1[r][c]+1;
            }
        }
    }

    q.push(mp(er,ec));
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        for1(i,0,4) {
            int nextr = r+dr[i];
            int nextc = c+dc[i];
            if (nextr>=0 && nextr<nr && nextc>=0 && nextc<nc && dist2[nextr][nextc]==1E9 && data[nextr][nextc]==1) {
                q.push(mp(nextr,nextc));
                dist2[nextr][nextc] = dist2[r][c]+1;
            }
        }
    }

    /*cerr<<endl;
    for1(i,0,nr) {
        for1(j,0,nc) {
            cerr<<(dist1[i][j]==1E9?0:dist1[i][j])<<' ';
        }
        cerr<<endl;
    }

    cerr<<endl;
    for1(i,0,nr) {
        for1(j,0,nc) {
            cerr<<(dist2[i][j]==1E9?0:dist2[i][j])<<' ';
        }
        cerr<<endl;
    }
    cerr<<endl;*/

    int bombcount = 0;
    int mindist = 1E9;
    for1(r,0,nr) {
        for1(c,0,nc) {
            int minfromstart = 1E8;
            int minfromend = 1E8;
            if (data[r][c] == 0) {
                int dr[4] = {0,0,1,-1};
                int dc[4] = {1,-1,0,0};
                for1(i,0,4) {
                    int nextr = r+dr[i];
                    int nextc = c+dc[i];
                    if (nextr<0 || nextr>=nr || nextc<0 || nextc>=nc) continue;
                    minfromstart = min(minfromstart,dist1[nextr][nextc]);
                    minfromend = min(minfromend,dist2[nextr][nextc]);
                }
                if (minfromstart<1E8 && minfromend<1E8 ) {
                    //cerr<<r<<' '<<c<<endl;
                    bombcount++;
                    mindist = min(mindist,minfromstart+minfromend+3);
                }
            }
        }
    }

    printf("%d\n%d",bombcount,mindist);
	return 0;
}
