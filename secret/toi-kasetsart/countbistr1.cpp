#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;
typedef long long ll;

vector< vector<ll>> pascal;

ll get(int r,int c) {
    if (r<0 || c<0 || r>=pascal.size() || c>=pascal.size()) return 0;
    return pascal[r][c];
}

void build(int n) {
    if (n==51) return;
    vector<ll> sub;
    for (int i = 0;i<=n;i++) {
        sub.push_back(get(n-1,i-1)+get(n-1,i));
    }
    pascal.push_back(sub);
    build(n+1);
}

int main() {
    int n,m; cin>>n>>m;
    pascal.push_back(vector<ll>(1,1));
    build(1);
    ll res = 0;
    for1(i,0,m+1) {
        res += pascal[n][i];
    }
    cout<<res;
    return 0;
}
