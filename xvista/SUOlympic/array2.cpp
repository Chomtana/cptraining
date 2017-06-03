#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(a,b,c) for(int (a)=(b);((b)<(c)?(a)<(c):(a)>=(c));a+=((b)<(c)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    int n; cin>>n;
    map<string,ll> data;
    while(n--) {
        string x; ll y; cin>>x>>y;
        data[x] += y;
    }
    vector<pair<ll,string>> getter;
    getter.reserve(10005);
    for(auto &p:data) {
        getter.emplace_back(p.second,p.first);
    }
    sort(all(getter),greater<pair<ll,string>>());
    for1(i,0,getter.size()) {
        if (getter[i].first == getter[0].first) {
            cout<<getter[i].second<<' '<<getter[i].first<<endl;
        }
    }
    return 0;
}
