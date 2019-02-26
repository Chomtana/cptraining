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
typedef vector<vector<int>> vvi;

vector<vector<pii>> E(1000000);
int n,m;

int main() {
    cout<<fixed;
    
    scanf("%d%d",&n,&m);
    for1(i,0,m) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        E[s].push_back({e,w});
    }
    
    vi dist(n+5,1e9);
    dist[1] = 0;
    for1(_,0,n-1) {
        for1(s,1,n+1) {
            for1(i,0,E[s].size()) {
                int e = E[s][i].first;
                if (dist[s] != 1e9 && dist[s]+E[s][i].second < dist[e]) {
                    dist[e] = dist[s]+E[s][i].second;
                }
            }
        }
    }
    
    bool hasnegcy = false;
    for1(s,1,n+1) {
        for1(i,0,E[s].size()) {
            int e = E[s][i].first;
            if (dist[s] != 1e9 && dist[s]+E[s][i].second < dist[e]) {
                hasnegcy = true;
                break;
            }
        }
        if (hasnegcy) break;
    }
    
    
        
    return 0;
}