#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long n,b,h,w; 
    while (cin>>n>>b>>h>>w) {
        long long currmin = 200000000;
        
        while (h--) {
            long long p; cin>>p;
            bool ok = false;
            for (int i = 0;i<w;i++) {
                long long _; cin>>_;
                if (_>=n) {
                    ok=true;
                }
            }
            
            if (ok && p*n<=b) {
                currmin = min(currmin,p*n);
            }
        }
        if (currmin == 200000000) {
            cout<<"stay home\n";
        } else {
            cout<<currmin<<endl;
        }
    }
    return 0;
}