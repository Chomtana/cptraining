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

#define max(a,b,c) max(a,max(b,c))
#define min(a,b,c) min(a,min(b,c))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; scanf("%d",&n);
	int data[n];
	for1(i,0,n) scanf("%d",data+i);
	
	int qs[n];
	qs[0]=data[0];
	for1(i,1,n) { //qs
		qs[i]=qs[i-1]+data[i];
	}
	
	int currmin = 1000000000;
	int resi = 0;
	int resj = 0;
	//if first partition pos = x then sum of first = qs[x]
	//if second partition pos = y then sum of second = qs[y]-qs[(x+1)-1]=qs[y]-qs[x]
	//sum of third = qs[n-1]-qs[y]
	for1(i,0,n) { //first partition pos
		for1(j,i+1,n) { //second partition pos
			int sum1 = qs[i];
			int sum2 = qs[j]-qs[i];
			int sum3 = qs[n-1]-qs[j];
			int ma = max(sum1,sum2,sum3);
			int mi = min(sum1,sum2,sum3);
			int d = abs(ma-mi);
			if (d<currmin) {
				currmin=d;
				resi = i+1;
				resj = j+1;
			}
		}
	}
	
	cout<<resi+1<<' '<<resj+1;
	return 0;
}