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

int ans[200005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t;
	while (t--) {
        rope<int> data;
        int n; scanf("%d",&n);
        for1(i,0,n) {
            data.push_back(i+1);
        }
        for1(i,0,n) {
            int x; scanf("%d",&x);
            if (x>0) {
                data.erase(data.mutable_begin()+i);
                data.insert(data.mutable_begin()+(i-x),i+1);
            }
        }
        for1(i,0,n) {
            ans[data[i]] = i+1;
        }
        for1(i,1,n+1) printf("%d ",ans[i]); printf("\n");
	}
	return 0;
}
