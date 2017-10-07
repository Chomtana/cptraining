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

int n;
char data[1005];
int dp[1005][1005];

int recur(int i,int j) {
    if (i>=j) return 0;

    if (dp[i][j]!=-1) return dp[i][j];

    int res = -1;
    if (data[i]==data[j]) return dp[i][j] = 1+recur(i+1,j-1); else {

        for1(k,i,j) {
            res = max(res,recur(i,k)+recur(k+1,j));
        }

    }
    return dp[i][j] = res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;

    //srand(time(0));

    memset(dp,-1,sizeof(dp));

    for1(i,0,n) {
        char temp[3];
        scanf("%s",temp);
        data[i] = temp[0];
    }

    cout<<recur(0,n-1);

	return 0;
}
