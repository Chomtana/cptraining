#include <bits/stdc++.h>

#define for1(a,b,c) for(ll (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;
typedef vector<int> vi;

ll data[6000000];
pii qs[6000000];
pii tree[24000000];
ll n,l;

bool comp(pii &a,pii &b) {
    if(a.first>b.first) return true;
    if(a.first<b.first) return false;

    return a.second<b.second;
}

pii query(int ts,int te,int treei,int s,int e) {
    if (e<ts || s>te) return mp(-1000000000000000L,-1L);
    if (s>=ts && e<=te) return tree[treei];

    int mid = (s+e)/2;
    pii a = query(ts,te,2*treei,s,mid);
    pii b = query(ts,te,2*treei+1,mid+1,e);
    if (comp(a,b)) {
        return a;
    } else {
        return b;
    }
}

pii query(int ts,int te) {
    /*subfunc(pii,f,(int treei,int s,int e)) {

    };
    return f(1,0,n-1);*/
    return query(ts,te,1,0,n-1);
}

void build() {
    subfunc(void,f,(int treei,int s,int e)) {
        if (s==e) {
            tree[treei] = qs[s];
        } else {
            int mid = (s+e)/2;
            f(2*treei,s,mid);
            f(2*treei+1,mid+1,e);
            if (comp(tree[treei*2],tree[treei*2+1])) {
                tree[treei] = tree[treei*2];
            } else {
                tree[treei] = tree[treei*2+1];
            }
        }
    };
    f(1,0,n-1);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
     scanf("%lld %lld",&n,&l);
    for1(i,0,n) {
        scanf("%lld",data+i);
        if (i==0) {
            qs[i].first = data[i];
        } else {
            qs[i].first = qs[i-1].first + data[i];
        }
        qs[i].second = i;
    }

    ll maxsum = 0;
    ll maxl = -1;

    /*qs[0].first = data[0];
    qs[0].second = 0;

    for1(i,1,n) {
        qs[i].first = qs[i-1].first+data[i];
        qs[i].second = i;
    }*/

    build();

    /*for1(i,0,4*n) {
        cerr<<tree[i].first<<' ';
    }
    cerr<<endl;*/

    pii res = mp(-1000000000000000L,-1L);

    for1(s,0,n) {
        //pii maxval = query(s,s+l-1);
        pii maxval = mp(s,s+l-1);
        if (s>0) {
            maxval.first -= qs[s-1].first;
        }
        ll len = maxval.second-s+1;
        if (maxval.first>maxsum) {
            maxsum = maxval.first;
            maxl = len;
        } else if (maxval.first==maxsum) {
            maxl = min(maxl,len);
        }
    }

    /*multiset<pii,comp> window;

    for1(i,0,l) {
        window.insert(qs[i]);
    }

    maxsum = max(maxsum,window.begin()->first);
    if (maxsum>0) {
        maxl = window.begin()->second+1;
    }

    for1(s,1,n) {
        window.erase(window.find(qs[s-1]));
        if (s+l-1<n) {
            window.insert(qs[s+l-1]);
        }
        ll value = window.begin()->first-qs[s-1].first;
        ll len = window.begin()->second-s+1;
        if (value>maxsum) {
            maxsum = value;
            maxl = len;
        } else if (value==maxsum) {
            maxl = min(maxl,len);
        }
    }*/

    if (maxl==-1) {
        cout<<"0\n0";
    } else {
        cout<<maxsum<<endl<<maxl;
    }


	return 0;
}
