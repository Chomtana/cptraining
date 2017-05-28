#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;

    ll p = 1E10;
    ll n = -1E10;
    int t; cin>>t; while (t--) {
        ll x,y,r; scanf("%lld %lld %lld",&x,&y,&r);
        if (y==0) {
            cout<<-1;
            return 0;
        }
        if (y>0) {
            y -= r;
            p = min(y,p);
        } else {
            y+=r;
            n = max(y,n);
        }

    }

    if (n>=0 || p<=0) {
        cout<<-1;
        return 0;
    } else {
        cout<<min(abs(n),p);
    }
	return 0;
}
