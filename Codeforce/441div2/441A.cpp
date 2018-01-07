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

//01 a
//02 b
//12 c


int n,a,b,c;

int dp[105][105];

int recur(int curr,int meal) {
    if (meal==n) {
        return 0;
    }

    if (dp[curr][meal]!=-1) return dp[curr][meal];

    if (curr==0) {
        return dp[curr][meal] = min(recur(1,meal+1)+a,recur(2,meal+1)+b);
    } else if (curr==1) {
        return dp[curr][meal] = min(recur(0,meal+1)+a,recur(2,meal+1)+c);
    } else {
        return dp[curr][meal] = min(recur(0,meal+1)+b,recur(1,meal+1)+c);
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>a>>b>>c;
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,1);
	return 0;
}
