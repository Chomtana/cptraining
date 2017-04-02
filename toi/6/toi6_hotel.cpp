#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define macro(a,b) if(mod==a) res+=b;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    ll n; cin>>n;
    ll mod = n%15;
    n /= 15;
    ll res = n*3000;
    macro(1,500)
    macro(2,800)
    macro(3,1300)
    macro(4,1500)
    macro(5,1500)
    macro(6,2000)
    macro(7,2300)
    macro(8,2800)
    macro(9,3000)
    macro(10,3000)
    macro(11,3000)
    macro(12,3000)
    macro(13,3000)
    macro(14,3000)
    cout<<res;
	return 0;
}
