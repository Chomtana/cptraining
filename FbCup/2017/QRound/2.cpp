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
	int t; cin>>t;
	for1(_t,1,t+1) {
        int n; cin>>n;
        vector<int> w(n);
        for1(i,0,n) cin>>w[i];
        sort(all(w),greater<int>());
        int sum = 0;
        int res = -1;
        for1(i,0,n) {
            int need = ceil(50.0/double(w[i]));
            sum += need;
            //cout<<need<<endl;
            if (sum>n) {
                res = i;
                break;
            }
        }
        if (res==-1) {
            res = n;
        }
        cout<<"Case #"<<_t<<": ";
        cout<<res<<endl;

	}
	return 0;
}
