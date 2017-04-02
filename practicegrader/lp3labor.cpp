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
	int n; cin>>n;
	int data[n]; for1(i,0,n) cin>>data[i];
	int worker[n]; for1(i,0,n) cin>>worker[i];
	int t; cin>>t; while(t--) {
        int k,center; cin>>k>>center;
        k--;
        k/=2;
        center--;
        bool no = false;
        if (center+k >= n || center-k<0) {
            cout<<"no ";
            no = true;
        }

        int sum = 0;
        bool allok = true;
        for1(i,center-k,center+k+1) {
            if (i<0 || i>=n) continue;
            sum += data[i];
            if (worker[i] < 5) {
                allok = false;
            }
        }

        cout<<sum;
        if (allok && !no) cout<<" labor";
        cout<<endl;
	}
	return 0;
}
