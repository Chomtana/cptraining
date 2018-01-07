#include <bits/stdc++.h>
#include <ext/rope>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;
using namespace __gnu_cxx;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n;
rope<int> v;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    for1(i,0,n) {
        int x; scanf("%d",&x);
        v.push_back(x);
    }
    int t; cin>>t;
    while (t--) {
        int l,m,r; scanf("%d%d%d",&l,&m,&r);
        rope<int> vv = v.substr(l,m-l);
        v.erase(l,m-l);
        v.insert(v.mutable_begin()+(r-(m-l)),vv);

    }
    for1(i,0,v.size()) {
        printf("%d ",v[i]);
    }
	return 0;
}
