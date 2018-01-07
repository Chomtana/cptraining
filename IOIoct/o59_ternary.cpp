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

const ll mod = 1e9+7;

int n;
int pre[105];
int in[105];
int I[105];

int dbg = 8;

ll dp[105][105][105];

ll recur(int prei,int ins,int ine) {
    //if (prei>n) return 0;

    //cerr<<prei<<' '<<ins<<' '<<ine<<endl;

    if (ins>ine) {
        return 1;
    }

    if (ins==ine) {
        return pre[prei]==in[ins];
    }

    //dbg--; if(dbg<=0) return 0;

    int ini = I[pre[prei]];

    if (ini<ins || ini>ine) return 0;

    if (dp[prei][ins][ine]!=-1) return dp[prei][ins][ine];

    //cerr<<prei<<' '<<ins<<' '<<ine<<" call "<<prei+ini-ins+1<<' '<<ini+1<<' '<<ine<<endl;
    ll res = 0;
    /*res = recur(prei+1,ins,ini-1)*recur(prei+ini-ins+1,ini+1,ine);
    res %= mod;
    if (ini+1<=ine) {
        res += recur(prei+1,ins,ini-1)*recur(prei+ini-ins+1,ini+1,ine);
        res %=mod;
    }*/
    for1(i,ini,ine+1) {
        //cerr<<prei<<' '<<ins<<' '<<ine<<" call "<<prei+ini-ins<<' '<<ini+1<<' '<<i<<" and "<<prei+i-ins+1<<' '<<i+1<<' '<<ine<<endl;
        res += ((recur(prei+1,ins,ini-1)*recur(prei+ini-ins+1,ini+1,i))%mod)*(recur(prei+i-ins+1,i+1,ine)%mod);
        res %= mod;
    }
    return dp[prei][ins][ine] = res%mod;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for1(i,0,n) {
        scanf("%d",pre+i);
    }
    for1(i,0,n) {
        scanf("%d",in+i);
        I[in[i]] = i;
    }

    cout<<recur(0,0,n-1);
	return 0;
}
