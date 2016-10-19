#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

string s;

int check(string x) {
    int c = 1;
    string y = x;
    if (s.size()%x.size() != 0) return 0;
    while (x.size()<s.size()) {
        x+=y;
        c++;
    }

    if (x==s) {
        int res = 0;
        for1(i,1,(int)(sqrt(c)+1)) {
            if (c%i==0) {
                if (c/i == i) res--;
                res+=2;
            }
        }
        return res;
    } else {
        return 0;
    }
}

int main () {
    ios::sync_with_stdio(false);

    //cout<<check("x");
    for1(_,0,5) {
        cin>>s;
        string y = "";
        for1(i,0,s.size()) {
            y += s[i];
            int x = check(y);
            if (x!=0) {
                cout<<x<<endl; break;
            }
        }
    }
    return 0;
}
