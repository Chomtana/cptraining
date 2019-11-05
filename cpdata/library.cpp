#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef pair<int,int> pii;

class dsunode {
public:
    int value;
    int parent;
};

class DSU {
public:
    vector<dsunode> node;
    int n;

    DSU() {}

    DSU(int nn) {
        n = nn;
        node.resize(n);
        for1(i,0,n) node[i].parent = i;
    }

    int find(int x) {
        if (node[x].parent == x) return x;
        return node[x].parent = find(node[x].parent);
    }

    void un(int a, int b) {
        a = find(a);
        b = find(b);

        node[a].parent = b;
    }
};

class Graph {
public:
    vector<vector<int>> E;
    vector<vector<pii>> EW; //edge with weight
    vector<bool> visited;

    //transpose
    vector<vector<int>> ET;

    //parent
    vector<int> parent;

    // fwt time (forward time)
    vector<int> fwt;
    int currfwt = 0;

    // Low time (require fwt time)
    vector<int> low;

    // bwt time (backward time)
    vector<int> bwt;
    int currbwt = 0;

    // Articulation Point plugins
    // Require: parent, fwt, low
    vector<bool> ap;

    // Bridge
    // Require: parent, fwt, low
    vector<pii> bridge;

    // pathstack
    stack<int> pathstack;

    // toposort
    // Require: pathstack
    vector<int> topo;

    // scc (keep root)
    // Require: pathstack
    vector<int> scc;
    vector<int> sccRep;

    // scc groups
    // Require: scc <- pathstack
    vector<vector<int>> sccgroup;
    int sccgroup_curr = 0;

    // scc DAG
    vector<vector<int>> sccE;

    // dist
    map<int, vector<int>> dist;

    // mst
    DSU mstdsu;
    vector<vector<pii>> Emst;
    int mstcost = 0;

    int n;

    Graph(int nn) {
        n = nn;
        E.resize(n);
        EW.resize(n); //edge with weight
        ET.resize(n); //transpose
        visited.resize(n);
        ap.resize(n);
        parent.resize(n); //parent
        fill(all(parent), -1);//parent
        fwt.resize(n); //fwt
        low.resize(n); //low
        bwt.resize(n); //bwt
        ap.resize(n); //ap
        sccRep.resize(n); //scc representator
        sccE.resize(n); //scc edge
        mstdsu = DSU(n); //mst
        Emst.resize(n); //mst edge
    }

    void addEdge(int s,int e,int w) {
        E[s].push_back(e);
        EW[s].push_back({e,w});
        ET[e].push_back(s);
    }

    void addEdge(int s,int e) {
        addEdge(s,e,1);
    }

    void dbg() {
        for1(i,0,n) {
            if (E[i].size() > 0) {
                cerr<<i<<" -> ";
                for1(j,0,E[i].size()) cerr<<E[i][j]<<' ';
                cerr<<endl;
            }
        }
    }

    void reset_visited() {
        fill(all(visited), false);
    }

    void dfs_inner(int curr) {
        int childcount = 0;
        visited[curr] = true;

        fwt[curr] = low[curr] = ++currfwt; //fwt, low

        //cerr<<curr<<endl;
        for(auto &next: E[curr]) {
            if (!visited[next]) {
                childcount++;

                parent[next] = curr; //parent

                dfs_inner(next);

                low[curr] = min(low[curr], low[next]); //low

                if (parent[curr] == -1 && childcount > 1) ap[curr] = true;
                if (parent[curr] != -1 && low[next] >= fwt[curr]) ap[curr] = true;
                if (low[next] > fwt[curr]) bridge.push_back({curr, next});
            } else if (next != parent[curr]) {
                low[curr] = min(low[curr], fwt[next]);
            }
        }

        bwt[curr] = ++currbwt; //backward time

        pathstack.push(curr); //pathstack
    }

    void scc_part2(int curr) {
        visited[curr] = true;
        sccRep[curr] = scc.back();
        sccgroup[sccgroup_curr].push_back(curr); // scc group
        for(auto &next: ET[curr]) {
            if (!visited[next]) scc_part2(next);
            else { // scc DAG
                sccE[scc.back()].push_back(next);
            }
        }
    }

    void dfs() {
        reset_visited();
        for1(i,0,n) {
            if (!visited[i]) {
                dfs_inner(i);
            }
        }

        //toposort
        reset_visited(); //scc
        while(!pathstack.empty()) {
            int start = pathstack.top();
            topo.push_back(start);
            pathstack.pop();

            //scc
            if (!visited[start]) {
                sccgroup.resize(sccgroup_curr+1);
                scc.push_back(start);
                scc_part2(start);
                sccgroup_curr++;
            }
        }

        // scc DAG
        for1(i,0,n) {
            for(auto &x:sccE[i]) {
                x = sccRep[x];
            }
        }
    }

    void floyd() {
        for1(i,0,n) dist[i].resize(n);
        for1(i,0,n) for1(j,0,n) dist[i][j] = 1e9;
        for1(s,0,n) for1(i,0,EW[s].size())
            dist[s][EW[s][i].first] = EW[s][i].second;

        for1(k,0,n) {
            for1(i,0,n) {
                for1(j,0,n) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    void dijkstra(int start) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for1(i,0,n) {
            dist[start].resize(n);
            dist[start][i] = 1e9;
        }
        dist[start][start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            int curr = pq.top().second;
            pq.pop();

            for(auto& nextp: EW[curr]) {
                int next = nextp.first;
                int w = nextp.second;
                if (dist[start][curr] + w < dist[start][next]) {
                    dist[start][next] = dist[start][curr] + w;
                    pq.push({dist[start][next], next});
                }
            }
        }
    }

    void mst() {
        vector<pair<int, pii>> Elist;
        for1(s,0,n) {
            for(auto& ew:EW[s]) {
                Elist.push_back({ew.second, {s, ew.first}});
            }
        }

        sort(all(Elist));

        for(auto& edge: Elist) {
            int s = edge.second.first;
            int e = edge.second.second;
            int w = edge.first;
            if (mstdsu.find(s) != mstdsu.find(e)) {
                mstcost += w;
                Emst[s].push_back({e, w});
                Emst[e].push_back({s, w});
                mstdsu.un(s,e);
            }
        }
    }

};

class Tree {
public:
    vector<vector<int>> E;
    vector<vector<pii>> EW;

    vector<bool> visited;

    vector<int> level;
    vector<vector<int>> P; //parent, lcacache

    int n;

    Tree(int nn) {
        n = nn;
        E.resize(n);
        EW.resize(n); //weighted
        visited.resize(n);

        //parent system (for lca, ...)
        level.resize(n);
        P.resize(n, vector<int>( ceil(log2(n)) + 1, -1 ));
    }

    void addEdge(int s,int e) {
        E[s].push_back(e);
    }

    void reset_visited() {
        fill(all(visited), false);
    }

    void dfs_inner(int curr, int parent) {
        visited[curr] = true;
        P[curr][0] = parent;
        for(int j = 1; (1<<j) < n; j++)
            P[curr][j] = P[P[curr][j-1]][j-1];
        for(auto& next: E[curr]) {
            if (!visited[next]) {
                level[next] = level[curr] + 1;
                dfs_inner(next, curr);
            }
        }
    }

    void dfs() {
        reset_visited();
        dfs_inner(0, 0);
    }

    int lca(int u, int v) {
        if (level[u] < level[v]) swap(u, v);

        int lg = ceil(log2(n));

        for (int i = lg; i >= 0; i--) {
            if (level[u] - (1<<i) >= level[v]) u = P[u][i];
        }

        if (u==v) return u;

        for (int i = lg; i >= 0; i--) {
            if (P[u][i] != P[v][i]) {
                u = P[u][i];
                v = P[v][i];
            }
        }

        return P[u][0];
    }
};

int main() {
    int t; cin>>t;
    for1(_,1,t+1) {
        int n; scanf("%d",&n);
        Tree g(n);
        for1(i,0,n) {
            int m; scanf("%d",&m);
            for1(j,0,m) {
                int e; scanf("%d", &e);
                e--;
                g.addEdge(i,e);
                g.addEdge(e,i);
            }
        }

        g.dfs();

        int q; scanf("%d", &q);
        printf("Case %d:\n", _);
        while (q--) {
            int s,e; scanf("%d %d", &s, &e);
            s--; e--;
            printf("%d\n",g.lca(s,e)+1);
        }
    }
}
