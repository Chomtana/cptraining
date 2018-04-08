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

struct smnode {
    smnode* l = NULL;
    smnode* r = NULL;
    int val = -1e9-5;
    
    smnode() {}
    
    smnode(int val) {
        this->val = val;
    }
    
    smnode(smnode* l,smnode* r): l(l), r(r), val(-1e9-5) {
        if (l) val = max(val,l->val);
        if (r) val = max(val,r->val);
    }
    
    smnode(smnode* l,smnode* r,int val) {
        this->l = l;
        this->r = r;
        this->val = val;
    }
};

int n,m;
vector<pii> E[10005];
map<pii,int> W;
piii El[100005];
vector<pii> Emst[100005];
int L[10005];
bool visited[10005];
int nodei[10005];

int djset[10005];

smnode* sm[10005]; //sm[nodei]

int find(int a) {
    if (djset[a]==a) return a;
    return djset[a] = find(djset[a]);
}

void un(int a,int b) {
    a = find(a);
    b = find(b);
    djset[a] = b;
}

int ans = 1e9+5;

int merge(int a,int b) {
    return max(a,b);
}

smnode* buildroot(int s,int e) {
    if (s==e) return new smnode(-1e9-5);
    int mid = (s+e)>>1;
    return new smnode(buildroot(s,mid),buildroot(mid+1,e));
}

smnode* update(smnode* i,int s,int e,int p,int val) {
    if (s==e) return new smnode(val);
    int mid = (s+e)>>1;
    if (p<=mid) return new smnode(update(i->l,s,mid,p,val),i->r);
    else return new smnode(i->l,update(i->r,mid+1,e,p,val));
}

smnode* update(smnode* i,int p,int val) {
    return update(i,0,n,p,val);
}

int query(smnode* i,int s,int e,int ts,int te) {
    if (s>=ts && e<=te) return i->val;
    if (e<ts || s>te) return -1e9;
    int mid = (s+e)>>1;
    return max(query(i->l,s,mid,ts,te),query(i->r,mid+1,e,ts,te));
}

int query(smnode* i,int ts,int te) {
    return query(i,0,n,ts,te);
}

void psmtree(smnode* i,int lv) {
    //for1(i,0,lv) printf("*"); printf("%lld\n",i->val);
    if (i->l==NULL && i->r==NULL) printf("%lld\n",i->val);
    if (i->l!=NULL) psmtree(i->l,lv+1);
    if (i->r!=NULL) psmtree(i->r,lv+1);
}

int lcadp[10005][25];

void buildsm(int c,int p,int lv) {
    nodei[c] = lv;
    L[c] = lv;
    
    //printf("ERR %d %d %d\n",c,p,0);
    
    lcadp[c][0] = p;
    
    if (p!=-1) {
        sm[c] = update(sm[p],lv,W[{p,c}]);
    } else {
        sm[c] = buildroot(0,n);
    }
    
    for1(i,0,Emst[c].size()) {
        int ne = Emst[c][i].first;
        int w = Emst[c][i].second;
        if (!visited[ne]) {
            visited[ne] = true;
            buildsm(ne,c,lv+1);
        }
    }
}

void dfs(int curr,int e,int a) {
    int nextc = 0;
    for1(i,0,Emst[curr].size()) {
        int ne = Emst[curr][i].first;
        int w = Emst[curr][i].second;
        if (!visited[ne]) {
            visited[ne] = true;
            nextc++;
            dfs(ne,e,max(a,w));
        }
    }
    
    //base case : find end
    if (curr == e) ans = a;
}

void buildlcadp() {
    //base case already done in buildsm function
    //lca[i][j] = lca[lca[i][j-1]][j-1];
    for(int j = 1;1<<j<n+1;j++) for1(i,1,n+1) lcadp[i][j] = lcadp[lcadp[i][j-1]][j-1];
}

int lca(int a,int b) {
    if (L[a]<L[b]) swap(a,b);
    int lg = 1; for(lg=1;1<<lg<=L[a];lg++); lg--;
    for(int i = lg;i>=0;i--) if (L[a]-(1<<i)>=L[b]) a = lcadp[a][i];
    if (a==b) return a;
    for(int i = lg;i>=0;i--) if (lcadp[a][i]!=-1 && lcadp[a][i]!=lcadp[b][i]) a = lcadp[a][i], b = lcadp[b][i];
    return lcadp[a][0];
}

int findans(int s,int e) {
    if (s==e) return 0;
    return query(sm[e],nodei[s]+1,nodei[e]);
}

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    cin>>n>>m;
    
    for1(i,0,10005) djset[i]=i;
    
    for1(i,0,m) {
        int s,e,w; scanf("%d %d %d",&s,&e,&w);
        E[s].emplace_back(e,w);
        E[e].emplace_back(s,w);
        El[i] = {w,{s,e}};
        W[{s,e}] = w;
        W[{e,s}] = w;
    }
    
    sort(El,El+m);
    
    for1(i,0,m) {
        int s = El[i].second.first;
        int e = El[i].second.second;
        int w = El[i].first;
        
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
    
    memset(lcadp,-1,sizeof(lcadp));
    
    fill(visited,visited+10005,false);
    visited[1] = true;
    buildsm(1,-1,0);
    
    buildlcadp();
    
    /*for1(i,1,n+1) {
        printf("SMTREE #%d\n",i);
        psmtree(sm[i],0);
        puts("");
    }*/
    
    /*for1(i,1,n+1) {
        for1(j,1,n+1) {
            printf("%d %d : %d\n",i,j,lca(i,j));
        }
    }*/
    
    int t; cin>>t; while(t--) {
        int s,e; scanf("%d %d",&s,&e);
        int l = lca(s,e);
        
        printf("%d\n",max(findans(l,s),findans(l,e)));
        
        
        /*fill(visited,visited+n+5,false);
        ans = 1e15L;
        visited[s] = true;
        dfs(s,e,0);
        printf("%lld\n",ans);*/
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