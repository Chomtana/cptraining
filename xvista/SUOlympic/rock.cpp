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

int data[2005];
int dp[2005][2005]; //dp[i][j]

int recur(int i,int j) {
	if (i>j) return 0;
	
	if (dp[i][j]!=-1) return dp[i][j];
	
	return dp[i][j] = max(max(data[i]+recur(i+1,j-1),data[i]+recur(i+2,j)),max(data[j]+recur(i,j-2),data[j]+recur(i+1,j-1)));
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;
	for1(i,1,2*n+1) {
		scanf("%d",data+i);
	}
	
	memset(dp,-1,sizeof(dp));
	
	cout<<recur(1,2*n);
	return 0;
}
