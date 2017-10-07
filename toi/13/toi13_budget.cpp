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

int n,m;
vector<pii> E[100005];
int dists[10005];
int diste[10005];

int ss,ee,b;

void dodists() {
    fill(dists,dists+n+5,1E9);
    dists[ss] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(mp(0,ss));
    while(!pq.empty()) {
        int c = pq.top().second;
        pq.pop();

        for1(i,0,E[c].size()) {
            int ne = E[c][i].first;
            if(dists[c]+E[c][i].second<dists[ne]) {
                dists[ne] = dists[c]+E[c][i].second;
                pq.push(mp(dists[ne],ne));
            }
        }
    }
}

void dodiste() {
    fill(diste,diste+n+5,1E9);
    diste[ee] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(mp(0,ee));
    while(!pq.empty()) {
        int c = pq.top().second;
        pq.pop();

        for1(i,0,E[c].size()) {
            int ne = E[c][i].first;
            if(diste[c]+E[c][i].second<diste[ne]) {
                diste[ne] = diste[c]+E[c][i].second;
                pq.push(mp(diste[ne],ne));
            }
        }
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m>>ss>>ee>>b;
    for1(i,0,m) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        E[s].push_back(mp(e,w));
        E[e].push_back(mp(s,w));
    }

    dodists();
    dodiste();

    if (dists[ee]<=b) {
        cout<<ee<<' '<<dists[ee]<<" 0\n";
    } else {
        int currmin = 1E9;
        int mini = -1;
        for1(i,0,n) {
            if (dists[i]<=b) {
                if (diste[i]<currmin) {
                    currmin = diste[i];
                    mini = i;
                }
            }
        }
        cout<<mini<<' '<<dists[mini]<<' '<<diste[mini]<<endl;
    }
	return 0;
}
