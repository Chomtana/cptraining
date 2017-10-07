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

int nn,kk,mm;

//int bt[10000];

ll dp[55][55][55][2][55];

ll recur(int n,int k,int m,bool last,int lastc) { //F=W
    if (m>mm) return 0;
    if (k>kk) return 0;
    if (n>=nn) {
            //for1(i,0,nn) cerr<<bt[i]; cerr<<' '<<k<<' '<<m;
        if (k==kk && m<=mm) {
            //cerr<<" T"<<endl;
            return 1;
        } else {
            //cerr<<" F"<<endl;
            return 0;
        }
    }

    if (dp[n][k][m][last][lastc]!=-1) return dp[n][k][m][last][lastc];

    ll res = 0;
    for1(i,0,2) { //fill black,white
        if(i==last) {
            //bt[n] = i;
            res += recur(n+1,k,max(m,lastc+1),i,lastc+1);
            //bt[n] = 2;
        } else {
            //bt[n] = i;
            res += recur(n+1,k+1,m,i,1);
            //bt[n] = 2;
        }
    }

    return dp[n][k][m][last][lastc]=res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    while (cin>>nn>>kk>>mm) {

        //fill(bt,bt+10000,2);
        //bt[0] = true;
        memset(dp,-1,sizeof(dp));
        cout<<recur(1,1,1,true,1)<<endl;
    }
	return 0;
}
