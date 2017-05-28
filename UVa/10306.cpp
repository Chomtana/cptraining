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

int n,target;
pii coins[45];

int dp[45][400][400];

//count len dp -> if choose working state -> add 1 else don't add (base case see that if condition -> we must choose or not , general case see that for each next then we must choose or not (don't need to be same for all next ... you need to increase value for each next)))
int recur(int curr,int sx,int sy) {
    //cerr<<curr<<' '<<sx<<' '<<sy<<endl;
    //value super not ok -> return antians ... it is not count way problem (if it has many coin but choose in any way don't get ans -> must return not possible)
    if (sx*sx+sy*sy>target*target) {
        return 1E9;
    }

    //value ok -> return 0 (single state only describe first to before current -> if it is ok : first to before current ok -> we don't count current)
    if (sx*sx+sy*sy==target*target) {
        return 0;
    }

    //out of bound and value not ok (value not ok -> return antians , value not ok shadow state from checking above)
    if (curr<0) {
        return 1E9;
    }

    if (dp[curr][sx][sy]!=-1) return dp[curr][sx][sy];

    //remember infinity 0,1 has 3 next
    //but if you perform all 3 next in count way problem it will duplicate count so in count way only use two (mai aow,change),(aow,mai change)
    //but in other problem if you don't perform all it will miss some case
    //so in other problem you need to put all 3 case ... (mai aow,change) (aow,mai change) (aow,change)
    return dp[curr][sx][sy] = min(recur(curr-1,sx,sy),min(recur(curr,sx+coins[curr].first,sy+coins[curr].second)+1,recur(curr-1,sx+coins[curr].first,sy+coins[curr].second)+1));
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
        for1(i,0,45) for1(j,0,400) for1(k,0,400) dp[i][j][k] = -1;
        scanf("%d %d",&n,&target);
        for1(i,0,n) {
            scanf("%d %d",&coins[i].first,&coins[i].second);
        }

        int res = recur(n-1,0,0);

        if (res>=1E9) {
            printf("not possible\n");
        } else {
            printf("%d\n",(res));
        }

        //for1(i,0,45) for1(j,0,400) for1(k,0,400) if (dp[i][j][k]!=-1) cerr<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
    }
	return 0;
}
