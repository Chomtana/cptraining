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
typedef vector<vector<int>> vvi;

vvi E(1000005);
int n,m;

int main() {
    cout<<fixed;
    
    scanf("%d",&n);
    for1(i,0,n-1) {
        int s,e; scanf("%d%d",&s,&e);
        E[s].push_back(e);
    }
    
    vector<bool> visited(n+5);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        cout<<curr<<' ';
        
        for1(i,0,E[curr].size()) {
            int next = E[curr][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return 0;
}