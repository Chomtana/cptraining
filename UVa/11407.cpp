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

int dp[10005];

int recur(int n) {
    if (n==0) return 0;
    if (dp[n]!=-1) return dp[n];
    int res = 1E9;
    for1(i,1,n+1) {
        if (i*i>n) break;
        res = min(res,recur(n-i*i));
    }
    return dp[n] = res+1;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	memset(dp,-1,sizeof(dp));
    int t; cin>>t; while(t--) {
        int n; scanf("%d",&n);
        printf("%d\n",recur(n));
    }
	return 0;
}
