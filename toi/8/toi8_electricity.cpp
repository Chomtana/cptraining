#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll data[500001];
ll dp[500001];

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n,k; scanf("%d %d",&n,&k);

    for1(i,0,n) scanf("%lld",data+i);

    multiset<ll> mingetter;
    mingetter.insert(data[0]);

    //cout<<data[0]<<endl;


    dp[0] = data[0];
    for1(i,1,n) {
        ll currmin = 1E9;

        currmin = *(mingetter.begin());
        dp[i] = currmin + data[i];
        if (i<k) {
            mingetter.insert(dp[i]);
        } else {
            mingetter.erase(mingetter.find(dp[i-k]));
            mingetter.insert(dp[i]);
        }
        //cerr<<i<<' '<<currmin<<' '<<*mingetter.begin()<<endl;

        /*for(int j = i-1;j>=0 && i-j<=k;j--) {
            currmin = min(currmin,dp[j]);
        }*/


    }

    printf("%lld",dp[n-1]);
	return 0;
}
