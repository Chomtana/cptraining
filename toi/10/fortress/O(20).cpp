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

ll process() {
    ll res = 0;
    ll m,n; scanf("%lld%lld",&m,&n);
    if (m%2!=0) return 0;
    ll want = m/2;
    ll B = want-n;
    if (B<0) return 0;
    if (want-2*B+1<=0) return 0; //crit case found by manual random test case : 1e8 1e6
    return want-2*B+1;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t = 20; while(t--) cout<<process()<<endl;
	return 0;
}
