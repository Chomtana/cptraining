#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int t; cin>>t;
    for1(_t,1,t+1) {
        cout<<"Case #"<<_t<<": ";
        bool x = false;
        bool t = false;
        bool _ = false;
        string s; cin>>s;
        for1(i,0,s.size()) {
            switch (s[i]) {
            case 'X':
                x = true; break;
            case 'T':
                t = true; break;
            case '-':
                _ = true; break;
            }
        }
        if (!x && !t && !_) {
            cout<<"Yes";
        } else {
            if (x) {
                cout<<"No - Runtime error";
            } else if (t) {
                cout<<"No - Time limit exceeded";
            } else if (_) {
                cout<<"No - Wrong answer";
            }
        }
        cout<<endl;
    }
    return 0;
}
