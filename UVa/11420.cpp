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

int nn,ss;
ll dp[70][70][2];

ll recur(int n,int s,int last) {
    if (s==-1) return 0;
    if (n==0) return 0;
    if (n==1) {
        if (s==1) {
            if (!last) return 1; else return 0;
        } else if (s==0) {
            if (!last) return 0; else return 1;
        } else return 0;
    }

    if (dp[n][s][last]!=-1) return dp[n][s][last];

    //first build final -> cal remaining state after build final

    ll res = 0;

    //if last(=final) is u then we need s more
    if (last) {
        res += recur(n-1,s,false)+recur(n-1,s,true);
    } else {
        //if last not u then we need s-1 more
        res += recur(n-1,s-1,false);

        //if last is u then we need s more
        res += recur(n-1,s,true);
    }

    return dp[n][s][last] = res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	memset(dp,-1,sizeof(dp));
    while(cin>>nn>>ss,nn>=0) {
        printf("%lld\n",recur(nn,ss,0)+recur(nn,ss,1));
        //cerr<<recur(nn,ss,0)<<' '<<recur(nn-1,ss,0)<<endl;
        //for1(i,0,nn+1) for1(j,0,ss+1) for1(k,0,2) cerr<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
    }
	return 0;
}
