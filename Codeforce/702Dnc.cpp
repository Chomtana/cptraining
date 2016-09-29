#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;

/*
two optimal solution found
drive , repair , drive , repair , drive , ... , walk/drive
drive , walk , walk , walk , walk , ... , walk
*/

int main() {
    ios::sync_with_stdio(false);
    ll d,k,a,b,t; cin>>d>>k>>a>>b>>t;
    ll tb = (t%b==0?t/b:t/b+1);
    ll n = d/(k+tb);
    cout<<n*(k*a + b*tb);


    return 0;
}
