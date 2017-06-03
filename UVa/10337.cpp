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

int n;
int data[10][1005];
int dp[10][1005];
int res = 1E9;

/*void recur(int r,int c,int ans) {
	if (r==9 && c==n) {
		res = min(res,ans);
		return;
	}
	if (c>=n || r>=10 || r<0) return;
	
	recur(r-1,c+1,ans+60-data[r][c]);
	recur(r,c+1,ans+30-data[r][c]);
	recur(r+1,c+1,ans+20-data[r][c]);
}*/

int recur(int r,int c) {
	if (r==9 && c==n) {
		return 0; //part te aow pai cal ans return recur({})
	}
	if (c>=n || r>=10 || r<0) return 1E9; //part te tua te working mai ok return antians
	
	if (dp[r][c]!=-1) return dp[r][c];
	
	return dp[r][c] = min(recur(r-1,c+1)+60-data[r][c],
	min(recur(r,c+1)+30-data[r][c],
	recur(r+1,c+1)+20-data[r][c]));
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int _ = 1;
	int t; cin>>t; while(t--) {
		memset(dp,-1,sizeof(dp));
		res = 1E9;
		scanf("%d",&n);
		n /= 100;
		for1(i,0,10) {
			for1(j,0,n) {
				scanf("%d",&data[i][j]);
			}
		}
		
		//recur(9,0,0);
		
		res = recur(9,0);
		
		printf("%d\n\n",res);
		
		_++;
	}
	return 0;
}
