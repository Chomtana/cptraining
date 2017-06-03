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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n;
	while (cin>>n) {
		int data[n];
		for1(i,0,n) scanf("%d",data+i);
		int m; scanf("%d",&m);
		
		sort(data,data+n);
		
		int ans1,ans2;
		int currmin = 1E9;
		
		for1(i,0,n) { //data[i] <= m-data[i];
			int target = m-data[i];
			if (target<data[i]) break;
			if (binary_search(data,data+n,target)) {
				int dif = target-data[i];
				if (dif<currmin) {
					currmin = dif;
					ans1 = data[i];
					ans2 = target;
				}
			}
		}
		
		printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);
	}
	return 0;
}
