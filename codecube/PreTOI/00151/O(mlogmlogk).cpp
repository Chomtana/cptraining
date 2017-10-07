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
typedef pair<int,pii> piii;
typedef vector<int> vi;

int n,m,k,t;
vector<vector<piii>> E(100005);
pii shoeraw[100005];
vector<pii> shoe;
ll dist[100005];

bool check(int d) {
    fill(dist,dist+n+5,1E15L);
    dist[1] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(mp(0,1));
    while (!q.empty()) {
        int c = q.top().second;
        q.pop();
        for1(i,0,E[c].size()) {
            int ne = E[c][i].first;
            int need = E[c][i].second.first;
            int w = E[c][i].second.second;
            //cerr<<"aaa "<<c<<' '<<ne<<endl;
            if (need<=d) {
                if (dist[c]+w<dist[ne]) {
                    dist[ne] = dist[c]+w;
                    q.push(mp(dist[ne],ne));
                }
            }
        }
    }
    return dist[n]<=t;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m>>k>>t;
    for1(i,0,m) {
        int s,e,d,t; scanf("%d%d%d%d",&s,&e,&d,&t);
        E[s].push_back(mp(e,mp(d,t)));
        E[e].push_back(mp(s,mp(d,t)));
    }
    for1(i,0,k) {
        scanf("%d%d",&shoeraw[i].second,&shoeraw[i].first);
    }
    sort(shoeraw,shoeraw+k);
    shoe.reserve(k+5);
    for1(i,0,k) {
        while (!shoe.empty() && shoe.back().second>=shoeraw[i].second) {
            shoe.pop_back();
        }
        shoe.push_back(shoeraw[i]);
    }

    /*for1(i,0,shoe.size()) {
        cerr<<shoe[i].first<<' '<<shoe[i].second<<endl;
    }*/

    int l = 0,r=shoe.size()-1;
    while(l<=r) {
        int mid = (l+r)/2;
        if(check(shoe[mid].first)) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    //cerr<<check(50)<<endl;
    if (l>=shoe.size()) {
        cout<<-1<<endl;
    } else {
        cout<<shoe[l].second<<endl;
    }
	return 0;
}
