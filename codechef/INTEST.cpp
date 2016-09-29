#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
    int t,k; cin>>t>>k;
    int c = 0;
    while (t--) {
        int x; cin>>x;
        if (x%k==0) {
            c++;
        }
    }
    cout<<c;
    return 0;
}