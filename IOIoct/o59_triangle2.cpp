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

const ll m = 1e9+7;

ll dp[1005];
ll ex[1005];
int n,k;

int main() {

	//ios::sync_with_stdio(false);
	cout<<fixed;
	//memset(dp,0,sizeof(dp)); //global auto init as 0
    cin>>n>>k;
    for1(i,0,n) {
        //for1(j,0,n) { //if j not use in loop -> multiply it with count
                        //if use in loop , use in if -> recognize to see that how much it count -> multiplyit with count
                        //if use in count then no way to optimize
            dp[1] += n*min(k,n-i-1);
            dp[1] %= m;
        //}
    }

    dp[1] *= 2; //up = down for dp[1] -> up+down = 2up

    for1(currdp,2,n+1) {
        ll currres = 0;

    }



    //intersect at least 1 -> select one pair of points that intersect -> select next points without this condition (only first pair met this condition , others pair can select everywhere)
    for1(i,0,n) { //select pair of points that intersect -> 2 point selected
        //select first down -> n
        //select second down -> n
        //select first up2 -> min(k,n-i-1)
        //select second up2 -> min(k,n-i-1)
        ex[2] += n*n*min(k,n-i-1)*min(k,n-i-1);
        ex[2] %= m;
    }

    for1(currdp,3,n+1) {
        //intersect at least 1 point
        //for intersect
        //select more 4 like ex[2]
        //select triangle like dp[1]
        //select triangle like dp[1]
        //...
        //compare to top -> select triangle like dp[1] ... is select triangle like dp[number of triangle to select]
        for1(i,0,n) {
            ex[currdp] += ex[2]*dp[currdp-2];
            ex[currdp] %= m;
        }
    }


    ll res = 0;

    for1(i,1,n+1) {
        res += dp[i]-ex[i];
    }

    cout<<res%m<<endl;
    for1(i,1,n+1) cerr<<dp[i]<<' '; cerr<<endl;
    for1(i,1,n+1) cerr<<ex[i]<<' '; cerr<<endl;

    ll dbg = 0;
    for1(i1,0,n) {
        for1(i2,i1+1,n) {
            for1(i3,0,n) { //ok
                for1(i4,0,n) {
                    for1(i5,i4+1,n) {
                        for1(i6,0,n) { //ok
                            if (i2==i3 || i2==i4 || i2==i5 || i2==i6 || i3==i4 || i3==i5 || i3==i6 || i4==i5 || i4==i6 || i5==i6) {
                                if ((i2-i1<=k && i5-i4<=k)) dbg++;
                            }
                        }
                    }
                }
            }
        }
    }
    cerr<<dbg<<endl;
	return 0;
}
