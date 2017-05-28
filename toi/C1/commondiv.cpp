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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    ll data[n];
    ll datasqrt[n];
    ll minsqrt = 1E15;
    ll mindata = 1E15;
    for1(i,0,n) {
        cin>>data[i];
        datasqrt[i] = sqrt(data[i]);
        mindata = min(mindata,data[i]);
        minsqrt = min(minsqrt,datasqrt[i]);
    }

    ll res = 0;

    //minsqrt = sqrt(11232);
    //mindata = 11232;

    //vector<int> dbg;

    for(ll i = 1;i<=minsqrt;i++) {
        bool ok = true;
        //cout<<ok<<endl;
        for1(j,0,n) {
            if (data[j]%i!=0) {
                ok = false;
                break;
            }
        }



        if (ok) {
            res++;

            //dbg.push_back(i);
        }

        ll ni = mindata/i;
        bool ok2 = true;
        for1(j,0,n) {
            //cout<<"nierr "<<ni<<' '<<data[j]<<endl;
            if (data[j]%ni!=0) {
                ok2 = false;

                break;
            }
        }

        if (ok2 && i!=ni) {
            res++;
            //dbg.push_back(ni);
        }
    }

    cout<<res<<endl;

    //sort(all(dbg));
    //for(int i:dbg) cout<<i<<' ';

	return 0;
}
