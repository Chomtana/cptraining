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

int data[200];
int qs[200];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; while (t--) {
		int n; scanf("%d",&n);
		int allsum=0;
		for1(i,0,n) {
			scanf("%d",data+i);
			allsum += data[i];
		}
		
		
		
		qs[0] = data[0];
		for1(i,1,n) {
			qs[i] = qs[i-1]+data[i];
		}
		
		
		int mindif = 1E9;
		for1(i,0,n-1) {
			int g1 = qs[i];
			int g2 = allsum-qs[i];
			int dif = abs(g1-g2);
			mindif = min(mindif,dif);
		}
		
		printf("%d\n",mindif);
	}
	return 0;
}
