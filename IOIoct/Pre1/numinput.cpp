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

int n,m;
vector<int> data;
bool ban[1005];
int la[1005]; //value of last = data[index of last]
int ne[1005];
int f[1005];
ll dp[1005][1005];

ll recur(int curr,int last) {
    if (curr>=data.size()) {
        if (last==n) {
            /*for1(i,1,data.size()) {
                cerr<<f[i]<<' ';
            }
            cerr<<endl;*/
            return 1;
        } else return 0;
    }

    if (dp[curr][last]!=-1) return dp[curr][last];

    ll res = 0;

    if (ban[curr]) {
        if (abs(last-data[curr])>1) return dp[curr][last] = 0;
        f[curr] = data[curr];
        res += recur(curr+1,data[curr]);
        f[curr] = 0;
    } else {
        f[curr] = last;
        res += recur(curr+1,last);
        f[curr] = 0;
        if (curr>1 && last+1<=ne[curr]) {
            f[curr] = last+1;
            res += recur(curr+1,last+1);
            f[curr] = 0;
        }
    }

    return dp[curr][last] = res%9901;

}

int main() {
	//ios::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	cout<<fixed;
    cin>>n>>m;
    data.push_back(-1);
    for1(i,0,n) {
        int x; scanf("%d",&x);
        while (x--) data.push_back(i+1);
    }

    for1(i,0,m) {
        int x; scanf("%d",&x);
        ban[x] = true;
    }

    int cla = 1; //index of lAst
    int cne = 1;
    while(cne<data.size() && !ban[cne]) cne++;
    for1(i,1,data.size()) {
        if (i>cne) {
            cla = cne;
            cne++;
            while(cne<data.size() && !ban[cne]) cne++;
        }
        la[i] = data[cla];
        if (cne<data.size()) ne[i] = data[cne]; else ne[i] = n;
    }

    /*for1(i,1,data.size()) cerr<<data[i]<<' '; cerr<<endl;
    for1(i,1,data.size()) cerr<<la[i]<<' '; cerr<<endl;
    for1(i,1,data.size()) cerr<<ne[i]<<' '; cerr<<endl;*/

    cout<<recur(1,1)%9901;
	return 0;
}
