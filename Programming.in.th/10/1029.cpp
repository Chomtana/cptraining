#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(a) a.begin(),a.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;


int main() {
    ios::sync_with_stdio(false);
    set<pii> data;
    int n,m,q; cin>>n>>m>>q;
    data.insert(mp(1,n));
    while (m--) {
        int a,b; cin>>a>>b;
        pii p = mp(a,b);
        set<pii>::iterator it = data.upper_bound(p);
        if (it==data.end()) goto doup;
        if (b>=(*it).first) {
            data.insert(mp((*it).first,b));
            data.insert(mp(b+1,(*it).second));
            data.erase(it);
        }

        doup:
        int downb = 0;//((it==data.end())?(*(it-1).second):(*it).second);
        if (it==data.end()) {
            advance(it,-1);
            downb = it->second;
        } else {
            downb = it->second;
            advance(it,-1);

        }
        if (b==(*it).second) {
            if (a>(*it).first) {
                data.insert(mp(a,downb));
                data.insert(mp(it->first,a-1));
                data.erase(it);
            } else {
                if (it == data.begin()) {
                    data.insert(mp(a,downb));
                    data.erase(it);
                } else {
                    advance(it,-1);
                    data.insert(mp(it->first,downb));
                    data.erase(it);
                    advance(it,1);
                    data.erase(it);
                }
            }
            it++;
            if (it != data.end()) {
                data.erase(it);
            }
            advance(it,-1);
        }
    }
    while(q--) {
        int x; cin>>x;
        pii _x = mp(x,0);
        set<pii>::iterator it = data.upper_bound(_x);
        advance(it,-1);
        cout<<(it->second-it->first+1)<<endl;
    }
    return 0;
}
