#
include < bits / stdc++.h > #define for1(i, j, k) for (int i = j; i <= k; ++i)# define eb emplace_back# define input()( * istream_iterator < int > (cin))
using namespace std;
const int lim = 5010;
int inc[lim], CC = 0;
bool v[lim] = {};
int fre[lim] = {};
int deg[lim] = {};
int ran[lim] = {};
vector < int > G[lim], GT[lim], GC[lim], tp;
stack < int > kos;
queue < int > q;
void dfs1(int now) {
    v[now] = true;
    for (auto i: G[now]) {
        if (not v[i]) {
            dfs1(i);
        }
    }
    kos.push(now);
}
void dfs2(int now) {
    v[now] = true;
    inc[now] = CC;
    for (auto i: GT[now]) {
        if (not v[i]) {
            dfs2(i);
        }
    }
}
int main() {
    int n = input();
    int p = input();
    for1(i, 1, p) {
        int a = input();
        int b = input();
        G[a].eb(b);
        GT[b].eb(a);
    }
    fill(v, v + lim, false);
    CC = 0;
    for1(i, 0, n - 1) {
        if (not v[i]) {
            dfs1(i);
        }
    }
    fill(v, v + lim, false);
    while (not kos.empty()) {
        int now = kos.top();
        kos.pop();
        if (not v[now]) {
            dfs2(now);
            CC++;
        }
    }
    //    printf("CC %d\n", CC);
    for1(i, 0, n - 1) {
        for (auto j: G[i]) {
            if (inc[i] == inc[j]) continue;
            GC[inc[i]].eb(inc[j]);
            deg[inc[j]]++;
        }
    }
    for1(i, 0, CC - 1) {
        if (deg[i] == 0) q.push(i);
    }
    while (not q.empty()) {
        int now = q.front();
        //        printf("now = %d\n", now);
        q.pop();
        tp.eb(now);
        for (auto i: GC[now]) {
            //            printf("%d %d\n",i , deg[i]);
            if (--deg[i] == 0) q.push(i);
        }
    }
    //     for1(i , 0 , n-1) printf("%d ",inc[i]);
    //     printf("\n");
    int low = 0;
    for (auto i: tp) {
        //            printf("%d\n" ,i);
        for (auto j: GC[i]) {
            ran[j] = max(ran[j], ran[i] + 1);
            low = max(low, ran[j]);
        }
    }
    for1(i, 0, n - 1) {
        fre[ran[inc[i]]]++;
    }
    for1(i, 0, low) {
        printf("%d ", fre[i]);
    }
}
