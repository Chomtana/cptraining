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

char data[1005][1005];
int dp[1005][1005];
int nr,nc;

int get(int i,int j) {
    if(i<0||j<0||i>=nr||j>=nc) return 0;
    return dp[i][j];
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>nr>>nc;
    for1(i,0,nr) {
        scanf("%s",data[i]);
    }

    int currmax = 0;

    for1(i,0,nr) {
        for1(j,0,nc) {
            if (data[i][j]=='0') {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(get(i-1,j-1),min(get(i-1,j),get(i,j-1)))+1;

            currmax = max(currmax,dp[i][j]);
            //cerr<<dp[i][j]<<' ';
        }
        //cerr<<endl;
    }



    cout<<currmax;

	return 0;
}
