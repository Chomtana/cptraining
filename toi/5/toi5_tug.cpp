#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n; scanf("%d",&n);
    ll team1[n]; for1(i,0,n) scanf("%lld",team1+i);
    ll team2[n]; for1(i,0,n) scanf("%lld",team2+i);
    sort(team1,team1+n);
    sort(team2,team2+n);
    ll sum = 0;
    for1(i,0,n) {
        sum += abs(team1[i]-team2[i]);
    }
    cout<<sum;
	return 0;
}
