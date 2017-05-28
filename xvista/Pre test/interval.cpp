//count inversion problem (count n^2 pair that x,y has opposite condition (ex: x<x , y>y)

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

pii data[100005];

class fwtree {
public:
    vector<int> fwdata;

    void add(int pos,int num) {
        for(int i = pos;i<fwdata.size();i+=i&(-i)) fwdata[i]+=num;
    }

    int get(int pos) {
        int res = 0;
        for(int i = pos;i>=0;i-=i&(-i)) res += fwdata[i];
        return res;
    }

    fwtree(int s) {
        fwdata.resize(s,0);
    }

};

int main() {
    ll n; cin>>n;
    for1(i,0,n) scanf("%d %d",&data[i].first,&data[i].second);
    sort(data,data+n);

    ll res = 0;
    vector<int> ok;
    priority_queue<int,vector<int>,greater<int>> fail;
    for1(i,1,n) {
        if (data[i-1].second<=data[i].first) {
            ok.pb(data[i-1].second);
        } else {
            fail.push(data[i-1].second);
        }

        while (!fail.empty() && fail.top()<=data[i].first) {
            ok.pb(fail.top());
            fail.pop();
        }

        res += ok.size();
    }

    cout<<(n*(n-1))/2-res;

    return 0;
}
