#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n,k,m; scanf("%d %d %d",&n,&k,&m);
    piii data[n]; for1(i,0,n) {
        scanf("%d %d",&data[i].first.first,&data[i].first.second);
        data[i].second = i;
    }
    sort(data,data+n);
    //for1(i,0,n) cout<<data[i].first<<','<<data[i].second<<' ';
    //cout<<endl;
    multiset<int> service;
    for1(i,0,k) service.insert(0);
    vector<bool> res(n,false);
    for1(i,0,n) {
        auto jit = service.lower_bound(data[i].first.first);
        //cout<<data[i].first.first<<' '<<*service.begin()<<endl;

        if (jit==service.begin()) continue;
        jit--;
        if (*jit < data[i].first.first) {
            service.insert(data[i].first.second);
            service.erase(jit);
            res[data[i].second] = true;
        }
    }
    while (m--) {
        int in; scanf("%d",&in);
        in--;
        printf((res[in]?"Y ":"N "));
    }
	return 0;
}
