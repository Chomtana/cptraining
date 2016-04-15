#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;
#define debug1(a) cout<<(a)<<endl;
#define debug2(a,b) cout<<(a)<<' '<<(b)<<endl;
#define debug3(a,b,c) cout<<(a)<<' '<<(b)<<' '<<(c)<<endl;
#define debug4(a,b,c,d) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<' '<<(e)<<endl;

typedef long long ll;

using namespace std;

ll calan(vector<ll> &c,ll n) {
    ll res = 0;
    for1(i,0,c.size()) {
        res += c[i]*pow(n,i);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cout<<fixed;
    int t; cin>>t;
    while (t--) {
        ll deg; cin>>deg;
        vector<ll> c(deg+1);
        for1(i,0,deg+1) {
            cin>>c[i];
        }
        ll d,k; cin>>d>>k;
        ll pos = 0;
        ll res = 0;
        for (ll n = 1;pos<k;n++) {
            res = calan(c,n);
            pos += n*d;
        }
        cout<<res<<endl;
    }
    return 0;
}