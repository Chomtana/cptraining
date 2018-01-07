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

int n,m,k,l;
pii A[50005];
pii B[50005];
set<pii> ban;
ll dp[50005][3][11];

const ll mod = 30011;

ll recur(int c,int cs,int ck) {
    if (ck>k) return 0;
    if (cs==0 && c>n) return 0;
    if (cs==1 && c>m) return 0;
    ll res = 0;
    if (ck%2==1) {
        res = 1;
    }

    if (dp[c][cs][ck]!=-1) return dp[c][cs][ck];

    if (cs==0) {
        int len = A[c].first;
        for1(i,A[c].second,A[c].second+len) {
            if (ban.find(mp(c,i))==ban.end()) res += recur(i,1,ck+1); else len++;
        }
    } else {
        int len = B[c].first;
        for1(i,B[c].second,B[c].second+len) {
            if (ban.find(mp(c,i))==ban.end()) res += recur(i,0,ck+1); else len++;
        }
    }

    return dp[c][cs][ck] = res%mod;
}

int main() {
	//ios::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	cout<<fixed;
	cin>>n>>m>>k>>l;
	if (k%2==0) k--;
	for1(i,0,l) {
        int a,b; scanf("%d%d",&a,&b);
        ban.insert(mp(a,b));
        ban.insert(mp(b,a));
	}
    for1(i,0,n) {
        int a,b; scanf("%d%d",&a,&b);
        A[i+1] = mp(a,b);
    }
    for1(i,0,m) {
        int a,b; scanf("%d%d",&a,&b);
        B[i+1] = mp(a,b);
    }

    ll res = 0;
    for1(i,1,n+1) {
        res += recur(i,0,0);
        res %= mod;
    }

    cout<<res%mod;
	return 0;
}
