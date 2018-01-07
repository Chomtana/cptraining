/*
Optimize with segment / fenwick tree -> must define dp without state space reduction
dp[1] = IS len 1
dp[2] = IS len 2
...

Condition:
left element (having done) must have value < right element (curr element)
normally, curr element = right element , do from left to right
-> left value : value that has already calculated
-> right value : current value

need left,right order -> tong simulate te la tua (simulate -> for each element update all dp[...])

if input = 1 2 3 4
iteration 1 (calculate art value at (1...1))
dp[1] = {1} = append 1
iteration 2 (...................... (1...2))
dp[1] = {1},{2} = oldit + append 2
dp[2] = {1,2} = oldit + dp[1],end<2 -> append 2
iteration 3 (...................... (1...3))
dp[1] = {1},{2},{3} = oldit + append 3
dp[2] = {1,2},{1,3},{2,3} = oldit + dp[1],end<3 -> append 3
dp[3] = {1,2,3} = dp[2],end<3 -> append 3
iteration 4 (...................... (1...4))
dp[1] = {1},{2},{3},{4} = oldit + append 4
dp[2] = {1,2},{1,3},{2,3},{1,4},{2,4},{3,4} = oldit + dp[1],end<4 -> append 4 (dp[1][4])
dp[3] = {1,2,3},{1,2,4},{1,3,4} = oldit + dp[2],end<4 -> append 4
dp[4] = {1,2,3,4} = dp[3],end<4 -> append 4

observe : dp[3],end<4 need more property : end , end < -> range -> fenwick tree
            end is fenwick tree property

dp[k][end] = LIS size k with end (final element) = end

if decreasing -> swith operator < -> > because of val left > val right -> we select left -> operator is >

rank law : value < value -> rank < rank
then
-> left rank : rank that has already calculated (rank of dp[k-1])
-> right rank : current rank
left rank < right rank -> left rank = [0,right rank-1]
*/

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

ll fw[45][80005];
const ll m = 1000000000-1;
int n,k;

ll query(int k,int pos) {
    ll res = 0;
    for(int i = pos;i>=1;i-=(i&-i)) {
        res += fw[k][i]%m;
    }
    return res%m;
}

ll query(int k,int s,int e) { //dp[k][s...e]
    return ((query(k,e)-query(k,s-1))%m+m)%m;
}

void update(int k,int pos,int val) { //dp[k][pos] += val;
    for(int i = pos;i<=n;i+=(i&-i)) {
        fw[k][i] += val;
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>k;
    for1(i,0,n) {
        int x; scanf("%d",&x);
        if (i>0) {
            for1(j,1,k+1) {
                if (j==1) {
                    update(j,x,1);
                } else {
                    if (x<n) {
                        update(j,x,query(j-1,x+1,n));
                        //cerr<<j<<' '<<x<<' '<<query(j-1,x+1,n)<<endl;
                    }
                }
            }
        } else {
            update(1,x,1);
        }
    }

    printf("%lld",query(k,1,n));

	return 0;
}
