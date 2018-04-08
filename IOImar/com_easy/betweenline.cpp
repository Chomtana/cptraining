#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int a[100000];

int main() {
    int n; cin>>n;
    int unix = 1;
    int mac = 1;
    int win = 1;
    
    for1(i,0,n) {
        int x; scanf("%d",&x);
        a[i] = x;
        if (x==10) {
            unix++;
        } else if (x==13) {
            mac++;
        }
    }
    
    for1(i,0,n-1) {
        if (a[i]==13 && a[i+1]==10) win++;
    }
    
    cout<<win<<' '<<unix<<' '<<mac;
    return 0;
}