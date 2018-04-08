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

int n;
vector<int> E[100005];

//LCA , 1 based
int lcadp[100005][25];
bool lcadfsvisited[100005];
int L[100005];
void lcadfs(int c,int p,int lv) {
    if (lcadfsvisited[c]) return;
    lcadfsvisited[c] = true;
    
    lcadp[c][0] = p;
    L[c] = lv;
    
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        lcadfs(ne,c,lv+1);
    }
}
void buildlcadp() {
    memset(lcadp,-1,sizeof(lcadp));
    lcadfs(1,-1,0);
    
    for(int j = 1;j<<1<=n;j++) for1(i,0,n+1) lcadp[i][j] = lcadp[lcadp[i][j-1]][j-1];
}
int lca(int a,int b) {
    if (L[a]<L[b]) swap(a,b);
    int log = 0;
    for(log=0;1<<log<=L[a];log++); log--;
    for(int i=log;i>=0;i--) if (L[a]-(1<<i)>=L[b]) a = lcadp[a][i];
    if (a==b) return a;
    for(int i=log;i>=0;i--) if (lcadp[a][i]!=-1 && lcadp[a][i]!=lcadp[b][i]) {
        a = lcadp[a][i]; b = lcadp[b][i];
    }
    return lcadp[a][0];
}

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    cin>>n;
    for1(i,0,n-1) {
        int s,e; scanf("%d%d",&s,&e);
        E[s].push_back(e);
        E[e].push_back(s);
    }
    
    buildlcadp();
    
    while (true) {
        int a,b; cin>>a>>b;
        printf("%d\n",lca(a,b));
    }
    return 0;
}
