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
    for(int x = 0;x<=want;x+=2) {
        int AC = want-x;
        int B = x/2;
        //cerr<<AC+B<<endl;
        if (AC+B==n) {
            res += AC+1;
        } else if (AC+B<n) break;
    }
    return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t = 20; while(t--) cout<<process()<<endl;
	return 0;
}
