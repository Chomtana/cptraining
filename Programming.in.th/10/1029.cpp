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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n,m,q; scanf("%d %d %d ",&n,&m,&q);
	bool data[n]; //(0=N,1=S)
	for1(i,0,n) data[i]=false;
	while (m--) {
		int s,len; scanf("%d %d ",&s,&len);
		s--;
		for1(i,s,s+len) {
			data[i] = !data[i];
		}
	}
	//for1(i,0,n) cout<<data[i]<<' '; cout<<endl;
	while (q--) {
		int in; scanf("%d ",&in);
		in--;
		int count = 1; //1 = in
		for (int i = in-1;i>=0&&data[i]==data[in];i--) count++;
		for (int i = in+1;i<n&&data[i]==data[in];i++) count++;
		printf("%d\n",count);
	}
	return 0;
}