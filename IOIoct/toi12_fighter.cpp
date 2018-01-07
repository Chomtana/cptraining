#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    ll p; cin>>p;
    int contig = 0;
    bool last = true;
    int e = p;
    int o = p;
    for1(i,0,2*p) {
        ll n; scanf("%lld",&n);
        if (n%2==0) {
            if (!last) {
                contig = 0;
                last = true;
            }
            if (contig<2) {
                o--;

            } else {
                o -= 3;

            }
            contig++;
        } else {
            if (last) {
                contig = 0;
                last = false;
            }
            if (contig<2) {
                e--;

            } else {
                e -= 3;

            }
            contig++;
        }
        if (e<=0) {
            cout<<1<<endl<<n;
            return 0;
        } else if (o<=0) {
            cout<<0<<endl<<n;
            return 0;
        }
    }
	return 0;
}
