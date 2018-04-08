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

int n,m;
vector<pii> E[10005];
piii El[100005];
vector<pii> Emst[100005];
bool visited[10005];

int djset[10005];

int find(int a) {
    if (djset[a]==a) return a;
    return djset[a] = find(djset[a]);
}

void un(int a,int b) {
    a = find(a);
    b = find(b);
    djset[a] = b;
}

ll ans = 1e15L;

void dfs(int curr,int e,ll a) {
    int nextc = 0;
    for1(i,0,Emst[curr].size()) {
        int ne = Emst[curr][i].first;
        ll w = Emst[curr][i].second;
        if (!visited[ne]) {
            visited[ne] = true;
            nextc++;
            dfs(ne,e,max(a,w));
        }
    }
    
    //base case : find end
    if (curr == e) ans = a;
}

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    cin>>n>>m;
    
    for1(i,0,10005) djset[i]=i;
    
    for1(i,0,m) {
        int s,e; ll w; scanf("%d %d %lld",&s,&e,&w);
        E[s].emplace_back(e,w);
        E[e].emplace_back(s,w);
        El[i] = {w,{s,e}};
    }
    
    sort(El,El+m);
    
    for1(i,0,m) {
        int s = El[i].second.first;
        int e = El[i].second.second;
        ll w = El[i].first;
        
        if (find(s)!=find(e)) {
            Emst[s].emplace_back(e,w);
            Emst[e].emplace_back(s,w);
            un(s,e);
        }
    }
    
    /*for1(i,1,n+1) {
        printf("%d : ",i);
        for1(j,0,Emst[i].size()) printf("%d ",Emst[i][j]);
        printf("\n");
    }*/
    
    int t; cin>>t; while(t--) {
        int s,e; scanf("%d %d",&s,&e);
        fill(visited,visited+n+5,false);
        ans = 1e15L;
        visited[s] = true;
        dfs(s,e,0);
        printf("%lld\n",ans);
    }
    
    
    return 0;
}

/*
6 8
1 2 3
1 6 1
6 5 5
5 2 8
5 4 2
6 3 5
1 4 6
1 3 13
*/