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

int n,kk;
int data[1005];
int qs[1005];
int dp[1005][305];

int qss(int i,int j) {
    if(i==0) return qs[j]; else return qs[j]-qs[i-1];
}

int recur(int p,int k) {
    if (p>=n) return 1E9;
    if (k==0) {
        //cerr<<p<<' '<<qss(p,n-1)<<endl;
        return qss(p,n-1);
    }

    if(dp[p][k]!=-1) return dp[p][k];

    int res = 1E9;
    for1(i,p,n) {
        res = min(res,max(qss(p,i),recur(i+1,k-1)));
    }
    return dp[p][k] = res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
     cin>>n>>kk;
     memset(dp,-1,sizeof(dp));
    for1(i,0,n) {
        scanf("%d",data+i);
        if(i==0) {
            qs[i] = data[0];
        } else {
            qs[i] = qs[i-1]+data[i];
        }
    }

    cout<<recur(0,kk-1);
	return 0;
}
