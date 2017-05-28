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

int n,t;
int C[30];

//count way problem
int Fcw(int c,int sm) {
    //super not ok
    if (sm>t) return 0;
    //super ok -> if do more -> mai me tung ok eek / mai me tung de kuean
    if(sm==t) return 1;
    //out of bound
    if (c<0) {
        //if ok return 1 (count way problem ... selective problem return F({}))
        if (sm==t) return 1;
        //else return antians (in count way problem antians = 0)
        return 0;
    }

    //count way use (mai aow,change) , (aow,mai change) : mun ja tong karm kun ... pork (aow,change) kerd jark (aow,mai change)+(mai aow,change)
    //but if not count way problem must write (aow,change)
    return Fcw(c-1,sm)+Fcw(c,sm+C[c]);

}

int dp[25][10005];

//count length problem
int F(int c,int sm) { //no condition meaning : F({...}) = count length of {...}
    //super not ok
    if (sm>t) return 1E9;
    //super ok -> if do more -> mai me tung ok eek / mai me tung de kuean
    if(sm==t) return 0;
    //out of bound
    if (c<0) {
        //if ok return F({})
        if (sm==t) return 0;
        //else return antians (in count way problem antians = 0)
        return 1E9;
    }

    if (dp[c][sm]!=-1) return dp[c][sm];

    //not count way problem must write (aow,change)
    return dp[c][sm] = min(F(c-1,sm),min(F(c,sm+C[c])+1,F(c-1,sm+C[c])+1));

}

/**
1. copy base case
2. return dp[c][sm] (mai tong check wa cached? because lao nae jai wa mun cached)
*/
int buget(int c,int sm) {
    //super not ok
    if (sm>t) return 1E9;
    //super ok -> if do more -> mai me tung ok eek / mai me tung de kuean
    if(sm==t) return 0;
    //out of bound
    if (c<0) {
        //if ok return F({})
        if (sm==t) return 0;
        //else return antians (in count way problem antians = 0)
        return 1E9;
    }

    return dp[c][sm];
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>t;
    for1(i,0,n) cin>>C[i];

    /// bottom up mai tong reset
    /// if kum tob pid sa dang wa order kong karn run loop pid
    //for1(i,0,25) for1(j,0,10005) dp[i][j]=-1;
    for1(c,0,n) { ///should write name same as recursive state
        for2(sm,t,0) {
            /// copy next step and change F to buget
            dp[c][sm] = min(buget(c-1,sm),min(buget(c,sm+C[c])+1,buget(c-1,sm+C[c])+1));
        }
    }

    //cout<<F(n-1,0);
    /// return dp[...][...] instead of F(...,...)
    cout<<dp[n-1][0];
	return 0;
}
