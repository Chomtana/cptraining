#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

#define dbgv(v) for1(i,0,v.size()) cerr<<v[i]<<' '; cerr<<endl;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define maxn 505

int n,m;
vector<int> E[maxn];
int P[maxn];
int L[maxn];
pii C[305];
pii El[205];
bool visited[maxn];
int LCAdp[maxn][105];
int LCA[maxn][maxn];

//cut edge that nearest to lca from start/end
//if we run from farthest to root (use lca) (from try all possible order) -> then cut edge nearest to lca is best : the word <lca> has special unknown relation (as of writing time)
int scut[305]; //scut[m] = (lca,...)
int ecut[305]; //ecut[m] = (lca,...)

int queryLCA(int p,int q) {
    if (L[p]<L[q]) {
        swap(p,q);
    }

    int lg = log2(maxn);

    for(int i = lg;i>=0;i--) {
        if (L[p]-(1<<i) >= L[q]) {
            p = LCAdp[p][i];
        }
    }

    if (p==q) return p;

    for(int i = lg;i>=0;i--) {
        if (LCAdp[p][i]!=-1 && LCAdp[p][i]!=LCAdp[q][i]) {
            p = LCAdp[p][i];
            q = LCAdp[q][i];
        }
    }

    return P[p];
}

void doLCA() {
    memset(LCAdp,-1,sizeof(LCAdp));

    for1(i,0,maxn) {
        LCAdp[i][0] = P[i];
    }

    for1(i,0,maxn) {
        for(int j = 0;(1<<j)<maxn;j++) {
            if (LCAdp[i][j-1]!=-1) {
                LCAdp[i][j] = LCAdp[LCAdp[i][j-1]][j-1];
            }
        }
    }

    //LCA full cache
    for1(i,0,maxn) {
        for1(j,0,maxn) {
            LCA[i][j] = queryLCA(i,j);
        }
    }
}

void dfs(int c,int p,int lv) {
    P[c] = p;
    L[c] = lv;

    for1(i,0,E[c].size()) {
        if (!visited[E[c][i]]) {
            visited[E[c][i]]=true;
            dfs(E[c][i],c,lv+1);
        }
    }
}

int res = 1000;
vector<pii> currE;
vector<pii> resE;
int cut[305];
vector<int> link[maxn][maxn];
int cutcount = 0;

bool mrun = false;

void dolink() {
    for1(i,0,m) {
        int s = C[i].first;
        int e = C[i].second;
        int lca = LCA[s][e];

        //cerr<<s<<' '<<e<<' '<<lca<<endl;

        if (s==e) {
            continue;
        }

        int bf = s;

        while (s!=lca) {
            s = P[s];
            if (s==lca) {
                scut[i] = bf;
            }
            link[bf][s].push_back(i);
            link[s][bf].push_back(i);
            bf = s;
        }

        bf = e;

        while (e!=lca) {
            e = P[e];
            if (e==lca) {
                ecut[i] = bf;
            }
            link[bf][e].push_back(i);
            link[e][bf].push_back(i);
            bf = e;
        }
    }
}

void select() {
    if (cutcount<res) {
        res = cutcount;
        resE = currE;
    }
    
}

void doscan(int s,int e,int val) {
    for1(i,0,link[s][e].size()) {
        //cerr<<"aaa "<<s<<' '<<e<<' '<<link[s][e][i]<<' '<<val<<endl;
        cut[link[s][e][i]] += val;
    }
}

bool check() {
    for1(i,0,m) {
        if (!cut[i]) return false;
    }
    return true;
}

void f(int curr) {
    /*cerr<<curr<<' '<<El[curr].first<<' '<<El[curr].second<<" : ";
    for1(i,0,cutcount) {
        cerr<<currE[i].first<<','<<currE[i].second<<' ';
    }
    cerr<<" : ";
    for1(i,0,m) {
        cerr<<cut[i]<<' ';
    }
    cerr<<endl;*/
    
    if (check()) {
        select();
        return;
    }
    
    if (curr>=n-1) {
        return;
    }
    if (cutcount>10) return;
    
    f(curr+1);
    
    cutcount++;
    doscan(El[curr].first,El[curr].second,1);
    currE.push_back({El[curr].first,El[curr].second});
    f(curr+1);
    cutcount--;
    doscan(El[curr].first,El[curr].second,-1);
    currE.pop_back();

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;
    for1(i,0,n-1) {
        int s,e; scanf("%d%d",&s,&e);
        E[s].push_back(e);
        E[e].push_back(s);
        El[i] = {s,e};
    }

    for1(i,0,m) {
        int s,e; scanf("%d%d",&s,&e);
        C[i] = {s,e};
        //cerr<<"aaa "<<i<<endl;
    }

    //cerr<<"aaa";

    memset(P,-1,sizeof(P));

    visited[1] = true;
    dfs(1,-1,1);

    doLCA();
    
    sort(C,C+m,[](pii &a,pii &b) {
        return L[LCA[a.first][a.second]]>L[LCA[b.first][b.second]];
    });

    dolink();
    
    /*for1(s,0,15) {
        for1(e,0,15) {
            if(link[s][e].size()>0) {
                cerr<<s<<' '<<e<<" : "; dbgv(link[s][e]);
            }
        }
    }*/
    
    /*for1(i,0,m) {
        cerr<<i<<' '<<scut[i]<<' '<<ecut[i]<<endl;
    }*/
    
    f(0);
    
    /*doscan(1,3,true);
    doscan(6,3,true);
    cerr<<" : ";
    for1(i,0,m) {
        cerr<<cut[i]<<' ';
    }
    cerr<<endl;*/
    
    //if (res==1000) while(true);
    //if (!mrun) while(true);
    
    cout<<res<<endl;
    for1(i,0,res) {
        cout<<resE[i].first<<' '<<resE[i].second<<endl;
    }

    /*for1(i,0,n+2) {
        cerr<<i<<' '<<P[i]<<' '<<L[i]<<endl;
    }*/

    /*for1(i,0,10) {
        for1(j,0,10) {
            cerr<<i<<' '<<j<<' '<<LCA[i][j]<<endl;
        }
    }*/

    //cout<<"aaa";
	return 0;
}