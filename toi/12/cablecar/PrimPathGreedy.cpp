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
typedef pair<int,pii> piii;
typedef vector<int> vi;

piii El[1000005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n,m; cin>>n>>m;
	for1(i,0,m) {
		int s,e,w; scanf("%d%d%d",&s,&e,&w);
		El[i] = mp(w,mp(s,e));
	}
	
	sort(El,El+m
	
	return 0;
}
