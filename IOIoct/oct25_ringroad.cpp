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

int n,k,q;
vector<pii> E[200005];
int ringw[200005];
int fw[200005];
int dist[200005];
int part[200005];

void dodjk(int s) {
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(mp(0,s));
    dist[s] = 0;
    while(!pq.empty()) {
        int c = pq.top().second;
        pq.pop();

        for1(i,0,E[c].size()) {
            int ne = E[c][i].first;
            int w = E[c][i].second;
            if (dist[c]+w<dist[ne]) {
                dist[ne] = dist[c]+w;
                pq.push(mp(dist[ne],ne));
            }
        }
    }
}

int query(int pos) {
    int res = 0;
    for(int i = pos;i>=1;i-=(i&(-i))) {
        res += fw[i];
    }
    return res;
}

int query(int s,int e) {
    return query(e)-(s>1?query(s-1):0);
}


void update(int pos,int val) {
    int delta = val-query(pos,pos);
    for(int i = pos;i<=k;i+=(i&(-i))) {
        fw[i] += delta;
    }
}

int ringdist(int s,int e) {
    if(s==e) return 0;
    return min(query(s,e-1),query(1,k)-query(s,e-1));
}


int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n>>k>>q;
	fill(dist,dist+n+5,1E9);

	for1(i,1,k+1) {
        int w; scanf("%d",&w);
        ringw[i] = w;
        part[i] = i;
        update(i,w);
	}

    for1(i,k+1,n+1) {
        int ne,w; scanf("%d%d",&ne,&w);
        E[i].emplace_back(ne,w);
        E[ne].emplace_back(i,w);
        if (ne<=k) {
            part[i] = ne;
        } else {
            part[i] = part[ne];
        }
    }

    for1(i,1,k+1) {
        dodjk(i);
    }

    while(q--) {
        int type,a,b; scanf("%d%d%d",&type,&a,&b);
        if (type==1) {
            int ringa = part[a];
            int ringb = part[b];
            if (ringa!=ringb) {
                int ringd = ringdist(min(ringa,ringb),max(ringa,ringb));
                printf("%d\n",ringd+dist[a]+dist[b]);
            } else {
                printf("%d\n",abs(dist[a]-dist[b]));
            }
        } else {
            update(a,b);
            //cerr<<query(1)<<endl;
        }
    }
	return 0;
}
