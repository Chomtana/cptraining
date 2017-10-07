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

int n,m;
ll data[1005];
ll qs[1005];
ll res = -1;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    while (cin>>n>>m,n!=0) {
        for1(i,0,n) scanf("%d",data+i);
        res = -1;
        qs[0] = data[n-1];
        qs[0] %= m;
        //cerr<<1<<" | "<<qs[0]<<' ';
        for1(i,1,n) {
            qs[i] = qs[i-1]+data[n-1-i];
            qs[i] %= m;
            //cerr<<qs[i]<<' ';
        }
        //cerr<<endl;
        res = max(res,qs[n-1]);
        for1(k,2,n+1) {
            qs[0] = data[n-(k-1)-1]*qs[0];
            qs[0] %= m;
            //cerr<<k<<" | "<<qs[0]<<' ';
            for1(i,1,n-(k-1)) {
                qs[i] = qs[i-1]+qs[i]*data[n-(k-1)-i-1];
                qs[i] %= m;
                //cerr<<qs[i]<<' ';
            }
            //cerr<<endl;
            res = max(res,qs[n-(k-1)-1]);
        }

        printf("%lld\n",res);
    }
	return 0;
}
