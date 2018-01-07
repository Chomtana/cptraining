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
int dp[1005];
int dpbf[1005];
//(n,k) -> (n+1,k+1)+a , (n+1,k-1)+b : algortree
//dp[n][k] = min(dp[n-1][k-1]+a , dp[n-1][k+1]+b)

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; while(t--) {
        scanf("%d%d",&n,&k);
        fill(dp,dp+1005,1E9);
        for1(i,0,n) {
            int a,b; scanf("%d%d",&a,&b);
            if (i==0) {
                dp[1+300] = a;
                dp[-1+300] = b;
            } else {
                for1(j,-k+300-3,k+300+4) {
                    dpbf[j] = dp[j];
                }
                for1(j,-k+300,k+300+1) {
                    dp[j] = min(dpbf[j-1]+a,dpbf[j+1]+b);
                }
            }
        }

        int res = 1E9;
        for1(j,-k+300,k+300+1) {
            res = min(res,dp[j]);
        }
        printf("%d\n",res);

	}
	return 0;
}
