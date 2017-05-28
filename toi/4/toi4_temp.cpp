#include <queue>
#include <cstdio>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

int main() {
	int n,sc,sr; scanf("%d %d %d",&n,&sc,&sr);
	sc--; sr--;
	int data[n][n];
	bool visited[n][n];
	for1(i,0,n) for1(j,0,n) {scanf("%d",&data[i][j]); visited[i][j]=false;}
	//100 = forbid

	queue<pii> q;
	q.push(mp(sr,sc));
	visited[sr][sc] = true;
	int currmax = -100;
	while (!q.empty()) {
		int currr = q.front().first;
		int currc = q.front().second;
		q.pop();

		currmax = max(currmax,data[currr][currc]);

		int dr[] = {0,0,1,-1};
		int dc[] = {1,-1,0,0};

		for1(i,0,4) {
			int nextr = currr+dr[i];
			int nextc = currc+dc[i];

			if(nextr>=0 && nextr<n && nextc>=0 && nextc<n &&!visited[nextr][nextc] && data[nextr][nextc] != 100 && data[nextr][nextc]>data[currr][currc])
			q.push(mp(nextr,nextc));
			visited[nextr][nextc] = true;
		}
	}

	printf("%d",currmax);

	return 0;
}

/*
4
2 1
100 1 3 8
0 2 1 4
2 3 5 100
0 8 8 100
*/
