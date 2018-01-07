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

ll n,k;
int pos[1005];
int bl = -1; int br = 0;
int nearest[1000005];

bool check(ll day) {
    ll res = 0;
    for1(i,0,1000001) {
        res += max(0LL,day+1-nearest[i]);
    }
    //calculate out of bound
    ll res0 = max(0LL,day+1-nearest[0]);
    ll res1e6 = max(0LL,day+1-nearest[1000000]);
    res += (res0)*(res0-1)/2;
    res += (res1e6)*(res1e6-1)/2;

    //cerr<<day<<' '<<res<<endl;
    return res>=k;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n>>k;
	for1(i,0,n) {
        scanf("%d",pos+i);
	}

	sort(pos,pos+n);

	for1(i,0,1000001) {
	    if (br<n && i>pos[br]) {
            bl++;
            br++;
	    }
        nearest[i] = 1E9;
        if (bl!=-1) {
            nearest[i] = min(nearest[i],abs(i-pos[bl]));
        }
        if (br<n) {
            nearest[i] = min(nearest[i],abs(i-pos[br]));
        }
	}

    /*for1(i,0,20) {
        cerr<<nearest[i]<<' ';
    }
    cerr<<endl;*/

    ll l = 0; ll r = 1E10L;
    while(l<=r) {
        ll mid = (l+r)/2;
        if (check(mid)) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout<<l;
	return 0;
}
