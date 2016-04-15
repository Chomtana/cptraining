#include <bits/stdc++.h>

using namespace std;

int main() {
    int k; cin>>k;
    while (k!=0) {
        int dx,dy; cin>>dx>>dy;
        while (k--) {
            int x,y; cin>>x>>y;
            if (x==dx || y==dy) cout<<"divisa";
            else if (y>dy && x>dx) cout<<"NE";
            else if (y>dy && x<dx) cout<<"NO";
            else if (y<dy && x<dx) cout<<"SO";
            else if (y<dy && x>dx) cout<<"SE";
            cout<<endl;
        }
        
        
        cin>>k;
    }
    return 0;
}