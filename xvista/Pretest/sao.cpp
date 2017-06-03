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

int main() {
    int nr,nc; cin>>nr>>nc;
    //int data[nr][nc];
    /*for1(i,0,nr) {
        for1(j,0,nc) {
            scanf("%d",&data[i][j]);
        }
    }*/

    ll res = 0;

    for1(i,0,nr) {
        set<ll> getter;
        for1(j,0,nc) {
            ll x; scanf("%lld",&x);
            auto it = getter.lower_bound(x/*data[i][j]*/); //want < -> lb-1
            if (it==getter.begin()) {

            } else {
                it--;
                res += *it;
            }
            getter.insert(x/*data[i][j]*/);
        }
    }

    cout<<res;

    return 0;
}
