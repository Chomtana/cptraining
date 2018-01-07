#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

#define m 1000000007

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n;
int k[5];

ll dp[1005][4][1005][8];

ll recur(int day,int curr,int stay,int status) {
    status |= (1<<(curr-1));

    if (day>=n) {
        if (status == 0b111) return 1; else return 0;
    }



    if (dp[day][curr][stay][status]!=-1) return dp[day][curr][stay][status];

    ll res = 0;
    if (stay+1<=k[curr]) {
        res += recur(day+1,curr,stay+1,status);
    }

    if (curr==1) {
        res += recur(day+1,2,1,status);
        res += recur(day+1,3,1,status);
    } else if (curr==2) {
        res += recur(day+1,3,1,status);
    } else {
        res += recur(day+1,1,1,status);
    }

    return dp[day][curr][stay][status] = res%m;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>k[1]>>k[2]>>k[3];
    memset(dp,-1,sizeof(dp));
    cout<<recur(1,1,1,0);
	return 0;
}
