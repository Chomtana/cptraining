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
    int m,n; scanf("%d%d",&m,&n);
    if (m%2!=0) return 0;
    int want = m/2;
    //for(int x = 0;x<=want;x+=2) {
    //it has direction (20 19 18 16 13 ... 2) -> use binary search ok
    int l=0,r = want;
    while (l<=r) {
        int B = (l+r)/2; //must brute number that possible all num in range (can linear search with for1/for2 macro)
        int x = 2*B;
        int AC = want-x;
        //int B = x/2;
        //cerr<<AC+B<<endl;
        //cerr<<x<<endl;
        if (AC+B==n) {
            //res += AC+1;
            return AC+1; //return because AC+B is unique
        } else {
            //if not find ans ->
            if (AC+B<n) {
                r = B-1;
            } else {
                l = B+1;
            }
        }
    }
    return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t = 20; while(t--) cout<<process()<<endl;
	return 0;
}
