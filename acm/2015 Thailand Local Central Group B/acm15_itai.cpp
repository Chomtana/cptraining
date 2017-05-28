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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
        int n,m,k; scanf("%d %d %d",&n,&m,&k);
        vector<vector<int>> E(n+1);
        for1(i,0,m) {
            int s,e; scanf("%d %d",&s,&e);
            E[s].push_back(e);
            E[e].push_back(s);
        }

        vector<bool> visited(n+1);

        while(k--) {
            int s; scanf("%d",&s);
            visited[s] = true;
            for(int &e:E[s]) {
                visited[e] = true;
            }
        }

        int res = 0;
        for1(i,0,n+1) res+=visited[i];
        printf("%d\n",res);
    }
	return 0;
}
