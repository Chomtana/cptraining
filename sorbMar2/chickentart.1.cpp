#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int nn,mm,kk;
int A[100005];
//vector<int> A;

int mymax = 0;
int my = 0;
vector<pii> myp;

const int inf = 1e9+5;

pii merge(pii a,pii b) {
    int x[4];
    x[0] = a.first;
    x[1] = a.second;
    x[2] = b.first;
    x[3] = b.second;
    sort(x,x+4,greater<int>());
    return {x[0],x[1]};
}

pii merge(pii a,int b) {
    int x[3];
    x[0] = a.first;
    x[1] = a.second;
    x[2] = b;
    sort(x,x+3,greater<int>());
    return {x[0],x[1]};
}

pii select(pii a,pii b) {
    if (a.second<b.second) return a;
    else if (a.second>b.second) return b;
    
    if (a.first>b.first) return a;
    if (a.first<b.first) return b;
}

pii dp[1005][1005];

pii f(int n,int k) {
    //cerr<<n<<' '<<k<<endl;
    
    if (n<=0) {
        if (k==0) {
            return dp[n][k] = {0,0};
        } else {
            return dp[n][k] = {inf,inf};
        }
    }
    if (k==0) return dp[n][k] = {inf,inf};
    
    pii res = {inf,inf};
    int sum = 0;
    for1(i,1,mm+1) {
        if (i>n) break;
        sum += A[n-i];
        pii subres = merge(f(n-i,k-1),sum);
        res = select(res,subres);
    }
    
    return dp[n][k] = res;
}

int main() {
    int n,m,k; cin>>n>>m>>k;
    nn = n; mm = m; kk = k;
    for1(i,0,n) {
        scanf("%d",A+i);
    }
    
    for1(i,0,1005) for1(j,0,1005) dp[i][j] = {-1,-1};
    
    cout<<f(n,k).second<<endl;
    
    for1(i,0,n+1) {
        for1(j,0,k+1) {
            printf("n=%d k=%d : %d %d\n",i,j,dp[i][j]);
        }
    }
    return 0;
}