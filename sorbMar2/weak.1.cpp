#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;

template<int size,int vercount>
class smtree {
    public:
    
    int basecase = 1e9;
    int antians = basecase;
    //int n = size;
    
    static int merge(int a,int b) {
        //if (min(a,b)==0) printf("aaa\n");
        return min(a,b);
    }
    
    struct smnode {
        smnode* l = NULL;
        smnode* r = NULL;
        int val = 1e9;
        
        smnode() {}
        smnode(int val): l(NULL), r(NULL), val(val) {}
        smnode(smnode* l,smnode* r): l(l), r(r), val(1e9) {
            if (l) val = merge(val,l->val);
            if (r) val = merge(val,r->val);
        }
        smnode(smnode* l,smnode* r,int val): l(l), r(r), val(val) {}
        
        int query(int s,int e,int ts,int te) {
            if (s>=ts && e<=te) return this->val;
            if (e<ts || s>te) return 1e9;
            int mid = (s+e)>>1;
            return merge(this->l->query(s,mid,ts,te),this->r->query(mid+1,e,ts,te));
        }
        
        int query () {
            return this->val;
        }
        
        int query (int ts,int te) {
            return query(0,n,ts,te);
        }
        
        smnode* update(int s,int e,int pos,int val) {
            if (s==e) return new smnode(val);
            int mid = (s+e)>>1;
            if (pos<=mid) return new smnode(this->l->update(s,mid,pos,val),this->r);
            else return new smnode(this->l,this->r->update(mid+1,e,pos,val));
        }
        
        smnode* update(int pos,int val) {
            return update(0,n,pos,val);
        }
        
        void dbg() {
            //if (this->l==NULL && this->r==NULL) {
                printf("%d ",this->val);
            //}
            if (this->l!=NULL) this->l->dbg();
            if (this->r!=NULL) this->r->dbg();
        }
    };
    
    smnode* sm[vercount+5];
    
    smnode* buildbase(int s,int e) {
        if (s==e) {
            return new smnode(1e9);
        } else {
            int mid = (s+e)>>1;
            return new smnode(buildbase(s,mid),buildbase(mid+1,e));
        }
    }
    
    smnode* buildbase() {
        return buildbase(0,n);
    }
    
    smnode* build(int i,int s,int e,int *data) {
        if (s==e) {
            return new smnode(data[s]);
        } else {
            int mid = (s+e)>>1;
            return new smnode(build(s,mid,data),build(mid+1,e,data));
        }
    }
    
    smnode* build(int *data) {
        return new smnode(build(0,n,data));
    }
    
    smnode*& operator [](int i) {
        return sm[i];
    }
};

//smtree<100005,100005> sm;
vector<pii> E[100005];
int P[100005];
//int L[100005];
int W[100005];
//int lcadp[100005][25];
int A[60005];

ll q,m,k;

/*void dfs(int c,int p,int lv) {
    lcadp[c][0] = p;
    
    cerr<<c<<' '<<p<<' '<<lv<<endl;
    
    if (p!=-1) {
        sm[c] = sm[p]->update(lv,W[c]);
    }
    
    for(int i = 0;i<E[c].size();i++) {
        dfs(E[c][i].first,c,lv+1);
    }
}*/

/*int lca(int a,int b) {
    if (L[a]<L[b]) {
        swap(a,b);
    }
    for(int i = 20;i>=0;i--) {
        if (L[a]-(1<<i)>=L[b]) {
            a = lcadp[a][i];
        }
    }
    if (a==b) return a;
    for(int i = 20;i>=0;i--) {
        if (lcadp[a][i]!=-1 && lcadp[a][i]!=lcadp[b][i]) {
            a = lcadp[a][i];
            b = lcadp[b][i];
        }
    }
    return lcadp[a][0];
}*/

//1 based
int lcadp[100005][25];
bool lcadfsvisited[100005];
int L[100005];
void lcadfs(int c,int p,int lv) {
    if (lcadfsvisited[c]) return;
    lcadfsvisited[c] = true;
    
    lcadp[c][0] = p;
    L[c] = lv;
    
    for1(i,0,E[c].size()) {
        int ne = E[c][i].first;
        lcadfs(ne,c,lv+1);
    }
}
void buildlcadp() {
    memset(lcadp,-1,sizeof(lcadp));
    lcadfs(1,-1,0);
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

ll nea(ll ai1,ll ans) {
    return ((k*ai1+ans)%m)%n;
}

/*int query2(int a,int b) {
    if (a==b) return 1e9;
    return sm[b]->query(L[a]+1,L[b]);
}*/

int query(int a,int b) {
    int p = lca(a,b);
    if (p==0 || p==-1) {
        cout<<1/0;
    }
    int ans = 1e9;
    while (a!=p) {
        ans = min(ans,W[a]);
        a = P[a];
    }
    while (b!=p) {
        ans = min(ans,W[b]);
        b = P[b];
    }
    //return min(query2(p,a),query2(p,b));
    return ans;
}

int main() {
    //cout<<1/0;
    cin>>n;
    W[0] = 1e9;
    for1(i,2,n+1) {
        int p,w; scanf("%d%d",&p,&w); p++;
        P[i] = p;
        E[p].emplace_back(i,w);
        E[i].emplace_back(p,w);
        W[i] = w;
    }
    
    //sm[1] = sm.buildbase();
    
    memset(lcadp,-1,sizeof(lcadp));
    
    //dfs(1,-1,0);
    
    /*for1(i,1,21) {
        for1(j,1,n) {
            lcadp[j][i] = lcadp[lcadp[j][i-1]][i-1];
        }
    }*/
    
    buildlcadp();
    
    /*for1(i,0,10) {
        for1(j,1,n+1) {
            printf("LCADP %d %d : %d\n",j,i,lcadp[j][i]);
        }
    }*/
    
    /*for1(i,1,n+1) {
        for1(j,i+1,n+1) {
            cerr<<"LCA "<<i<<' '<<j<<" : "<<lca(i,j)<<endl;
        }
    }*/
    
    /*for1(i,1,n+1) {
        sm[i]->dbg();
        printf("\n");
    }*/
    
    /*for1(i,1,n+1) {
        for1(j,i+1,n+1) {
            //cerr<<"ANS "<<i<<' '<<j<<" : "<<query(i,j)<<endl;
            printf("ANS %d %d : %d\n",i,j,query(i,j));
        }
    }*/
    
    cin>>q>>k>>m;
    cin>>A[1]>>A[2];
    for1(i,3,q+3) {
        int a = min(A[i-2]+1,A[i-1]+1);
        int b = max(A[i-2]+1,A[i-1]+1);
        ll ans = (A[i-2]==A[i-1]?0:query(a,b));
        printf("%d\n",ans);
        A[i] = nea(A[i-1],ans);
    }
    return 0;
}