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

int data[105][105];
int dp[105][105];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    for1(i,1,n+1) {
        for1(j,1,i+1) {
            scanf("%d",&data[i][j]);
        }
    }

    dp[1][1] = data[1][1];

    //<2,1> = <1,1>,<1,0>
    for1(i,2,n+1) {
        for1(j,1,i+1) {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + data[i][j];
        }
    }

    int currmax = 0;
    for1(i,1,n+1) {
        currmax = max(currmax,dp[n][i]);
    }
    cout<<currmax;
	return 0;
}
