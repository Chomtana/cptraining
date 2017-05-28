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
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(6);
    int t; cin>>t; for1(_,1,t+1) {
        int n,k; cin>>n>>k;
        ld u; cin>>u;
        ld data[n];
        ld mindata = 1000;
        for1(i,0,n) {
            cin>>data[i];
            mindata = min(mindata,data[i]);
        }

        ld l = mindata;
        ld h = 1;
        for1(i,0,1000) {
            ld mid = (l+h)/2;

            ld uneed = 0;
            for1(i,0,n) {
                if (data[i]<mid) {
                    uneed += mid-data[i];
                }
            }

            if (uneed <= u) {
                l = mid+0.000001;
            } else {
                h = mid-0.000001;
            }

            //cerr<<l<<' '<<h<<' '<<mid<<endl;
        }

        l -= 0.000001;

        ld res = 1;

        for1(i,0,n) {
            if (data[i]<l) {
                res *= l;
            } else {
                res *= data[i];
            }
        }

        cout<<"Case #"<<_<<": "<<res<<endl;
    }
	return 0;
}
