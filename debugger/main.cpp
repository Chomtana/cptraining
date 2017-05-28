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

int W[105];
int P[105];
int m,n;

int dp[105][15005];

int F(int c,int sw) {

    //cerr<<c<<' '<<sw<<endl;

    //out of bound base case
    if (c>=n) {
        if (sw>m && sw<=2000) return -1E9;
        return 0;
    }

    //if cached return cached
    if (dp[c][sw]!=-1) return dp[c][sw];

    //cannot select current (select current -> not ok) (must use value from ... to current include current)
    //-> has only 1 next case : pass to next element without select current element
    if (sw+P[c]>2000) {
        if (sw+P[c]>m+200) return dp[c][sw] = F(c+1,sw);
    } else {
        if (sw+P[c]>m && sw+P[c]<=2000) return dp[c][sw] = max(F(c+1,sw),F(c+1,sw+P[c])+W[c]);
        if (sw+P[c]>m) return dp[c][sw] = F(c+1,sw);
    }

    //solution base case
    /*if(sw > m && m < 1800)
        return -1000;
    if(sw > m + 200)
        return -1000;
    if(c == n) {
        if(sw > m && sw <= 2000)
            return -1000;
        return 0;
    }
    if(dp[c][sw] != -1)
        return dp[c][sw];*/

    //do next (compact version ... in same line as cache new value)
    //cache new value
    return dp[c][sw] = max(F(c+1,sw),F(c+1,sw+P[c])+W[c]);
}

//solution
int recurse(int i, int w) {
    if(w > m && m < 1800)
        return -1000;
    if(w > m + 200)
        return -1000;
    if(i == n) {
        if(w > m && w <= 2000)
            return -1000;
        return 0;
    }
    if(dp[i][w] != -1)
        return dp[i][w];

    return dp[i][w] = max(recurse(i + 1, w), \
        W[i] + recurse(i + 1, w + P[i]));
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;

    while (cin>>m>>n) {

        for1(i,0,n+5) {
            for1(j,0,m+205) {
                dp[i][j] = -1;
            }
        }

        for1(i,0,n) {
            int p,w; scanf("%d %d",&p,&w);
            P[i] = p;
            W[i] = w;
        }

        printf("%d\n",F(0,0));
        //printf("%d\n",recurse(0,0));

        /*for1(i,0,n) {
            cerr<<P[i]<<' '<<W[i]<<endl;
        }*/

        /*for1(i,0,n) {
            for1(j,0,m) {
                if (dp[i][j]!=-1) cerr<<i<<' '<<j<<' '<<dp[i][j]<<endl;
            }
        }*/


    }
	return 0;
}
