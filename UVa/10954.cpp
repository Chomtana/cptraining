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
    while (cin>>n,n!=0) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for1(i,0,n) {
            ll in; scanf("%lld",&in);
            pq.push(in);
        }

        ll res = 0;
        while (pq.size()>1) {
            ll curr = pq.top();
            pq.pop();
            curr += pq.top();
            pq.pop();
            res += curr;
            pq.push(curr);
        }

        printf("%lld\n",res);
    }
	return 0;
}
