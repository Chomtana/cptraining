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

int nr,nc;
bool data[55][55];
ll dp[55][55];

ll recur(int r,int c) {
    if(r==nr-1&&c==nc-1) return 1;
    if(r<0||c<0||r>=nr||c>=nc) return 0;
    if(dp[r][c]!=-1) return dp[r][c];
    int dr[] = {1,0};
    int dc[] = {0,1};
    ll res = 0;
    for1(i,0,2) {
        int ner = r+dr[i];
        int nec = c+dc[i];
        if (!data[ner][nec]) {
            res += recur(ner,nec);
        }
    }
    return dp[r][c]= res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>nr>>nc;
    int m; cin>>m;
    memset(dp,-1,sizeof(dp));
    while(m--) {
        int r,c; scanf("%d%d",&r,&c);
        r--;c--;data[r][c]=true;
    }

    cout<<recur(0,0);
	return 0;
}
