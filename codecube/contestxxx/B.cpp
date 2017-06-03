/**
Critical case:
mun mai jum pen tong end te final level ***

2 2
0000
0000
must answer 0
but it answer 1
*/

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

char data[20][110];

int n,m;

int realres = 1E9;

int dp[20][2];

int finalrow = 0;

int recurdp(int f,bool dir/*,int res*/) {
	
	//cerr<<f<<' '<<dir<<' '<<res<<endl;
	
	if (f<0) {
		//realres = min(realres,res);
		return 0;
	}
	
	if (dp[f][dir]!=-1) return dp[f][dir];
	
	int col;
	
	int resadd = 0;
	
	if (dir) { //from left
		col = 0;
		for1(j,col+1,m+2) {
			if (data[f][j]=='1') {
				resadd += j-col;
				col = j;
			}
		}
		
	} else {
		col = m+1;
		for2(j,col-1,0) {
			if (data[f][j]=='1') {
				resadd += col-j;
				col = j;
			}
		}
	}
	
	if (f==finalrow) {
		return dp[f][dir] = resadd;
	}
	
	return dp[f][dir] = min(recurdp(f-1,true/*,res+col+1*/)+resadd+col+1,
	recurdp(f-1,false/*,res+(m+1-col)+1*/)+resadd+(m+1-col)+1);
}

int recur(int f,bool dir,int res) {
	
	//cerr<<f<<' '<<dir<<' '<<res<<endl;
	
	if (f<0) {
		//realres = min(realres,res);
		return 0;
	}
	
	//if (dp[f][dir]!=-1) return dp[f][dir];
	
	int col;
	
	int resadd = 0;
	
	if (dir) { //from left
		col = 0;
		for1(j,col+1,m+2) {
			if (data[f][j]=='1') {
				res += j-col;
				col = j;
			}
		}
		
	} else {
		col = m+1;
		for2(j,col-1,0) {
			if (data[f][j]=='1') {
				res += col-j;
				col = j;
			}
		}
	}
	
	if (f==0) { //fix crit case
		realres = min(realres,res);
		//return dp[f][dir] = resadd;
	}
	
	//return dp[f][dir] = min(recur(f-1,true/*,res+col+1*/)+resadd+col+1,
	//recur(f-1,false/*,res+(m+1-col)+1*/)+resadd+(m+1-col)+1);
	recur(f-1,true,res+col+1);
	recur(f-1,false,res+(m+1-col)+1);
}

bool isempty(int f) {
	for1(i,0,m+2) {
		if (data[f][i]=='1') return false;
	}
	return true;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	
	for1(i,0,n) {
		scanf("%s",data[i]);
	}
	
	//fix crit case
	while (finalrow<n && isempty(finalrow)) finalrow++;
	
	if (finalrow==n) {
		cout<<0; return 0;
	}
	
	realres = recurdp(n-1,true);
	//recur(n-1,true,0);
	
	/*int res = 0;
	
	int col = 0;
	bool dir = true; //T;FL F;FR
	for2(i,n-1,0) {
		if (dir) { //from left
			for1(j,col+1,m+2) {
				if (data[i][j]=='1') {
					res += j-col;
					col = j;
				}
			}
			
		} else {
			for2(j,col-1,0) {
				if (data[i][j]=='1') {
					res += col-j;
					col = j;
				}
			}
		}
		
		if (i-1>=0) {
			int nf = findmin(i-1);
			int nfmax = findmax(i-1);
			int toleft,toright;
			if (nf==-1) {
				toright = (m+1-col);
				toleft = col;
			} else {
				toright = (m+1-col)+(m+1-nf);
				toleft = col+nfmax;

			}
			cerr<<toleft<<' '<<
			if (toleft<toright) {
				col = 0;
				dir = true;
			} else {
				col = m+1;
				dir = false;
			}
		}
	}
	
	cout<<res;*/
	
	cout<<realres;
	
	return 0;
}
