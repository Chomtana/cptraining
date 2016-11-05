#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n;
	while (cin>>n) {
        bool ok[n];
        fill(ok,ok+n,false);
        int before; cin>>before;
        for1(i,1,n) {
            int x; cin>>x;
            int d = abs(x-before);
            ok[d] = true;

            before = x;
        }
        for1(i,1,n) {
            if (!ok[i]) {
                cout<<"Not jolly"<<endl;
                goto nextcase;
            }
        }
        cout<<"Jolly"<<endl;
        nextcase:
            continue;
	}
	return 0;
}
