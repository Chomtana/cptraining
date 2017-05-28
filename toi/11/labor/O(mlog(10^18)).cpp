/**
binary search rule : if (l==h) then l = h = mid = point that we want+-1 (in this case we want balance point)
                        to do binary search you need to know if (...) then point that we need in left/right -> else point that we need in opposite direction
*/

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

ll m,n;
ll data[1000005];
ll datamin = 1E15;

ll countn(ll s) {
    ll res = 0;
    for1(i,0,m) {
        res += s/data[i];
    }
    return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    //srand(time(0));
    cin>>m>>n;
    //m = 1000000;
    //n = 1000000000000;


    for1(i,0,m) {
        scanf("%lld",&data[i]);
        //data[i] = rand()%1000000+10;

        datamin = min(datamin,data[i]);
    }

    //sort(data,data+m);

    //ll res = 2E18;

    //cout<<res<<endl;

    //binary search
    ll l = 0;
    ll h = 1E18;
    while (l<=h) {
        ll mid = (l+h)/2;
        ll curr = countn(mid);
        //ll curr = -1;

        //cerr<<mid<<endl;

        if (curr>=n) {
            h = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout<<l;
	return 0;
}
