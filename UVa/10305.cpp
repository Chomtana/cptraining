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

vector<vector<int>> E;
vector<bool> visited;
stack<int> st;

void toposort(int curr) {
	if (visited[curr]) return;
	visited[curr] = true;
	
	for1(i,0,E[curr].size()) {
		int ne = E[curr][i];
		toposort(ne);
	}
	
	st.push(curr); //only add this one line from normal compact dfs
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n,m;
	while(cin>>n>>m) {
		E.resize(n+5);
		visited.resize(n+5,false);
		//st.clear();
		
		for1(i,0,m) {
			int s,e; scanf("%d%d",&s,&e);
			//before -> after (left = before ... left->right ... a->b = E[a].push_back(b))
			E[s].push_back(e);
		}
		
		for1(i,1,n+1) {
			if(!visited[i]) toposort(i);
		}
		
		while (!st.empty()) {
			printf("%d ",st.top()); st.pop();
		}
		printf("\n");
		
		E.clear();
		visited.clear();
	}
	return 0;
}
