#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; cin>>nr>>nc;
    char data[nr][nc+1];
    cin.ignore();
    for1(i,0,nr) {
        scanf("%s",data+i);
    }

    vector<vector<bool>> visited(nr,vector<bool>(nc,false));

    int res = 0;

    for1(i,0,nr) {
        for1(j,0,nc) {
            if (!visited[i][j] && data[i][j]=='.') {
                //int count = 0;
                queue<pii> q;
                q.push(mp(i,j));
                visited[i][j] = true;
                while (!q.empty()) {
                    int currr = q.front().first;
                    int currc = q.front().second;

                    q.pop();

                    int dr[] = {0,0,1,-1};
                    int dc[] = {1,-1,0,0};

                    bool hassh = false;

                    for1(k,0,4) {
                        int nextr = currr+dr[k];
                        int nextc = currc+dc[k];
                        if (nextr>=0&&nextr<nr and nextc<nc and nextc>=0 and !visited[nextr][nextc]) {
                            if (data[nextr][nextc]=='.') {
                                q.push(mp(nextr,nextc));
                                visited[nextr][nextc] = true;
                            } else if (data[nextr][nextc]=='#') {
                                hassh = true;
                            }
                        }
                    }

                    if (!hassh) data[currr][currc] = '@';
                }

                //res = max(res,count);
            }
        }
    }

    visited.clear();
    visited.resize(nr,vector<bool>(nc,false));

    for1(i,0,nr) {
        for1(j,0,nc) {
            if (!visited[i][j] && data[i][j]=='@') {
                int count = 0;
                queue<pii> q;
                q.push(mp(i,j));
                visited[i][j] = true;
                while (!q.empty()) {
                    int currr = q.front().first;
                    int currc = q.front().second;

                    q.pop();

                    int dr[] = {0,0,1,-1};
                    int dc[] = {1,-1,0,0};

                    bool hassh = false;

                    for1(k,0,4) {
                        int nextr = currr+dr[k];
                        int nextc = currc+dc[k];
                        if (nextr>=0&&nextr<nr and nextc<nc and nextc>=0 and !visited[nextr][nextc]) {
                            if (data[nextr][nextc]=='@') {
                                q.push(mp(nextr,nextc));
                                visited[nextr][nextc] = true;
                            } else if (data[nextr][nextc]=='#') {
                                hassh = true;
                            }
                        }
                    }

                    count++;
                }

                res = max(res,count);
            }
        }
    }

    cout<<res;
	return 0;
}
