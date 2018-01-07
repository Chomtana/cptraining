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

int n,k;
int dp[55][55];
const int mod = 2009;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    for1(i,1,50+1) {
        dp[i][0] = 1;
        dp[i][i-1] = 1;
    }
    for1(i,2,50+1) {
        for1(j,1,i-1) {
            dp[i][j] = 1;
            for1(x,0,j+1) {
                dp[i][j] += dp[i-1][x];
            }
            dp[i][j] %= mod;
        }
    }
	int t; cin>>t; while(t--) {
        cin>>n>>k;

        cout<<dp[n][k]<<endl;
	}
	return 0;
}
