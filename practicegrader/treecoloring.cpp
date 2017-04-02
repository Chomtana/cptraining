#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define m 93563

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    //k*(k-1)^(n-1);
    int t; cin>>t;
    while (t--) {
        int n,k; cin>>n>>k;
        int temp;
        for1(i,0,n-1) {
            cin>>temp>>temp;
        }

        int res = 1;
        for1(i,0,n-1) {
            res *= k-1;
            res %= m;
        }

        res *= k;
        cout<<res%m<<endl;
    }
	return 0;
}
