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
    int n;
    while (cin>>n) {
        ll data[n]; for1(i,0,n) scanf("%lld",data+i);
        ll m; scanf("%lld",&m);

        sort(data,data+n);

        //always have sol in this prob (jod bork)
        //bool ok = false;

        ll ans1,ans2;

        for1(i,0,n) {
            ll nf = m-data[i];
            if (nf<data[i]) break;
            if (binary_search(data,data+n,nf)) {
                //ok = true;
                ans1 = data[i];
                ans2 = nf;
                //printf("Peter should buy books whose prices are %lld and %lld.\n\n",data[i],nf);
                //break;
            }
        }

        printf("Peter should buy books whose prices are %lld and %lld.\n\n",ans1,ans2);


    }
	return 0;
}
