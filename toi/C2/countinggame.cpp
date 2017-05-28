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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nn; cin>>nn;

    subfunc(vector<bool>,calban,(int n)) {
        vector<bool> ban(11,false);
        char s[20];
        sprintf(s,"%d",n);
        int len = strlen(s);
        for1(i,0,len) {
            ban[s[i]-'0'] = true;
        }
        return ban;
    };

    vector<int> dp(nn+1,1E9); //caching init as antians (want min -> max...1E9)

    subfunc(int,donext,(int n)) {
        //bool hasnext = false;

        //base case
        if (n==1) return 0;
        if (n<1) return int(1E9);

        //dp caching
        //if caching != anti ans -> cached -> return it and don't process because it will waste time reprocess thing that we have already processed.
        if (dp[n]!=1E9) {
            return dp[n];
        }

        //no cache -> process

        vector<bool> ban = calban(n);

        int nextbest = 1E9;

        for1(i,2,6) { //[2,5]
            if (!ban[i]) {
                if (n%i!=0) {
                    //hasnext = true;
                    nextbest = min(nextbest,donext(n-i));
                }
            }
        }

        //save cache and return
        return dp[n] = nextbest+1;
    };

    int res = donext(nn);
    if (res>=1E9) {
        cout<<-1;
    } else {
        cout<<res;
    }

	return 0;
}
