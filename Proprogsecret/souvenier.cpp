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

int m,n;

vector<vector<int>> data;
int dp[25][205];

int recur(int pos,int want) { //recur[pos][want] = max(buy item from shop 0...pos (all shop) not exceed want)
	if (want < 0) return -1E9; //break law return antians
	if (pos<0) { //not break law but out of bound return recur({})
		return 0;
	}
	
	if (dp[pos][want]!=-1) return dp[pos][want];

	int res = -1E9;
	for1(i,0,data[pos].size()) {
		res = max(res,recur(pos-1,want-data[pos][i])+data[pos][i]);
	}
	return dp[pos][want] = res;
	
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; while(t--) {
		scanf("%d%d",&m,&n);
		data.resize(n);
		for1(i,0,n) {
			int x; scanf("%d",&x);
			data[i].resize(x);
			for1(j,0,x) scanf("%d",&data[i][j]);
		}
		
		memset(dp,-1,sizeof(dp));
		int res = recur(n-1,m);
		if (res>0) {
			printf("%d\n",res);
		} else {
			printf("no solution\n");
		}
		
		data.clear();
		
	}
	return 0;
}
