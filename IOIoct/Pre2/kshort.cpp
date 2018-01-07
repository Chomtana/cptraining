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

int n,m,ns,l;
vector<pii> E[10005];
vector<pii> Es[10005];
int dist[10005][55];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m>>ns>>l;
    for1(i,0,m) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        E[s].push_back({e,w});
    }
    for1(i,0,ns) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        Es[s].push_back({e,w});
    }

    for1(i,0,n+5) fill(dist[i],dist[i]+55,1E9);

    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({0,{1,0}});
    dist[1][0] = 0;
    while (!pq.empty()) {
        int c = pq.top().second.first;
        int cs = pq.top().second.second;
        pq.pop();

        for1(i,0,E[c].size()) {
            int ne = E[c][i].first;
            int w = E[c][i].second;
            if (dist[c][cs]+w<dist[ne][cs]) {
                dist[ne][cs] = dist[c][cs]+w;
                pq.push({dist[ne][cs],{ne,cs}});
            }
        }

        if (cs+1<=l) {
            for1(i,0,Es[c].size()) {
                int ne = Es[c][i].first;
                int w = Es[c][i].second;
                if (dist[c][cs]+w<dist[ne][cs+1]) {
                    dist[ne][cs+1] = dist[c][cs]+w;
                    pq.push({dist[ne][cs+1],{ne,cs+1}});
                }
            }
        }
    }

    cout<<*min_element(dist[n],dist[n]+55);
	return 0;
}
