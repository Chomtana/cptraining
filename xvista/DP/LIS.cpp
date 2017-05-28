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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    int data[n]; for1(i,0,n) scanf("%d",data+i);
    int dp[n]; //dp[i] = LIS [0,i] force end at i
    dp[0] = 1;
    for1(i,1,n) {
        dp[i] = 1;
        for1(j,0,i) {
            if (data[j]<=data[i]) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    cout<<*max_element(dp,dp+n); //want end at any point -> if dp force end must select from all dp
	return 0;
}
