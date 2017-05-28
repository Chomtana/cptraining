#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int m,n; cin>>m>>n;
    ll data[m]; for1(i,0,m) scanf("%lld",data+i);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for1(i,0,m) {
        pq.push(mp(data[i],i));
    }
    while (n--) {
        ll finish = pq.top().first;
        int id = pq.top().second;
        finish += data[id];
        pq.pop();
        pq.push(mp(finish,id));
    }

    ll res = 0;

    while (!pq.empty()) {
        ll finish = pq.top().first;
        int id = pq.top().second;
        finish -= data[id];
        res = max(res,finish);
        pq.pop();

    }

    cout<<res;

	return 0;
}
