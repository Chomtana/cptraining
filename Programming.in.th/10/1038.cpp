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

int n;
double data[25][25];
int curr[25];
bool ban[25];
double res = 0;

double dp[(1<<21)];

int count1(int x) {
    int res = 0;
    while (x) {
        res+=x&1;
        x>>=1;
    }
    return res;
}

double f(int c) {
    if (c==(1<<n)-1) {
        return 1;
    }

    if (dp[c]!=-1) return dp[c];

    double res = 0;
    int r = count1(c);

    //cerr<<bitset<20>(c)<<' '<<r<<endl;

    for1(i,0,n) {
        int test = c&(1<<i);
        if (!test) {
            res = max(res,data[r][i]*f(c|(1<<i)));
        }
    }

    return dp[c] = res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    for1(i,0,n) {
        for1(j,0,n) {
            cin>>data[i][j];
            data[i][j] /= 100;
        }
    }
    fill(dp,dp+(1<<21),-1);
    //f(0);
    printf("%.6f",f(0)*100);
	return 0;
}
