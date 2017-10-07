#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int m,n;
int a[1005];
int b[1005];
pii dp[1010][1010];

pii recur(int i,int j) {
    if (i<0 && j<0) return mp(1,0);

    if (dp[i+5][j+5]!=mp(-1,-1)) {
        //cerr<<i<<' '<<j<<endl;
        return dp[i+5][j+5];
    }

    pii ne1 = mp(1E9,1E9);
    pii ne2 = mp(1E9,1E9);

    if (i>=0) ne1 = recur(i-1,j);
    if (j>=0) ne2 = recur(i,j-1);

    ne1.second += a[i];
    ne2.second += b[j];
    if (ne1.second>m) {
        ne1.first++;
        ne1.second = a[i];
    }
    if (ne2.second>m) {
        ne2.first++;
        ne2.second = b[j];
    }

    return dp[i+5][j+5] = min(ne1,ne2);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>m>>n;
    //memset(dp,-1,sizeof(dp));

    for1(i,0,n+10) for1(j,0,n+10) dp[i][j] = mp(-1,-1);

    for1(i,0,n) scanf("%d",a+i);
    for1(i,0,n) scanf("%d",b+i);

    pii res = recur(n-1,n-1);
    cout<<res.first<<endl<<res.second;
	return 0;
}
