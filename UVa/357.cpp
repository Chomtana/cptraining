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
int C[] = {1,5,10,25,50};
ll dp[10][40000];

ll recur(int c,int curr) {
    //check base answer
    //exceed limit
    if (curr>n) {
        return 0;
    }

    //ok
    if (curr==n) {
        return 1;
    }

    //out of bound (and not ans)
    if (c<0) {
        return 0;
    }

    if (dp[c][curr]!=-1) return dp[c][curr];

    return dp[c][curr] = recur(c-1,curr)+recur(c,curr+C[c])/*+recur(c-1,curr+C[c]) /*mai aow pork nub sum (dai tum ma leaw nai path c,curr+C[c] -> c-1,curr dai c-1,curr+C[c]*/;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    while (cin>>n) {
        for1(i,0,5) {
            for1(j,0,n+100) {
                dp[i][j] = -1;
            }
        }
        ll res = recur(4,0);
        if (res>1) {
            printf("There are %lld ways to produce %d cents change.\n",res,n);
        } else {
            printf("There is only %lld way to produce %d cents change.\n",res,n);
        }
    }
	return 0;
}
