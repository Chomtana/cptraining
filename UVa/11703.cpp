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

int dp[1000005];

int recur(int x) {
	if (x==0) return 1;
	if (dp[x]!=-1) return dp[x];
	return dp[x] = (recur(x-sqrt(x))+recur(log(x))+recur(x*sin(x)*sin(x)))%1000000;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n;
	memset(dp,-1,sizeof(dp));
	while (cin>>n,n!=-1) {
		cout<<recur(n)<<endl;
	}
	return 0;
}
