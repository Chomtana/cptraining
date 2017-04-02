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
	int r,s,t; cin>>r>>s>>t;
	int _; cin>>_;
	while (_--) {
        int n; cin>>n;
        if (n<r) {
            cout<<"no"<<endl; continue;
        }
        n-=r;
        // n= 0 -> yes
        // n= 1...S --> yes
        // n = S+1 ... S+T-1 -> no
        //won loop -> %
        //% S+T

        n %= s+t;

        if (n<=s) cout<<"yes"; else cout<<"no";
        cout<<endl;
	}
	return 0;
}
