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
typedef pair<ll,pair<ll,pair<ll,ll>>> type;

int n,m,l,q;
vector<pair<ll,ll>> E[80005];
ll dist[80005][12]; //dist[...][...][p]
ll distnew[80005][12]; //dist[...][...][p+1]
vector<ll> has;
//short P[80005][12];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m>>l>>q;
    for1(i,0,m) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        E[s].emplace_back(e,w);
        //E[e].emplace_back(s,w);
    }

    has.push_back(-1);

    for1(i,0,l) {
        int x; scanf("%d",&x); has.push_back(x);
    }

    for1(i,0,n+5) {
        for1(j,0,12) {
            //fill(dist[i][j],dist[i][j]+11,1E9);
            dist[i][j] = 1E18L;
            distnew[i][j] = 1E18L;
        }
    }

    /*for1(i,0,n+5) {
        for1(j,0,12) {
            P[i][j] = -1;
        }
    }*/

    //P[1][0] = 0;
    distnew[1][0] = 0;

    ll res = 1E18L;

    for1(ps,0,q+1) {
        priority_queue<type,vector<type>,greater<type>> pq;
        //pq.push(mp(0,mp(1,mp(0,0))));
        //dist[1][0] = 0;
        for1(i,0,n+3) {
            for1(j,0,l+1) {
                dist[i][j] = distnew[i][j];
                distnew[i][j] = 1E18L;
                if (dist[i][j] != 1E18L) {
                    //dist[i][j] = 0;
                    pq.push(mp(dist[i][j],mp(i,mp(ps,j))));
                } else {
                    //dist[i][j] = 1E9;
                }
            }
        }
        while(!pq.empty()) {
            int c = pq.top().second.first;
            ll p = pq.top().second.second.first;
            ll last = pq.top().second.second.second;
            ll oldp = p;
            pq.pop();
            ll newlast = last;

            //greedy : must drink
            if (find(all(has),c)!=has.end() && has[last]!=c) {
                if (p<q) {
                    p++;
                    newlast = find(all(has),c)-has.begin();
                }
            }

            //cerr<<c<<" : ";

            for1(i,0,E[c].size()) {
                int ne = E[c][i].first;
                ll w = E[c][i].second/(1<<p);
                //cerr<<"aaa "<<c<<' '<<ne<<' '<<w<<endl;
                if (oldp==p) {
                    if (dist[c][last]+w<dist[ne][newlast]) {
                        dist[ne][newlast] = dist[c][last]+w;
                        //P[ne][newlast] = p;
                        pq.push(mp(dist[ne][newlast],mp(ne,mp(p,newlast))));
                    }
                } else {
                    if (dist[c][last]+w<distnew[ne][newlast]) {
                        distnew[ne][newlast] = dist[c][last]+w;
                        //P[ne][newlast] = p;
                        //pq.push(mp(distnew[ne][newlast],mp(ne,mp(p,newlast))));
                    }
                }
                //cerr<<ne<<' ';
            }

            //cerr<<endl;
        }

        for1(j,0,12) {
            //res = min(res,*min_element(dist[n][j],dist[n][j]+11));
            res = min(res,distnew[n][j]);
            res = min(res,dist[n][j]);
        }
    }

    /*cerr<<"aaa ";
    for1(i,0,n+1) {
        cerr<<P[i]<<' ';
    }
    cerr<<endl;*/

    /*for1(i,1,n+1) {
        cerr<<i<<' ';
        for1(j,0,9) {

            cerr<<dist[i][j]<<' ';
        }
        cerr<<endl;
    }*/
    cout<<res;
	return 0;
}
