#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        int data[n];
        for1(i,0,n) {
            cin>>data[i];
        }

        ll sum = 0;
        for1(i,0,n) {
            for1(j,0,i) {
                if (data[j]<=data[i]) sum++;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
