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

int data[105][10005];
int dist[105][10005];
bool visited[105][10005];

int nr,nc,k;

/*int bfs(int s) {
	dist[nr-1][s] = data[nr-1][s];
	visited[nr-1][s] = true;
	queue<pii> q;
	q.push(mp(nr-1,s));
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		
		for1(i,0,k+1) {
			int ner = r-1;
			int nec = c-i;
			if (ner>=0 and nec>=0 and ner<nr and nec<nc) {
				if (!visited[ner][nec]) {
					visited[ner][nec] = true;
					q.push(mp(ner,nec));
				}
				if (dist[r][c]+data[ner][nec]>dist[ner][nec]) {
					dist[ner][nec]=data[ner][nec]+dist[r][c];
				}
				//q.push(mp(ner,nec));
			}
			
			nec = c+i;
			if (ner>=0 and nec>=0 and ner<nr and nec<nc) {
				if (!visited[ner][nec]) {
					visited[ner][nec] = true;
					q.push(mp(ner,nec));
				}
				if (dist[r][c]+data[ner][nec]>dist[ner][nec]) {
					dist[ner][nec]=data[ner][nec]+dist[r][c];
				}
				//q.push(mp(ner,nec));
			}
		}
		
		
	}
}*/

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	 cin>>nr>>nc>>k;
	 memset(dist,-1,sizeof(dist));
	for1(i,0,nr) {
		for1(j,0,nc) {
			scanf("%d",&data[i][j]);
		}
	}
	
	//for1(i,0,nc) bfs(i);
	
	multiset<int> getter;
	
	for1(i,0,nc) dist[nr-1][i] = data[nr-1][i];
	for2(i,nr-2,0) {
		getter.clear();
		for1(x,0,k+1) {
			getter.insert(dist[i+1][x]);
		}
		dist[i][0] = *(--getter.end())+data[i][0];
		for1(j,1,nc) {
			if (j-k-1>=0) {
				getter.erase(getter.find(dist[i+1][j-k-1]));
			}
			if (j+k<nc) {
				getter.insert(dist[i+1][j+k]);
			}
			dist[i][j] = *(--getter.end())+data[i][j];
		}
	}
	
	/*cerr<<"DBG"<<endl;
	
	for1(i,0,nr) {
		for1(j,0,nc) {
			cerr<<dist[i][j]<<' ';
		}
		cerr<<endl;
	}*/
	
	cout<<*max_element(dist[0],dist[0]+nc);
	return 0;
}
