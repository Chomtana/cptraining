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

piii El[200005];

struct djnode {
	int parent;
};

djnode djset[200005];

int find(int x) {
	if(djset[x].parent==x) return x;
	return djset[x].parent = find(djset[x].parent);
}

void un(int a,int b) {
	a = find(a);b=find(b);
	djset[a].parent=b;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n,m; 
	while(cin>>n>>m&&n!=0) {
		int allsum = 0;
		
		for1(i,0,n+5) {
			djset[i].parent = i;
		}
		
		for1(i,0,m) {
			int s,e,w; scanf("%d%d%d",&s,&e,&w);
			El[i] = mp(w,mp(s,e));
			allsum += w;
		}
		
		sort(El,El+m);
		
		int res = 0;
		
		for1(i,0,m) {
			int s = El[i].second.first;
			int e = El[i].second.second;
			int w = El[i].first;
			
			if (find(s)!=find(e)) {
				un(s,e);
				res += w;
			}
		}
		
		printf("%d\n",allsum-res);
	}
	return 0;
}
