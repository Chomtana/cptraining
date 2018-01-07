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

int nr,nc;
int data[15][105];
int path[15][105];
int dp[15][105];

int recur(int cr,int cc) {
    if (cr==-1) cr=nr-1;
    if (cr>=nr) cr=0;
    if (cc>=nc) {
        return 0;
    }

    if (dp[cr][cc]!=-1) return dp[cr][cc];

    int res1 = recur(cr-1,cc+1)+data[cr][cc];
    int res2 = recur(cr,cc+1)+data[cr][cc];
    int res3 = recur(cr+1,cc+1)+data[cr][cc];
    int res = min(res1,min(res2,res3));

    int ner = 1E9;
    if (res==res1) {
        int nerr = cr-1;
        if (nerr==-1) nerr=nr-1;
        if (nerr>=nr) nerr=0;
        if (nerr<ner) {
            ner = nerr;
            path[cr][cc] = 0;
        }
    }
    if (res==res2) {
        int nerr = cr;
        if (nerr==-1) nerr=nr-1;
        if (nerr>=nr) nerr=0;
        if (nerr<ner) {
            ner = nerr;
            path[cr][cc] = 1;
        }
    }
    if (res==res3) {
        int nerr = cr+1;
        if (nerr==-1) nerr=nr-1;
        if (nerr>=nr) nerr=0;
        if (nerr<ner) {
            ner = nerr;
            path[cr][cc] = 2;
        }
    }


    return dp[cr][cc] = res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    while(cin>>nr>>nc) {
        for1(i,0,nr) {
            for1(j,0,nc) {
                scanf("%d",&data[i][j]);
            }
        }

        memset(dp,-1,sizeof(dp));
        int res = 1E9;
        int sr = 0;
        for1(i,0,nr) {
            int subres = recur(i,0);
            if (subres<res) {
                res = subres;
                sr = i;
            }
        }
        int cc = 0;
        int cr = sr;
        while(cc<nc) {
            printf("%d",cr+1);
            if (cc!=nc-1) {
                printf(" ");
            }

            if (path[cr][cc]==0) {
                cr--;
            } else if (path[cr][cc]==2) {
                cr++;
            }

            if (cr==-1) cr=nr-1;
            if (cr>=nr) cr=0;

            cc++;
        }
        printf("\n");
        printf("%d\n",res);
    }


	return 0;
}
