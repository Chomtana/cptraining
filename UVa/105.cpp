#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int l,h,r;
    int maxr = 0;
    vector<int> H(20000); //H[x] = h at pos x = result at pos x
    while (cin>>l) {
    //int t; cin>>t; while (t--) {
        //cin>>l;
        cin>>h>>r;
        maxr = max(maxr,r);
        for1(i,l,r) {
            H[i] = max(H[i],h);
        }
    }

    for1(i,1,maxr+1) {
        if (H[i]!=H[i-1]) {
            cout<<i<<' '<<H[i];
            if (i!=maxr) cout<<' ';
        }
        //cout<<H[i]<<endl;
    }

    cout<<endl;

    return 0;
}
