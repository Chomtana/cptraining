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

int dp[505][505];

int buget(int i,int j) {
    if (i<0||j<0) return 0;
    return dp[i][j];
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    string a,b; cin>>a>>b;
    
    for1(i,0,a.size()) {
        for1(j,0,b.size()) {
            if (a[i]==b[j]) {
                dp[i][j] = buget(i-1,j-1)+1;
            } else {
                dp[i][j] = max(buget(i-1,j),buget(i,j-1));
            }
        }
    }
    
    cout<<dp[a.size()-1][b.size()-1];
	return 0;
}
