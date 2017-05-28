#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;

ll floorlog2(ll a) {
    ll res = 0;
    while (a) {
        a>>=1;
        res++;
    }
    return res-1;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        ll n,k; cin>>n>>k;
        vector<pii> m;
        vector<pii> l;
        ll anslv = floorlog2(k)+1;
        //cout<<anslv<<endl;
        m.reserve(anslv+1);
        l.reserve(anslv+1);
        m.push_back(mp(n,1));
        l.push_back(mp(0,0));
        subfunc(void,lvcal,(ll lv)) {
            if (lv>anslv) {
                return;
            }

            if (m[lv].first%2==0) {
                //even
                m.push_back(mp(m[lv].first/2,m[lv].second));
                l.push_back(mp(m[lv].first/2-1,m[lv].second+2*l[lv].second));
            } else {
                //odd
                m.push_back(mp(m[lv].first/2,l[lv].second+2*m[lv].second));
                l.push_back(mp(m[lv].first/2-1,l[lv].second));
            }
            lvcal(lv+1);
        };

        lvcal(0);

        anslv--;

        ll ansbase = pow(2,anslv);

        subfunc(void,doans,(ll i)) {
            cout<<"Case #"<<_<<": ";
            if (i%2==0) {
                cout<<i/2<<' '<<i/2-1<<endl;
            } else {
                cout<<i/2<<' '<<i/2<<endl;
            }
        };

        for1(i,0,anslv+1) {
            cerr<<i<<" M "<<m[i].first<<' '<<m[i].second<<" L "<<l[i].first<<' '<<l[i].second<<endl;
        }
        cerr<<k-ansbase+1<<endl;

        if (k-ansbase+1 > m[anslv].second) {
            //ans less -> next lv
            doans(l[anslv].first);
        } else {
            //ans more -> next lv
            doans(m[anslv].first);
        }

    }
	return 0;
}
