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
typedef pair<ll,int> pii;
typedef vector<int> vi;

pii data[10005];
int n,k;
int ok = 0;

ll dp[10005][(1<<8)+5];

ll recur(int curr,int a) {
    if (a==ok) return 0;

    if (dp[curr][a]!=-1) {
        return dp[curr][a];
    }

    ll res = 1E9;
    for1(i,curr,n) {
        res = min(res,recur(i+1,a|data[i].second)+data[i].first);
    }

    return dp[curr][a] = res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for1(i,0,k) {
        ok++;
        ok <<= 1;
    }
    ok >>= 1;
    for1(i,0,n) {
        ll w; scanf("%lld",&w);
        int a = 0;
        for1(j,0,k) {
            int x; scanf("%d",&x);
            a <<= 1;
            a += x;
        }
        data[i] = mp(w,a);
    }

    cout<<recur(0,0);
	return 0;
}
