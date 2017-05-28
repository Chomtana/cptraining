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

int m,n;
int P[105];
int F[105];
int dp[105][20000];

int f(int c,int sw) {
    ///Old idea:
    //this problem hard to write super incorrect base case (but can write)
    //-> write it in out of bound (caching fail)
    //-> don't need to care about super or insuper ... super , not super both get antians as result in out of bound step
    /// !!! But caching fail (dp[c][sw] will return junk value because sw out of bound) !!!
    /// require if (current state is super incorrect ... mai sa mud tum hai mun correct dai nai karn run kung tor tor pai) -> return antians

    //if super incorrect -> return antians
    if (sw>2000) {
        if (sw>m+200) return -1E9;
    } else {
        if (m<=1800) {
            if (sw>m) return -1E9;
        }
        // m = (1801,2000] isn't super incorrect
        //because if m = 1801 , sw = 1901 in this time you cannot buy ...
        //but if choose to do next by buy something price 100 then state m = 1801 , sw = 2001 ...
        //it will ok -> tum tor pai yung me okard ok -> mai chai super incorrect
    }

    if (c<0) {
        //if not ok return antians
        if (sw>2000) {
            if (sw>m+200) return -1E9;
        } else {
            if (sw>m) return -1E9;
        }
        return 0; //if ok return f({})
    }

    if (dp[c][sw]!=-1) return dp[c][sw];

    return dp[c][sw] = max(f(c-1,sw),f(c-1,sw+P[c])+F[c]);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    while (cin>>m>>n) {

        for1(i,0,n+5) for1(j,0,m+2005) dp[i][j]=-1;

        for1(i,0,n) {
            scanf("%d%d",P+i,F+i);
        }

        printf("%d\n",f(n-1,0));

    }
	return 0;
}
