#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;

int n,m;

ll squaresum(ll x) {
    return x*(x+1)*(2*x+1)/6;
}

bool makeselected(vector<bool> &selected,ll pos) {
    for1(i,pos,n) {
        if (!selected[i]) {
            selected[i] = true;
            return true;
        }
    }
    return false;
}


ll main2() {
    cin>>n>>m;
    vector<pii> data; //(price,day)
    for1(i,0,n) {
        int datastart = data.size();
        for1(j,0,m) {
            ll price; cin>>price;
            data.push_back(mp(price,i));
        }
        //need to include tax
        //cerr<<"DBG:"<<datastart<<endl;
        sort(data.begin()+datastart,data.end());
        /*
        first 1^2 = 1
        second 2^2 = 4 -> 2^2-1^2 = 4-1 = 3
        third 3^2 = 9 -> 9-1-3 = 5
        */
        ll tempsum = 0;
        for(int j = datastart;j<data.size();j++) {
            ll item = j-datastart+1;

            data[j].first += item*item - tempsum;
            tempsum += item*item - tempsum;
            //cerr<<"DBG: "<<item<<' '<<data[j].first<<endl;
        }
    }

	//sort (price,day)
	//pub pub pub select if day nun selected -> make day nun / day tor pai selected ... if mai me day tor pai kor mai tong select mun

	sort(all(data));
    vector<bool> selected(n,false);
    ll sum = 0;
    for1(i,0,data.size()) {
        if (makeselected(selected,data[i].second)) {
            sum += data[i].first;
        }
    }
    return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;

	int t; cin>>t;
	for1(_t,1,t+1) {
        cout<<"Case #"<<_t<<": "<<main2()<<endl;
	}
	return 0;
}
