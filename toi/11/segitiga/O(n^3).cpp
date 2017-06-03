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
typedef vector<int> vi;

string s;

vector<vector<pii>> from(3);

char dp[260][260][3];



bool recur(int i,int j,int want) {
	if (i==j) return s[i]-'0'==want;
	
	if (dp[i][j][want]!=2) return dp[i][j][want];
	
	for1(k,i,j) {
		for1(x,0,from[want].size()) {
			//cerr<<k<<' '<<want<<' '<<from[want][x].first<<' '<<from[want][x].second<<endl;
			/*if (i==2 && j==s.size()-1 && k==2 && want==1) {
				cerr<<recur(i,k,from[want][x].first)<<' '<<recur(k+1,j,from[want][x].second)<<' '<<from[want][x].second<<endl;
			}*/
			if (recur(i,k,from[want][x].first) && recur(k+1,j,from[want][x].second)) return dp[i][j][want] = true;
		}
	}
	
	return dp[i][j][want] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	
	from[0].resize(1);
	from[0][0] = mp(0,2);
	from[1].resize(5);
	from[1][0] = mp(0,1);
	from[1][1] = mp(1,1);
	from[1][2] = mp(1,2);
	from[1][3] = mp(2,0);
	from[1][4] = mp(2,2);
	from[2].resize(3);
	from[2][0] = mp(0,0);
	from[2][1] = mp(1,0);
	from[2][2] = mp(2,1);
	
	int t=20; while(t--) {
		int n; cin>>n; cin>>s;
		memset(dp,2,sizeof(dp));
		if (recur(0,s.size()-1,0)) {
			cout<<"yes"<<endl;
		} else {
			cout<<"no"<<endl;
		}
	}
	return 0;
}
