#include <bits/stdc++.h>

#define for1(a,b,c) for(ll (a)=(b);(a)<(c);(a)++)
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
    ll n,l; scanf("%lld %lld",&n,&l);
    ll data[n];
    for1(i,0,n) scanf("%lld",data+i);

    ll maxsum = 0;
    ll maxl = -1;

    for1(s,0,n) {
        for1(len,1,l+1) {
            ll sum = 0;
            for1(i,s,s+len) {
                if (i>=n) break;
                sum += data[i];
            }
            if (sum>maxsum) {
                maxsum = sum;
                maxl = len;
            } else if (sum==maxsum) {
                maxl = min(maxl,len);
            }
        }
    }

    if (maxl==-1) {
        cout<<"0\n0";
    } else {
        cout<<maxsum<<endl<<maxl;
    }
	return 0;
}
