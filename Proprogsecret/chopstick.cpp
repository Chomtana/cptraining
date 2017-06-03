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

int data[100];

int dp[100][100];

int recur(int i,int j) {
	if (i==j) return 0;
	
	//cerr<<i<<' '<<j<<endl;
	
	if (dp[i][j]!=-1) return dp[i][j];
	
	int currmin = 1E9;
	for1(k,i+1,j) {
		currmin = min(currmin,recur(i,k)+recur(k,j)+(data[j]-data[i]));
	}
	
	if (currmin==1E9) { //single
		return dp[i][j] = 0;
	}
	return dp[i][j] = currmin;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int k;
	while (cin>>k,k!=0) {
		int n; scanf("%d",&n);
		for1(i,0,n+5) for1(j,0,n+5) dp[i][j] = -1;
		data[0] = 0;
		data[n+1] = k;
		for1(i,1,n+1) {
			scanf("%d",data+i);
		}
		
		printf("The minimum cutting is %d.\n",recur(0,n+1));
	}
	return 0;
}
