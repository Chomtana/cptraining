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
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;

piii El[100005];

int n,m,q;
int dsu[5005]; //dsu[i] = parent(i)
int currg;
int g[100005];

int find(int i) {
    if (dsu[i]==i) return i;
    return dsu[i] = find(dsu[i]);
}

void un(int a,int b,int gi) {
    a = find(a);
    b = find(b);
    if (a!=b) {
        currg--;
        dsu[a] = b;
    }
    g[gi] = currg;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m>>q;
    for1(i,0,n) {
        dsu[i] = i;
    }
    currg = n;
    for1(i,0,m) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        El[i] = (mp(w,mp(s,e)));
    }

    sort(El,El+m);

    for1(i,0,m) {
        un(El[i].second.first,El[i].second.second,i);
    }

    /*for1(i,0,m) {
        cerr<<i<<' '<<El[i].first<<' '<<g[i]<<endl;
    }*/

    reverse(g,g+m);

    while (q--) {
        int x; scanf("%d",&x);
        auto it = upper_bound(g,g+m,x);
        if (it==g) {

        } else {
            it--;
            int i = it-g;
            i = m-i-1;
            printf("%d\n",El[i].first);
        }

    }


	return 0;
}
