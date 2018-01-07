/*
TASK:o59_oct_c2_triangle
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#define long long long
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
using namespace std;

const long mod = 1e9+7ll;
long dp[105][105];
int main() {
	// freopen("r", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			if(i == 0 || j == 0) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			for(int k = 1; k <= m; ++k) {
				if(i-k-1 >= 0) dp[i][j] += dp[i-k-1][j-1];
				if(j-k-1 >= 0) dp[i][j] += dp[i-1][j-k-1];
			}
			dp[i][j] = (dp[i][j] + mod)%mod;
		}
	}
	for1(i,0,n+1) {
        for1(j,0,n+1) {
            cerr<<dp[i][j]<<' ';
        }
        cerr<<endl;
	}
	printf("%lld\n", (dp[n][n]+mod-1)%mod);
}
