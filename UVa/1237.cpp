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

struct type{
    string s;
    ll l,u;
};

bool ts(type a, type b) {
    return a.l<b.l;
}

int main() {
    ios::sync_with_stdio(false);
    cout<<fixed;
    int t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        vector<type> data(n);
        for1(i,0,n) {
            cin>>data[i].s>>data[i].l>>data[i].u;
        }
        //sort(data,data+n,ts);
        int q; cin>>q;
        while (q--) {
            ll in; cin>>in;
            bool ok = false;
            int oki = 0;
            for1(i,0,n) {
                if (data[i].l<=in && in<=data[i].u) {
                    if (ok) {ok=false; break;}
                    ok = true;
                    oki = i;
                }
                
            }
            cout<<((ok)?data[oki].s:"UNDETERMINED")<<endl;
        }
        if (t>0)
        cout<<endl;
    }
    return 0;
}