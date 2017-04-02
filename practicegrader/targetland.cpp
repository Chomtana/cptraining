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
	int data[n];
	for1(i,0,n) cin>>data[i];
	int t; cin>>t;
	while (t--) {
        int k,center; cin>>k>>center;
        k--;
        k/=2;
        if (center+k > n) {
            cout<<"no"<<endl;
            continue;
        }
        if (center-k<=0){
            cout<<"no"<<endl;
            continue;
        }
        center--;
        int sum = 0;
        for1(i,center-k,center+k+1) {
            sum += data[i];
        }
        cout<<sum<<endl;
	}
	return 0;
}
