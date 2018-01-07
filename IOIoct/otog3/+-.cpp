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

int n,k;
//vector<bool> data;
vector<bool> res;
short dp[3005][10050];


bool recur(int c,int sum) { //+T -F
    if (c>n) {
        if (sum==k) return true; else return false;
    } else {
        if (abs(sum)>=5000) false;
        if (dp[c][sum+5005]!=-1) return dp[c][sum+5005];
        if(recur(c+1,sum+c)) {
            res[c-2] = true;
            return dp[c][sum+5005] = true;
        }


        if (recur(c+1,sum-c)) {
            res[c-2] = false;
            return dp[c][sum+5005] = true;
        }

    }

    return dp[c][sum+5005] = false;

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t = 10; while(t--) {
        scanf("%d%d",&n,&k);
        res.clear();
        res.resize(n+5);

        memset(dp,-1,sizeof(dp));

        if (recur(2,1)) {
            printf("1");
            for1(i,0,n-1) {
                if (res[i]) printf("+"); else printf("-");
                printf("%d",i+2);
            }
            printf("\n");
        } else {
            printf("Impossible\n");
        }

	}
	return 0;
}
