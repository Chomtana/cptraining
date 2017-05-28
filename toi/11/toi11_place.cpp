#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pair<int,int>> piii;
typedef vector<int> vi;

struct djnode {
    int parent;
    int rank = 0;
};

djnode djset[200005];

int find(int i) {
    if (djset[i].parent == i) return i;
    return djset[i].parent = find(djset[i].parent);
}

void un(int a,int b) {
    a = find(a);
    b = find(b);
    if (djset[a].rank < djset[b].rank) {
        djset[a].parent = b;
        djset[b].rank++;
    } else {
        djset[b].parent = a;
        djset[a].rank++;
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m; cin>>n>>m;
    deque<piii> El(m);
    for1(i,0,m) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        El[i] = mp(w,mp(s,e));
    }

    sort(all(El),greater<piii>());

    for1(i,0,n+1) {
        djset[i].parent = i;
    }

    ll sigmaw = 0;

    while (El.size()>0) {
        int cs = El[0].second.first;
        int ce = El[0].second.second;
        int cw = El[0].first;

        El.pop_front();

        if (find(cs)!=find(ce)) {
            sigmaw += cw;
            un(cs,ce);
        }
    }

    cout<<sigmaw-(n-1);


	return 0;
}
