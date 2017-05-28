#include <bits/stdc++.h>

#define for1(a,b,c) for(ll (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;

//ll data[6000000];
pii qs[6000000];

deque<int> window;

class comp {
public:
    bool operator () (const pii &a, const pii &b) const {
        if(a.first>b.first) return true;
        if(a.first<b.first) return false;

        return a.second<b.second;
    }
};

bool C(pii &a,pii &b) {
    if(a.first>b.first) return true;
    if(a.first<b.first) return false;

    return a.second<b.second;
}

void windowins(int i) { //insert to sliding window takes index of element that want to insert
    pii &in = qs[i];
    while (!window.empty() && !C(qs[window.back()],in)) {
        window.pop_back();
    }

    window.push_back(i);
}

void windowpopob(int s) { //pop out of bound (takes start)
    while(!window.empty() && window[0]<s) {
        window.pop_front();
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    ll n,l; scanf("%lld %lld",&n,&l);
    for1(i,0,n) {
        ll x;
        //scanf("%lld",data+i); //optimize more by input -> calculate qs -> throw it away ... because in next time we don't use data[i]
        scanf("%lld",&x);
        if (i==0) {
            qs[0].first = x;
        } else {
            qs[i].first = qs[i-1].first+x;
        }
        qs[i].second = i;
    }

    //window.reserve(l+5);

    ll maxsum = 0;
    ll maxl = -1;

    //Processed in input step -> mai tong tum sum ... mai me pra yod
    /*qs[0].first = data[0];
    qs[0].second = 0;

    for1(i,1,n) {
        qs[i].first = qs[i-1].first+data[i];
        qs[i].second = i;
    }*/



    for1(i,0,l) {
        windowins(i);
    }

    maxsum = max(maxsum,qs[window[0]].first);
    if (maxsum>0) {
        maxl = qs[window[0]].second+1;
    }

    /*for1(i,0,n) {
        cerr<<qs[i].first<<' ';
    }
    cerr<<endl;

    cerr<<qs[window[0]].first<<endl;*/

    for1(s,1,n) {
        windowpopob(s); //window.erase(window.find(qs[s-1]));
        if (s+l-1<n) {
            windowins(s+l-1);
        }
        //cerr<<qs[window[0]].first<<endl;
        ll value = qs[window[0]].first-qs[s-1].first;
        ll len = qs[window[0]].second-s+1;
        if (value>maxsum) {
            maxsum = value;
            maxl = len;
        } else if (value==maxsum) {
            maxl = min(maxl,len);
        }
    }

    if (maxl==-1) {
        cout<<"0\n0";
    } else {
        cout<<maxsum<<endl<<maxl;
    }


	return 0;
}
