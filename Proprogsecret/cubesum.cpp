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

int n;

ll dp[10000][25];

ll recur(int x,int last) {
	if (x<0) return 0;
	if (x==0) return 1;
	
	if (dp[x][last]!=-1) return dp[x][last];
	
	ll sum = 0;
	for1(i,last,x+1) {
		if (x-i*i*i<0) break;
		sum += recur(x-i*i*i,i);
	}
	
	return dp[x][last] = sum;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	
	while (cin>>n) {
		for1(i,0,n+5) for1(j,0,25) dp[i][j]=-1;
		cout<<recur(n,1)<<endl;
	}
	return 0;
}
