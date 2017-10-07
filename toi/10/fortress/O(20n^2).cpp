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
    for1(i,0,n+1) {
        for1(j,0,n+1) {
            if (i+j>m) break;
            if (i+j>n) break;
            int k = n-i-j;
            if (2*i+4*j+2*k<=m) {
                if (2*i+4*j+2*k==m) res++;
            } else {
                break;
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
