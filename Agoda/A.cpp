#include <bits/stdc++.h>
using namespace std;

#define for1(a,b,c) for(int a=b;a<c;a++)

int dp[55][1005];

int f(int p,int n) {
    if (p<=0 || n<0) return -1e9;
    if (p==1) return n;
    if (n==0) return 0;
    if (n==1) return 1;
    
    cout<<p<<' '<<n<<endl;
    
    return max(f(p-1, (n+1)/2-1), f(p, (n+1)/2+1));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin>>t;
    for1(_,1,t+1) {
        memset(dp,-1,sizeof(dp));
        int p,n; scanf("%d %d", &p, &n);
        printf("%d %d\n",_,f(p,n));
    }
    return 0;
}
