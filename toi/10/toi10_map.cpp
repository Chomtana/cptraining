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
typedef pair<int,pii> piii;
typedef vector<int> vi;

struct node {
	int left=-1,right=-1,up=-1,down=-1;
};

int nr,nc;
node data[50000];
map<piii,bool> visited;
map<pii,int> res;

int minr = 1E9;
int minc = 1E9;

void build(int p,int r,int c) {
	if (p==-1 || p==-1) return;
	
	if (visited[mp(p,mp(r,c))]) return;
	visited[mp(p,mp(r,c))] = true;
	
	res[mp(r,c)] = p;
	
	minr=min(minr,r);
	minc=min(minc,c);
	
	build(data[p].left,r,c-1);
	build(data[p].right,r,c+1);
	build(data[p].up,r-1,c);
	build(data[p].down,r+1,c);
}


int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>nr>>nc;
	for1(i,0,nr*nc-1) {
		int a,b; char cc[3]; scanf("%d %s %d",&a,cc,&b);
		char c = cc[0];
		if (c=='U') {
			data[b].up = a;
			data[a].down = b;
		} else if (c=='L') {
			data[b].left = a;
			data[a].right = b;
		}
	}
	
	build(0,0,0);
	
	for1(i,minr,minr+nr) {
		for1(j,minc,minc+nc) {
			printf("%d ",res[mp(i,j)]);
		}
		printf("\n");
	}
	
	//cerr<<minr<<' '<<minc<<endl;
	return 0;
}
