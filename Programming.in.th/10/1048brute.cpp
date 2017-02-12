#include <bits/stdc++.h>

#define for1(a,b,c) for(ll (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

/*
Brute force induction pattern recognize:
- [2]
- [3]
- [2 4]
2 3 [2 5]
2 3 2 4 2 3 [2 6]
2 3 2 4 2 3 2 5 2 3 2 4 2 3 [2 7]
*/

ll countbit(ll x) {
    ll res = 0;
    while (x) {
        res += x&1;
        x >>= 1;
    }
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    ll k,n; cin>>k>>n;

    //brute force induction all n
    //ll k = 32;
    //for1(n,0,100/*(1L<<32L) - 1L*/) {


        ll res = 0;
        for1(i,0,n) {
            ll x = i^(i+1);
            //cout<<i<<' '<<i+1<<' '<<countbit(x)<<endl;
            res += countbit(x);
        }
        cout<<res<<endl;
    //}
	return 0;
}
