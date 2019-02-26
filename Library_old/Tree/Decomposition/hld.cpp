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

int chainNo=0,chainHead[N],chainPos[N],chainInd[N],chainSize[N];
void hld(int cur) {
    if(chainHead[chainNo] == -1) chainHead[chainNo]=cur;
    chainInd[cur] = chainNo;
    chainPos[cur] = chainSize[chainNo];
    chainSize[chainNo]++;

    int ind = -1,mai = -1;
    for(int i = 0; i < adj[cur].sz; i++) {         if(subsize[ adj[cur][i] ] > mai) {
            mai = subsize[ adj[cur][i] ];
            ind = i;
        }
    }

    if(ind >= 0) hld( adj[cur][ind] );

    for(int i = 0; i < adj[cur].sz; i++) {
        if(i != ind) {
            chainNo++;
            hld( adj[cur][i] );
        }
    }
}

int query_up(int u, int v) {
    int uchain, vchain = chainInd[v], ans = -1;

    while(1) {
        if(uchain == vchain) {
            int cur = query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
            if( cur > ans ) ans = cur;
            break;
        }
        int cur = query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
        if( cur > ans ) ans = cur;
        u = chainHead[uchain];
        u = parent(u);
    }
    return ans;
}

int query(int u, int v) {
    int lca = LCA(u, v);
    return max( query_up(u, lca), query_up(v, lca) );
}




int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;

    return 0;
}
