#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

class Graph {
public:
    vector<vector<int>> E;
    vector<bool> visited;

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

    Graph(int n) {
        E.resize(n+5);
        visited.resize(n+5);
        ap.resize(n+5);
        parent.resize(n+5); //parent
        fill(all(parent), -1);//parent
        fwt.resize(n+5); //fwt
        low.resize(n+5); //low
        bwt.resize(n+5); //bwt
        ap.resize(n+5); //ap
    }

    void addEdge(int s,int e) {
        E[s].push_back(e);
    }

    void dbg() {
        for1(i,0,E.size()) {
            if (E[i].size() > 0) {
                cerr<<i<<" -> ";
                for1(j,0,E[i].size()) cerr<<E[i][j]<<' ';
                cerr<<endl;
            }
        }
    }

    void dfs(int curr) {
        int childcount = 0;
        visited[curr] = true;

        fwt[curr] = low[curr] = ++currfwt; //fwt, low

        cerr<<curr<<endl;
        for(auto &next: E[curr]) {
            if (!visited[next]) {
                childcount++;

                parent[next] = curr; //parent

                dfs(next);

                low[curr] = min(low[curr], low[next]); //low

                if (parent[curr] == -1 && childcount > 1) ap[curr] = true;
                if (parent[curr] != -1 && low[next] >= fwt[curr]) ap[curr] = true;
            } else if (next != parent[curr]) {
                low[curr] = min(low[curr], fwt[next]);
            }
        }

        bwt[curr] = ++currbwt;
    }

    void reset_visited() {
        fill(all(visited), false);
    }
};

int main() {
    Graph g(8);
    /*g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(0, 1);
    g.addEdge(2, 0);
    g.addEdge(1, 2);
    g.addEdge(3, 0);
    g.addEdge(4, 3);*/
    g.addEdge(1,3);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(0,1);
    g.addEdge(3,5);
    g.dbg();

    g.reset_visited();
    g.dfs(0);

    for1(i,0,g.E.size()) {
        //if (g.ap[i]) cerr<<i<<' ';
        cerr<<i<<' '<<g.fwt[i]<<' '<<g.bwt[i]<<endl;
    }
    cerr<<endl;
}
