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

int dp[1005][35];
int V[1005];
int W[1005];
//int B[105];

int n,nb;
int cw;

int R(int c,int sw) {
    //if cannot make to answer anymore return anti ans (shouldn't check in out of bound because it will enlarge dp array)
    if (sw>cw) {
        return -1E9;
    }

    //knapsack no == case -> check for ok in out of bound step
    /*if (sw==cw) {
        return 0;
    }*/

    //if out of bound and answer not super not ok (ans ok is possible)
    if (c<0) {
        //if ans ok -> return ans of empty case
        if (sw<=cw) {
            return 0;
        } else { //if not ok
            return -1E9;
        }
    }

    if (dp[c][sw]!=-1) return dp[c][sw];

    return dp[c][sw] = max(R(c-1,sw),R(c-1,sw+W[c])+V[c]);
} //use top down definition to write bottom up code for incredible problem with n > 1,000,000

int buget(int c,int sw) {
    //if cannot make to answer anymore return anti ans (shouldn't check in out of bound because it will enlarge dp array)
    if (sw>cw) {
        return -1E9;
    }

    //knapsack no == case -> check for ok in out of bound step
    /*if (sw==cw) {
        return 0;
    }*/

    //if out of bound and answer not super not ok (ans ok is possible)
    if (c<0) {
        //if ans ok -> return ans of empty case
        if (sw<=cw) {
            return 0;
        } else { //if not ok
            return -1E9;
        }
    }

    return dp[c][sw]; //bottom up mai tong check wa cached? pork lao nae jai wa mun cache leaw
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {

        int anscache[35];
        fill(anscache,anscache+35,-1);

        scanf("%d",&n);
        for1(i,0,n) {
            scanf("%d%d",V+i,W+i);
        }

        int nb; scanf("%d",&nb);

        int res = 0;



        for1(i,0,nb) {
            scanf("%d",&cw);
            //for1(i,0,1005) for1(j,0,35) dp[i][j] = -1; //bottom up doesn't require reset
            //res += R(n-1,0);

            if (anscache[cw]!=-1) {
                res += anscache[cw];
                continue;
            }

            //bottom up dp
            for1(c,0,n) {
                for1(sw,0,cw+1) {
                    dp[c][sw] = max(buget(c-1,sw),buget(c-1,sw+W[c])+V[c]);
                }
            }

            anscache[cw] = dp[n-1][0];
            res += dp[n-1][0];
        }

        printf("%d\n",res);

    }
	return 0;
}
