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

#define m 1000000007


int n;

ll dp[100005][10];

bool isp(int a,int b) {
    if (a==1) return b!=2;
    if (a==2) return b!=1;
    if (a==3) return b!=4 && b!=5;
    if (a==4) return b!=3 && b!=5;
    if (a==5) return b!=3 && b!=4;
}

ll recur(int ins,int last) {
    if (ins>=n) return 1;
    
    if (dp[ins][last+1]!=-1) return dp[ins][last+1];
    
    ll res = 0;
    for1(i,1,6) {
        if (isp(i,last)) {
            res += recur(ins+1,i);
            res%=m;
        }
    }
    return dp[ins][last+1] = res;
}

int main() {
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,-1);
    return 0;
}
