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

int data[1000];
int n,q;
int d,m;
ll dp[205][15][25];

ll recur(int curr,int sel,int sum) {
    //base case
    if (sel==m) {
        if (sum==0) return 1; else return 0;
    }
    if (curr<0) return 0;

    //caching : return cached
    if(dp[curr][sel][sum]!=-1) return dp[curr][sel][sum];

    //process (in this case process in return time)
    //return and cache new
    return dp[curr][sel][sum] = recur(curr-1,sel,sum)+recur(curr-1,sel+1,((sum+data[curr])%d+d)%d);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int setid = 0;
    while(cin>>n>>q,n!=0) {
        printf("SET %d:\n",++setid);
        fill(data,data+n,0);
        for1(i,0,n) scanf("%d",data+i);
        int queryid = 0;
        while (q--) {
            scanf("%d%d",&d,&m);
            for1(i,0,n) {
                for1(j,0,15) for1(k,0,25) dp[i][j][k] = -1;
            }
            printf("QUERY %d: ",++queryid);
            printf("%lld\n",recur(n-1,0,0));
        }
    }
	return 0;
}
