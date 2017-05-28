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

string a,b;

int dp[505][505];

int lcs(int ai,int bi) {
    if (ai==-1 || bi==-1) return 0;

    if (dp[ai][bi]!=-1) return dp[ai][bi];

    if (a[ai]==b[bi]) {
        return dp[ai][bi] = lcs(ai-1,bi-1)+1;
    } else {
        return dp[ai][bi] = max(lcs(ai-1,bi),lcs(ai,bi-1));
    }

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>a>>b;
    for1(i,0,a.size()) for1(j,0,b.size()) dp[i][j] = -1;
    cout<<lcs(a.size()-1,b.size()-1);
	return 0;
}
