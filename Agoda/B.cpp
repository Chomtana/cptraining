#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nh,nt,v;
vector<vector<int>> E(2005);
vector<bool> visited(2005);
vector<int> V(2005);

void dfs(int curr) {
    for(auto &next: E[curr]) {
        V[curr]--;
        V[next]++;
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin>>t;
    while(t--) {
        for1(i,0,2005) {
            visited[i] = false;
            V[i] = 0;
            E.clear();
        }
        scanf("%d %d %d",&nh,&nt,&v);
        for1(i,0,v) {
            char c1; int id1;
            char c2; int id2;
            scanf(" %c%d %c%d", &c1,&id1,&c2,&id2);
            if (c1=='T') id1+=1000;
            if (c2=='T') id2+=1000;
            
            E[id1].push_back(id2);
        }
        
        for1(i,1,n+1) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(i);
            }
        }
        
        for1(i,1001,1001+n) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(i);
            }
        }
        
        
    }
    return 0;
}
