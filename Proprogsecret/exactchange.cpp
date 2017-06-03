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
int data[105];
pii dp[105][10005];

pii recur(int i,int j) {
	if (j>=m) return mp(0,0);
	if (i>=n) {
		if (j<m) return mp(1E9,1E9); else return mp(0,0);
	}
	
	if (dp[i][j].first!=-1) return dp[i][j];

	pii notchoose = recur(i+1,j);
	pii choose = recur(i+1,j+data[i]);
	choose.first += data[i];
	choose.second++;
	
	if (choose.first < notchoose.first) {
		return dp[i][j] = choose;
	} else if (notchoose.first < choose.first) {
		return dp[i][j] = notchoose;
	} else {
		if (choose.second < notchoose.second) return dp[i][j] = choose; else return dp[i][j] = notchoose;
	}
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t;
	while (t--) {
		scanf("%d%d",&m,&n);
		for1(i,0,n) {
			scanf("%d",data+i);
		}
		
		for1(i,0,n+5) for1(j,0,m+5) dp[i][j] = mp(-1,-1);
		pii res = recur(0,0);
		printf("%d %d\n",res.first,res.second);
	}
	return 0;
}
