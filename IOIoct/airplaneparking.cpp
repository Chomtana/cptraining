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

pii data[305];
int n;
int dp[305];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; while(t--) {
        scanf("%d",&n);
        for1(i,0,n) {
            scanf("%d%d",&data[i].first,&data[i].second);
        }
        sort(data,data+n,[](pii a,pii b) {
            if (a.first<b.first) return true;
            if (a.first>b.first) return false;
            return a.second<b.second;
        });

        dp[0] = 1;
        for1(i,1,n) {
            dp[i] = 1;
            for1(j,0,i) {
                if (data[j].second>data[i].second || data[i].first>data[j].second || data[i].first==data[j].first) {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }

        printf("%d\n",*max_element(dp,dp+n));
	}

	return 0;
}
