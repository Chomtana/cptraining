#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t;
    for1(_,1,t+1) {
        cout<<"Case "<<_<<": ";
        int currmax = 0;
        int n; cin>>n;
        while (n--) {
            int x; cin>>x;
            currmax =max(currmax,x);
        }
        cout<<currmax<<endl;
    }
	return 0;
}
