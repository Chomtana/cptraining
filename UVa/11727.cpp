#include <bits/stdc++.h>
#define cond(a) a!=mi && a!=ma

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t; cin>>t;
    for (int _t=1;_t<=t;_t++) {
        int a,b,c; cin>>a>>b>>c;
        int mi = min(a,min(b,c));
        int ma = max(a,max(b,c));
        cout<<"Case "<<_t<<": ";
        if (cond(a)) cout<<a;
        else if (cond(b)) cout<<b;
        else if (cond(c)) cout<<c;
        cout<<endl;
    }
    return 0;
}