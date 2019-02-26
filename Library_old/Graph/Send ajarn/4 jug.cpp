//Brute force level 3 -> Algorithm tree brute force

#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

/*
Operations :
fill bucket 1 -> (n,j)
fill bucket 2 -> (i,m)
remove bucket 1 -> (0,j)
remove bucket 2 -> (i,0)
add to bucket 1 ; i+j<=n -> (i+j,0)
add to bucket 1 ; i+j>n -> (n,i+j-n)
add to bucket 2 ; i+j<=m -> (0,i+j)
add to bucket 2 ; i+j>m -> (i+j-m,m)
*/

class info {
    public:
    int i,j,type;

    info(int i,int j,int type) {
        this->i = i;
        this->j = j;
        this->type = type;
    }
};

ostream& operator << (ostream& os,info& a) {
    os<<a.i<<' '<<a.j<<endl;
    if (a.type==0) cout<<"Fill bucket 1 full";
    if (a.type==1) cout<<"Fill bucket 2 full";
    if (a.type==2) cout<<"Remove all water from bucket 1";
    if (a.type==3) cout<<"Remove all water from bucket 2";
    if (a.type==4) cout<<"Add water to bucket 1";
    if (a.type==5) cout<<"Add water to bucket 2";
    if (a.type==6) cout<<"End";
    cout<<endl;
    return os;
}

int n,m,t;

vector<vector<bool>> visited;

stack<info> path;

bool dfs(int i,int j) {
    if (i==t || j==t) {
        path.push(info(i,j,6));
        return true;
    }
    if (visited[i][j]) return false;
    visited[i][j] = true;
    if(dfs(n,j)) {path.push(info(i,j,0)); return true;}
    if(dfs(i,m)) {path.push(info(i,j,1)); return true;}
    if(dfs(0,j)) {path.push(info(i,j,2)); return true;}
    if(dfs(i,0)) {path.push(info(i,j,3)); return true;}
    if (i+j<=n) {
        if(dfs(i+j,0)) {path.push(info(i,j,4)); return true;}
    } else {
        if(dfs(n,i+j-n)) {path.push(info(i,j,4)); return true;}
    }
    if (i+j<=m) {
        if(dfs(0,i+j)) {path.push(info(i,j,5)); return true;}
    } else {
        if(dfs(i+j-m,m)) {path.push(info(i,j,5)); return true;}
    }
    return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m>>t;
    visited.resize(n+1,vector<bool>(m+1,false));
    dfs(0,0);

    while (!path.empty()) {
        cout<<path.top();
        path.pop();
    }
	return 0;
}
