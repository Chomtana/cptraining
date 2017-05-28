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
    int n,m;
    while(cin>>n>>m,n!=0||m!=0) {
        bitset<1000005> u;
        bool ok = true;
        for1(i,0,n) {
            int s,e; scanf("%d %d",&s,&e);
            if (ok)
            for1(j,s,e) {
                if (u[j]) {
                    ok = false;
                } else {
                    u[j] = true;
                }
            }
        }
        for1(i,0,m) {
            int s,e,r; scanf("%d%d%d",&s,&e,&r);
            if (ok)
            while (s<=1000000) {
                for1(j,s,e) {
                    if (j>1000000) {
                        break;
                    }
                    if (u[j]) {
                        ok = false;
                    } else {
                        u[j] = true;
                    }
                }

                s+=r;
                e+=r;
            }
        }

        if (ok) printf("NO CONFLICT\n"); else printf("CONFLICT\n");
    }
	return 0;
}
