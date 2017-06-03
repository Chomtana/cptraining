#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(a,b,c) for(int (a)=(b);((b)<(c)?(a)<(c):(a)>=(c));a+=((b)<(c)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int nn,mm,kk;

ll dp[35][35][35][2][35];

ll recur(int n,int m,int k,bool bf,int cm) { //bf;T = black , F = white ... m = maximum contiguous color , cm = last group contiguous color
    //cerr<<n<<' '<<m<<' '<<k<<endl;
    
    //base case
    if (m>mm) return 0; //run next -> mai me tung dai kum tob
    if (k>kk) return 0; //run next -> mai me tung dai kum tob
    if (n>=nn) {
        if (m<=mm && k==kk) return 1; else return 0;
    }
    
    if (dp[n][m][k][bf][cm]!=-1) return dp[n][m][k][bf][cm];
    
    //fill
    ll res = 0;
    for(int fill=0;fill<=1;fill++) {
        if (fill==bf) {
            res += recur(n+1,max(m,cm+1),k,fill,cm+1);
        } else {
            res += recur(n+1,m,k+1,fill,1);
        }
    }
    
    
    return dp[n][m][k][bf][cm] = res;
}

int main() {
    cin>>nn>>mm>>kk;
    memset(dp,-1,sizeof(dp));
    cout<<recur(1,1,0,true,1);
    return 0;
}
