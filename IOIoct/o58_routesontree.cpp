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
typedef pair<ll,ll> pii;
typedef pair<ll,pair<ll,ll>> piii;
typedef vector<int> vi;

int n,m,k;

vector<pii> E[100005];
ll dist[100005][7];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	for1(i,0,100005) for1(j,0,7) dist[i][j]=1E15;

    cin>>n>>m>>k;
    for1(i,0,m) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        E[s].emplace_back(e,w);
    }

    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push(mp(0,mp(1,0)));
    dist[1][0] = 0;
    while (!pq.empty()) {
        int c = pq.top().second.first;
        int ck = pq.top().second.second;
        pq.pop();

        for1(i,0,E[c].size()) {
            int ne = E[c][i].first;
            ll w = E[c][i].second;
            if (w>=0) {
                if (dist[c][ck]+w<dist[ne][ck]) {
                    dist[ne][ck] = dist[c][ck]+w;
                    pq.push(mp(dist[ne][ck],mp(ne,ck)));
                }
            } else if (w>=-100) {
                if (dist[c][ck]<dist[ne][ck]) {
                    dist[ne][ck] = dist[c][ck];
                    pq.push(mp(dist[ne][ck],mp(ne,ck)));
                }
            } else { // w<-100
                if (dist[c][ck]<dist[ne][ck+1] && ck+1<=k) {
                    dist[ne][ck+1] = dist[c][ck];
                    pq.push(mp(dist[ne][ck+1],mp(ne,ck+1)));

                }
            }
        }

    }

    ll res = *min_element(dist[n],dist[n]+7);
    if (res!=1E15) cout<<res; else cout<<-1;
	return 0;
}
