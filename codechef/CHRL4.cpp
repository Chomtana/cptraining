#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define m 1000000007

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	ll n,k; cin>>n>>k;
	ll data[n];
	for1(i,0,n) cin>>data[i];
	ll dp[n]; //dp[i] = ans [0,i] include i
	ll mcount[n]; //realdp[i]=2*m+5 -> dp[i]=5 mcount[i]=2
	for1(i,0,n) dp[i] = 1000000000000000;
	dp[0]=data[0]; //base case
	for1(i,1,n) {
		for1(j,0,i) {
			dp[i] = min(dp[i],dp[j]*data[i]);
		}
		//mcount[i] = dp[i]/m;
		dp[i] %= m;
	}
 	return 0;
}
