#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<vector<char>> data;
vector<vector<bool>> visited;
int nr,nc;
char need;

void dfs(int r,int c) {
    if (r<0 || c<0 || r>=nr || c>=nc) return;
    if (data[r][c]!=need) return;
    if (visited[r][c]) return;
    visited[r][c] = true;
    dfs(r-1,c);
    dfs(r+1,c);
    dfs(r,c-1);
    dfs(r,c+1);
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    while(cin>>nr>>nc) {
        data.resize(nr,vector<char>(nc));
        visited.resize(nr,vector<bool>(nc,false));
        for1(i,0,nr) for1(j,0,nc) cin>>data[i][j];
        int r,c; cin>>r>>c;
        need = data[r][c];
        dfs(r,c);
        int count = 0;
        for1(i,0,nr) for1(j,0,nc) {
            count += visited[i][j];
        }
        cout<<count;

        data.clear();
        visited.clear();
    }
	return 0;
}
