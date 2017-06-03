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
typedef pair<int,pii> piii;
typedef vector<int> vi;

//piii El[];
int dp[105][105];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int _ = 1;
	int n,m,q; while(cin>>n>>m>>q,n!=0) {
		//memset(dp,1E9,sizeof(dp));
		for1(i,0,105) {
			for1(j,0,105) {
				dp[i][j] = 1E9;
			}
		}
		
		for1(i,0,m) {
			int s,e,w; scanf("%d%d%d",&s,&e,&w);
			dp[s][e] = w;
			dp[e][s] = w;
		}
		
		for1(i,0,105) {
			dp[i][i] = 0;
		}
		
		for1(k,1,n+1) {
			for1(i,1,n+1) {
				for1(j,1,n+1) {
					dp[i][j] = min(dp[i][j],max(dp[i][k],dp[k][j]));
					//dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		
		if(_>1) printf("\n");
		
		printf("Case #%d\n",_++);
		
		while(q--) {
			int s,e; scanf("%d%d",&s,&e);
			if (dp[s][e]<1E9) {
				printf("%d\n",dp[s][e]);
			} else {
				printf("no path\n");
			}
		}
	}
	return 0;
}
