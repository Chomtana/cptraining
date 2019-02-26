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
int dist[1005][1005];

int main() {
    cout<<fixed;
    
    scanf("%d%d",&n,&m);
    for1(i,0,m) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        E[s].push_back({e,w});
    }
    
    for1(i,0,1005) for1(j,0,1005) dist[i][j] = 1e9;
    
    for1(k,1,n+1) {
        for1(i,1,n+1) {
            for1(j,1,n+1) {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    
    
        
    return 0;
}