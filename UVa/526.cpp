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

string s,t;

int dp[s.size()+5][t.size()+5];

void edit() {
	
	
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	while (getline(cin,s)&&getline(cin,t)) {
		s = " "+s;
		t = " "+t;
		for1(i,0,s.size()) {
			for1(j,0,t.size()) {
				dp[i][j] = 0;
			}
		}
		for1(i,1,s.size()) {
			dp[i][0] = 1;
		}
		for1(i,1,t.size()) {
			dp[0][i] = 1;
		}
		edit();
	}
	return 0;
}
