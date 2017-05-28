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
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m; cin>>n>>m;
    vector<vector<pii>> E(n+1);
    for1(i,0,m) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        E[s].push_back(mp(e,w));
        E[e].push_back(mp(s,w));
    }

    int s,e,people; scanf("%d%d%d",&s,&e,&people);

    int dist[n+5];
    fill(dist,dist+n+5,-1E9);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(mp(1E9,s));
    dist[s] = 1E9;
    while (!q.empty()) {
        int c = q.top().second;
        q.pop();

        for1(i,0,E[c].size()) {
            int ne = E[c][i].first;
            int w = E[c][i].second;
            if (min(dist[c],w)>dist[ne]) {
                dist[ne] = min(dist[c],w);
                q.push(mp(dist[ne],ne));
            }
        }

    }

    int perround = dist[e];
    /**
    want n round
    assume what we want : assume must use n round
    if use n round -> has people+n people
    then it must use (people+n)/perround round
    n = (people+n)/perround
    perround*n = people+n
    perround*n - n = people
    n(perround-1) = people
    n = people/(perround-1)
    */
    cout<<(people%(perround-1)==0?people/(perround-1):people/(perround-1)+1);
	return 0;
}
