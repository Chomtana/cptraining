#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<vector<int>> data;
vector<vector<bool>> visited;

int nr,nc;

void dfs(int r,int c) {
    //cout<<r<<' '<<c<<endl;
    int dr[8] = {0,0,1,1,1,-1,-1,-1};
    int dc[8] = {1,-1,0,1,-1,0,1,-1};
    visited[r][c] = true;
    for1(i,0,8) {
        int nextr = r+dr[i];
        int nextc = c+dc[i];
        if (nextr>=0 && nextr<nr && nextc>=0 && nextc<nc && data[nextr][nextc]==1 && !visited[nextr][nextc]) {
            dfs(nextr,nextc);
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
         cin>>nr>>nc;
        data.resize(nr,vector<int>(nc,0));
        visited.resize(nr,vector<bool>(nc,false));
        for1(i,0,nr) {
            for1(j,0,nc) {
                cin>>data[i][j];
            }
        }

        int count = 0;

        for1(i,0,nr) {
            for1(j,0,nc) {
                if (!visited[i][j] && data[i][j] == 1) {
                    dfs(i,j);
                    count++;
                }
            }
        }

        cout<<count<<endl;

        data.clear();
        visited.clear();


    }
	return 0;
}
