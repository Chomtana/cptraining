/*
Learn new thing:
Sliding window in O(n)
Shadow remove from front/back if we only do pop (no push in any line of code) in that direction ... use index as current first element ... then no shadow arr[x] will become arr[x+firstelementindex]
*/

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

//deque<int> window; //Optimise by using shadow pop_front and vector.reserve
vector<int> window;
int windowfront = 0;

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
    while ((window.size()>windowfront) && !C(qs[window.back()],in)) { //use (size>start) instead of !window.empty() because in shadow remove it can't be empty ...
        window.pop_back();
    }

    window.push_back(i);
}

void windowpopob(int s) { //pop out of bound (takes start)
    while((window.size()>windowfront) && window[windowfront]<s) {
        windowfront++;
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    ll n,l; scanf("%lld %lld",&n,&l);
    ll x; //scanf("%lld",&x);

    //qs[0].first = x;
    //qs[0].second = 0;

    for1(i,0,n) { //because if is slow so we need to make i=0 special case
        //scanf("%lld",data+i); //optimize more by input and throw
        //scanf("%lld",&x);
        //qs[i].first = qs[i-1].first+x;
        //qs[i].second = i;
        scanf("%lld",&x); //optimize more by input and throw
        if (i==0) {
            qs[0].first = x;
        } else {
            qs[i].first = qs[i-1].first+x;
        }
        qs[i].second = i;
    }

    //window.reserve(l+5);
    window.reserve(n+5); //shadow remove don't remove value so it must be n

    ll maxsum = 0;
    ll maxl = -1;

    //processed in input step ... don't need to redo
    /*qs[0].first = data[0];
    qs[0].second = 0;

    for1(i,1,n) {
        qs[i].first = qs[i-1].first+data[i];
        qs[i].second = i;
    }*/



    for1(i,0,l) {
        windowins(i);
    }

    maxsum = max(maxsum,qs[window[windowfront]].first);
    if (maxsum>0) {
        maxl = qs[window[windowfront]].second+1;
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
        ll value = qs[window[windowfront]].first-qs[s-1].first;
        ll len = qs[window[windowfront]].second-s+1;
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
