#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args
#define m (1000000000-1)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n,k;
int data[80005];
ll dp[80005][50];

ll recur(int last,int s) {
    if (s==k) {
        return 1;
    }
    if (dp[last+1][s]!=-1) return dp[last+1][s];
    ll res = 0;
    for1(i,last+1,n) {
        if (last==-1 || data[i]<data[last]) {
            res += recur(i,s+1)%m;
        }
    }
    return dp[last+1][s] = res%m;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n>>k;
    for1(i,0,n) {
        scanf("%d",data+i);
    }

    memset(dp,-1,sizeof(dp));

    cout<<recur(-1,0);
	return 0;
}
