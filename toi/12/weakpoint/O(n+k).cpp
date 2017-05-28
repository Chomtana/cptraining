/**
- groupgraph(articulation point) is tree
    -> can greedy in that respresentation (group graph normally greedy using connected component)

Greedy properties:
- Weak point is only articulation point
    if no articulation point then return (minimum i,1)
    else calculate from articulation point only
- Weak point must find first in each path from root (visualize in group graph for see better)
    - Block that points
    -> use flood fill (add group id to each node)
    -> for each possible weak points , count group that adjacent to weak point and not root group


*/

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

vector<vector<int>> E;
int T[500005];
int L[500005];
int t = 0;
bool A[500005]; //auto init as false
bool visited[500005]; //auto init as false
int G[500005];
int Gc[500005]; //auto init as 0
int currg = 0;
vector<int> block;

int currse;

int n,root;

int res = 0;

void docount(int curr) {
    if (visited[curr]) return;
    visited[curr] = true;
    res++;

    for1(i,0,E[curr].size()) {
        int ne = E[curr][i];
        docount(ne);
    }
}

void doarti(int c,int bf) {
    T[c] = L[c] = t++;

    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!visited[ne]) {
            visited[ne] = true;
            //mai tong necount++ pork lao exclude root
            doarti(ne,c);

            if (bf!=-1 && T[c]<=L[ne]) {
                A[c] = true;
            }

            if (ne!=bf) L[c] = min(L[c],L[ne]);
        } else {
            if (ne!=bf) L[c] = min(L[c],T[ne]);
        }
    }

    //exclude root -> if it is root always not arti point (always not select root)
}

void doblock() {
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for1(i,0,E[curr].size()) {
            int ne = E[curr][i];
            if (A[ne]) {
                block.push_back(ne);
            } else {
                if (!visited[ne]) {
                    visited[ne] = true;
                    q.push(ne);
                }
            }
        }
    }

    for1(i,0,n+1) visited[i] = false;
    for1(i,0,block.size()) visited[block[i]] = true;
}

void fill(int curr) {
    if (visited[curr]) return;
    visited[curr] = true;

    G[curr] = currg;
    Gc[currg]++;

    for1(i,0,E[curr].size()) {
        int ne = E[curr][i];
        fill(ne);
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>root;
    E.resize(n+5);

    for1(i,0,n) {
        int s,e,w; scanf("%d%d",&s,&e);
        E[s].push_back(e);
        E[e].push_back(s);
    }

    //doarti
    visited[root] = true;
    doarti(root,-1);
    int articount = 0;
    for1(i,1,n+1) {
        articount += A[i];
    }

    if (articount==0) {
        if (root==1) {
            cout<<"2\n0";
        } else {
            cout<<"1\n0";
        }
        return 0;
    }

    int currmax = 0;
    int maxi = 0;

    ///find first arti points from root -> block it
    for1(j,0,n+1) visited[j] = false;//reset visited
    doblock();

    ///fill color (fill group id for each node)
    for1(i,1,n+1) {
        if (!visited[i]) {
            fill(i);
            currg++;
        }
    }

    ///do calc result
    int rootg = G[root];

    //cerr<<block.size()<<endl;

    for1(i,0,block.size()) {
        vector<int> neg;
        int cres = 0;
        for1(j,0,E[block[i]].size()) {
            int ne = E[block[i]][j];
            if (G[ne]!=rootg) {
                neg.push_back(G[ne]);
            }
        }

        sort(all(neg));
        auto endit = unique(all(neg)); //unique will only 100% efficiency after sort
        for(auto it = neg.begin();it!=endit;it++) {
            cres += Gc[*it];
            //cerr<<*it<<' ';
        }
        //cerr<<endl;

        //cerr<<block[i]<<' '<<Gc[3]<<endl;

        if (cres>currmax) {
            currmax = cres;
            maxi = block[i];
        }
    }

    /*for1(i,1,n+1) {
        if (!A[i]) continue;
        if (i==root) continue;
        currse = i;
        for1(j,0,n+1) visited[j] = false;
        res = 0;
        visited[i] = true;
        docount(root);
        res = n-res-1;
        if (res>currmax) {
            currmax = res;
            maxi = i;
        }
    }*/

    cout<<maxi<<endl<<currmax;
	return 0;
}
