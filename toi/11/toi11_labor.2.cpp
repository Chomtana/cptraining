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

int T[1000005];
ll m,n;

ll check(ll size) { //return maximum box that can transfer withing <size> time
    ll total = 0;
    for1(i,0,m) {
        total += size/T[i];
    }
    return total;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>m>>n;
    for1(i,0,m) scanf("%d",T+i);
    
    ll l = 0; ll r = 1E12;
    while (l<=r) {
        ll mid = (l+r)/2;
        if (check(mid)>=n) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    
    cout<<l;
	return 0;
}
