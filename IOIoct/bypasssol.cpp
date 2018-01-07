/*
TASK: o58_oct_c1_bypass
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<int> g[100005];
pii d[100005][2]; //d[n] = ((max1 of node n,node that has max),(max2 of node n,node that has max))
int n;
bool chk[100005]; //visited
int dfs(int idx){
    if(chk[idx])return 0; //visited
    chk[idx] = true; //visited
    int sum = 1;
    int prev; //previous = last visited
    for(auto &i:g[idx]){ //foreach next
        int now = dfs(i);
        sum+=now;
        if(now == 0){ //if visited
            prev = i; //previous = last visited
            continue;
        }
        //if not visited (has ans)
        pii x = pii(now,i);
        if(x>d[idx][0])swap(x,d[idx][0]);
        if(x>d[idx][1])swap(x,d[idx][1]);
    }
    if(idx!=1){ //if not root
        pii x = pii(n-sum,prev); //(inv sum,last visited)
        if(x>d[idx][0])swap(x,d[idx][0]);
        if(x>d[idx][1])swap(x,d[idx][1]);
    }
    //printf("-->%d %d\n",idx,sum);
    //printf("%d %d\n",d[idx][0].first,d[idx][0].second);
    //printf("%d %d\n",d[idx][1].first,d[idx][1].second);
    return sum; //one way sum
}
int main(){
    scanf("%d",&n);
    vector<pii> edge;
    for(int i = 1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back(pii(u,v));
    }
    dfs(1);
    long long mx = 0;
    for(auto &now:edge){ //for each edge
        int u = now.first,v = now.second;
        int a1,a2;
        if(d[u][0].second != v) a1 = d[u][0].first;
        else a1 = d[u][1].first;
        if(d[v][0].second != u) a2 = d[v][0].first;
        else a2 = d[v][1].first;
        //printf("%d %d::%d %d\n",u,v,a1,a2);
        mx = max(mx,(long long)a1*a2);
    }
    printf("%lld",mx);
}

//in distance 4 : prev foreach foreach prev
//mang kod hod sud
