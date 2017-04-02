#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp(a,b,c) make_pair(make_pair(a,b),c)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef vector<int> vi;

#define macro(x,y,z)    if (!runned[x][y]) { \
                            q.push(mp(x,y,z)); \
                            if (visited[x][y]) { \
                                printf("%d\n%d %d",z,x,y); return 0; \
                            } \
                            visited[x][y] = true; \
                        }

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; scanf("%d %d",&nr,&nc);
    char data[nr+2][nc+2];
    bool left[nr+2][nc+2];
    bool up[nr+2][nc+2];
    for1(i,0,nr+2) {
        for1(j,0,nc+2) {
            data[i][j] = 'N';
            left[i][j] = false;
            up[i][j] = false;
        }
    }
    for1(i,1,nr+1) {
        for1(j,1,nc+1) {
            scanf(" %c",&data[i][j]);
        }
    }


    for1(i,1,nr+1) {
        for1(j,1,nc+1) {
            switch (data[i][j]) {
            case 'B':
                left[i][j+1] = true;
                up[i+1][j] = true;
                break;
            case 'R':
                left[i][j+1] = true;
                break;
            case 'D':
                //q.push(mp(r+1,c,t+1));
                up[i+1][j] = true;
                break;
            }
        }
    }

    /*for1(i,0,nr+2) {
        for1(j,0,nc+2) {
            cout<<left[i][j]<<' ';
        }
        cout<<endl;
    }*/

    queue<piii> q;
    q.push(mp(1,1,1));
    bool visited[nr+2][nc+2];
    bool runned[nr+2][nc+2];
    for1(i,0,nr+2) {
        for1(j,0,nc+2) {
            visited[i][j] = false;
            runned[i][j] = false;
        }
    }
    visited[1][1] = true;
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        runned[r][c] = true;
        switch (data[r][c]) {
        case 'B':
            /*q.push(mp(r+1,c,t+1));
            if (visited[r+1][c]) {
                printf("%d\n%d %d",t+1,r+1,c); return 0;
            }
            q.push(mp(r,c+1,t+1));*/
            macro(r+1,c,t+1)
            macro(r,c+1,t+1)
            break;
        case 'R':
            //q.push(mp(r,c+1,t+1));
            macro(r,c+1,t+1)
            break;
        case 'D':
            //q.push(mp(r+1,c,t+1));
            macro(r+1,c,t+1)
            break;
        }

        if (up[r][c]) {
            macro(r-1,c,t+1)
        }

        if (left[r][c]) {
            macro(r,c-1,t+1)
        }

    }
	return 0;
}
