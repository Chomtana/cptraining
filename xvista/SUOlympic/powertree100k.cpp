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

struct node {
	int left,right;
	int parent;
	int p;
};

node data[100005];
bool notroot[100005];
int root = -1;
//bool visited[100005];

void docache(int curr) {
	docache(data[curr]->left);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n,k; cin>>n>>k;
	
	for1(i,0,n) {
		int p,l,r; scanf("%d%d%d",&p,&l,&r);
		l--; r--;
		if (l!=-1) {
			data[i].left = l;
			notroot[l] = true;
		}
		if (r!=-1) {
			data[i].right = r;
			notroot[r] = true;
		}
	}
	
	for1(i,0,n) if(!notroot[i]) {
		root = i;
		break;
	}
	
	//cerr<<root;
	
	
	
	
	return 0;
}
