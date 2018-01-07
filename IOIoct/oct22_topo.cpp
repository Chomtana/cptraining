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

int n,m;
vector<int> E[100005];

stack<int> topo;
int visited[100005];
bool cycle = false;

void dfs(int c) {
    if (cycle) return;
    visited[c] = 1;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];

        if (visited[ne]==0) {
            //cerr<<"bbb "<<c<<' '<<ne<<endl;
            visited[ne] = 1;
            dfs(ne);
        } else if (visited[ne]==1) {
            //cerr<<ne<<endl;
            cycle = true;
            return;
        }
    }
    visited[c] = 2;

    //cerr<<"aaa "<<c<<endl;

    topo.push(c);
    //printf("%d",c);
    //jing jing mang tum tong ne leoi kor dai mai tong push
    //tong ne = post order traversal = toposort
    //ta tum tong ne mun kor ja run order tarm toposort

    //tae hear ne mang hai har wa mang me cycle ? -> tong push
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;
    for1(i,0,m) {
        int s,e; scanf("%d%d",&s,&e);
        E[s].push_back(e);
    }

    for1(i,1,n+1) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i);
        }
    }

    if(cycle) {
        cout<<"no";
    } else {
        while (!topo.empty()) { printf("%d\n",topo.top()); topo.pop(); }
    }
	return 0;
}
