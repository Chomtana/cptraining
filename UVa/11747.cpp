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
typedef pair<ll,pii> piii;

struct djnode {
    int parent,rank = 0;
};

djnode djset[1005];

int find(int i) {
    if (djset[i].parent==i) return i;
    return djset[i].parent = find(djset[i].parent);
}

void un(int a,int b) {
    a = find(a);
    b = find(b);
    if (djset[a].rank<djset[b].rank) {
        djset[a].parent = b;
        djset[b].rank++;
    } else {
        djset[b].parent = a;
        djset[a].rank++;
    }
}



int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m;
    while (cin>>n>>m,n!=0) {
        for1(i,0,n) {
            djset[i].parent = i;
            djset[i].rank = 0;
        }

        vector<piii> El;

        for1(i,0,m) {
            int s,e; ll w; cin>>s>>e>>w;
            El.push_back(mp(w,mp(s,e)));
        }

        sort(all(El));

        vector<ll> res;

        for1(i,0,El.size()) {
            int cs = El[i].second.first;
            int ce = El[i].second.second;
            ll cw = El[i].first;

            if (find(cs)==find(ce)) {
                res.push_back(cw);
            } else {
                un(cs,ce);
            }
        }

        sort(all(res));

        if (res.size()==0) cout<<"forest"<<endl; else {
            cout<<res[0];
            for1(i,1,res.size()) cout<<' '<<res[i];
            cout<<endl;
        }
    }
	return 0;
}
