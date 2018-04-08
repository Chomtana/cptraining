#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int c[10000];

int main() {
    int h,l,n; cin>>h>>l>>n;
    int r = l+h;
    
    for1(i,0,n) {
        int x; cin>>x;
        if (x>=l && x<=r) {
            c[x]++;
        }
    }
    
    cout<<*max_element(c,c+10000);
    return 0;
}