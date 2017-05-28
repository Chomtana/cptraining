#include <bits/stdc++.h>

#define for1(a,b,c) for(ll (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;

ll data[6000000];
pii qs[6000000];

class comp {
public:
    bool operator () (const pii &a, const pii &b) const {
        if(a.first>b.first) return true;
        if(a.first<b.first) return false;

        return a.second<b.second;
    }
};

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    ll n,l; scanf("%lld %lld",&n,&l);
    for1(i,0,n) scanf("%lld",data+i);

    ll maxsum = 0;
    ll maxl = -1;

    qs[0].first = data[0];
    qs[0].second = 0;

    for1(i,1,n) {
        qs[i].first = qs[i-1].first+data[i];
        qs[i].second = i;
    }

    multiset<pii,comp> window;

    for1(i,0,l) {
        window.insert(qs[i]);
    }

    maxsum = max(maxsum,window.begin()->first);
    if (maxsum>0) {
        maxl = window.begin()->second+1;
    }

    for1(s,1,n) {
        window.erase(window.find(qs[s-1]));
        if (s+l-1<n) {
            window.insert(qs[s+l-1]);
        }
        ll value = window.begin()->first-qs[s-1].first;
        ll len = window.begin()->second-s+1;
        if (value>maxsum) {
            maxsum = value;
            maxl = len;
        } else if (value==maxsum) {
            maxl = min(maxl,len);
        }
    }

    if (maxl==-1) {
        cout<<"0\n0";
    } else {
        cout<<maxsum<<endl<<maxl;
    }


	return 0;
}
