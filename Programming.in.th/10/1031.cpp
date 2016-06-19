#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<c;(a)++)

using namespace std;

struct node {
	vector<int> next;
};

int main() {
	int k,n,m; cin>>k>>n>>m;
	node V[n];
	int d[n]; //min dist
	fill(d,d+n,1000000000);
	d[0]=0;
	for1(i,0,m) {
		int s,e; cin>>s>>e; s--; e--;
		//s->e
		V[s].next.push_back(e);
	}

	//bool visited[n]; fill(visited,visited+n,false);
	queue<int> q;
	int c = 0;
	q.push(c);
	do {
		c = q.front();
		q.pop();
		//visited[c] = true;

		for1(i,0,V[c].next.size()) {
			int e = V[c].next[i];
			if (d[c]+1<d[e]) {
				d[e] = d[c]+1;
				if (d[e]<k) q.push(e);
			}
		}

	} while (!q.empty());

	int res = 0;
	for1(i,0,n) {
		if (d[i]<=k) {
			res = max(res,i);
		}
	}

	cout<<res+1;
	return 0;
}
