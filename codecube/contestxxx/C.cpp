/**
Critical case:
Problem bork gew gub index -> pen index gao -> don't use index after sort ***

2 2
0000
0000
must answer 0
but it answer 1
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
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll backup[100005];
ll data[100005];
int n,m;

ll check(ll k) {
	for1(i,0,n) {
		data[i] = backup[i]+(i+1)*k;
	}
	sort(data,data+n);
	ll totalmoney = 0;
	for1(i,0,k) {
		totalmoney += data[i];
	}
	return totalmoney;
}

/*ll checkk(ll k) {
	ll l = 0; ll r = 1E9;
	while (l<=r) {
		ll mid = (l+r)/2;
		if (check(k,mid)) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	return l;
}*/

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n>>m;
	for1(i,0,n) {
		scanf("%I64d",backup+i);
	}
	
	//sort(data,data+n);
	
	ll kl = 0; ll kr = n;
	while (kl<=kr) {
		ll mid = (kl+kr)/2;
		ll checkres = check(mid);
		//cerr<<mid<<' '<<checkres<<endl;
		if (checkres<=m) {
			kl = mid+1;
		} else {
			kr = mid-1;
		}
	}
	
	cout<<kl-1<<' '<<check(kl-1);
	return 0;
}
