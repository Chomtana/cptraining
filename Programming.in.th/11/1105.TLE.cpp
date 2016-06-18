#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;
#define debug1(a) cout<<(a)<<endl;
#define debug2(a,b) cout<<(a)<<' '<<(b)<<endl;
#define debug3(a,b,c) cout<<(a)<<' '<<(b)<<' '<<(c)<<endl;
#define debug4(a,b,c,d) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<' '<<(e)<<endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

bool gecomp(int a,int b) {
	return a>b;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n,k; scanf("%d %d",&n,&k);
	priority_queue< int,vector<int>,greater<int> > pq;
	for1(i,0,n) {
		int in; scanf("%d",&in);
		if (pq.size()<k||in>=pq.top()) pq.push(in);
	}
	
	int x = pq.size()-k;
	while (x--) pq.pop();
	cout<<pq.top();
	
	return 0;
}