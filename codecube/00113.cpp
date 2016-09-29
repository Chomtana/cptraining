#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

bool printed = false;

void pn(int n,int c) {
    if (c>0) printed = true;
    while (c--) cout<<n;
}

int main() {
    int p; cin>>p;
    int data[10];
    bool veryim = true;
    for1(i,0,10) {
        cin>>data[i];
        if (data[i]<=p) {
            veryim = false;
        }
    }
    if (veryim) {
        cout<<-1; return 0;
    }
    for(int i = 9;i>=0&&p!=0;i--) {
        if (i==0 && !printed) {
            cout<<-1; return 0;
        }
        pn(i,p/data[i]);
        p %= data[i];
    }
    return 0;
}
