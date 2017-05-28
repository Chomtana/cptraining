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

int dist[100005];
int lv[100005];
int parent[100005];
vector<vector<pii>> E;
//vector<int> gid;
int gid[100005];

int LCA(int a,int b) {
      int larger,smaller;
      if(lv[a]>lv[b])
        {larger=a;smaller=b;}
      else {larger=b;smaller=a;}
      while(lv[larger]!=lv[smaller])
         larger=parent[larger];
      while(larger!=smaller)
      {
          larger=parent[larger];
          smaller=parent[smaller];
      }
      return larger;//you can also return smaller here.
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,k; cin>>n>>k;
    E.resize(n);
    srand(time(0));
    //gid.resize(n);
    for1(i,0,n-1) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        E[s].push_back(mp(e,w));
        E[e].push_back(mp(s,w));
    }

    for1(i,0,n) {
        dist[i] = 1E9;
        lv[i] = 1E9;
    }

    int start = rand()%n;

    dist[0] = 0;
    gid[0] = 0;
    lv[0] = 0;

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for1(j,0,E[c].size()) {
            int ne = E[c][j].first;
            if (dist[ne]==1E9) {
                dist[ne] = dist[c]+E[c][j].second;
                lv[ne] = lv[c]+1;
                parent[ne] = c;
                if (c == 0) {
                    gid[ne] = j+1;
                } else {
                    gid[ne] = gid[c];
                }
                q.push(ne);
            }
        }

    }

    while (k--) {
        int s,e; scanf("%d%d",&s,&e);
        if (s==0) {
            printf("%d\n",dist[e]);
        } else {
            if (gid[s]==gid[e]) {
                printf("%d\n",dist[s]+dist[e]-2*dist[LCA(s,e)]);
            } else {
                printf("%d\n",dist[e]+dist[s]);
            }
        }
    }

	return 0;
}
