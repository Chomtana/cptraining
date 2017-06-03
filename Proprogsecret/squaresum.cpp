//constructive version

#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(a,b,c) for(int (a)=(b);((b)<(c)?(a)<(c):(a)>=(c));a+=((b)<(c)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n;

int dp[10005][105];

int recur(int sum,int last) {
    if(sum<0) return 1E9;
    if (sum==0) {
        return 0;
    }
    
    if (dp[sum][last]!=-1) return dp[sum][last];
    
    int res = 1E9;
    for1(i,last,n+1) {
        if (sum-i*i<0) break;
        res = min(res,recur(sum-i*i,i)+1);
    }

    return dp[sum][last] = res;
}

int main() {
    memset(dp,-1,sizeof(dp));
    int t; cin>>t; while(t--) {
        scanf("%d",&n);
        printf("%d\n",recur(n,1));
    }
    return 0;
}
 