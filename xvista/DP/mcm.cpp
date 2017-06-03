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

int data[105];

int dp[105][105];

int recur(int i,int j) { //dp[i][j] = answer(i...j)
    if (i==j) return 0;
    
    if (dp[i][j]!=0) return dp[i][j];
    
    int currmin = 1E9;
    for1(k,i,j) {
        currmin = min(currmin,recur(i,k)+recur(k+1,j)+data[i]*data[k+1]*data[j+1]);
    }
    return dp[i][j]=currmin;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    for1(i,0,n+1) scanf("%d",data+i);
    cout<<recur(0,n-1);
	return 0;
}
