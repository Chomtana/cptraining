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
    int t; cin>>t; for1(_,1,t+1) {
        printf("Case %d: ",_);
        double d,v,u; scanf("%lf %lf %lf",&d,&v,&u);

        if (v>=u || u==0 || v==0) {
            printf("Case %d: can't determine\n",_);
            continue;
        }

        double t1 = d/u;
        double t2 = d/sqrt(u*u-v*v);

        printf("Case %d: %.3lf\n",_,abs(t1-t2));
    }
	return 0;
}
