#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin>>t;
    int x = 0;
    while (t--) {
        string s; cin>>s;
        char op = s[1];
        if (op=='+') {
            x++;
        } else {
            x--;
        }
    }
    cout<<x;
    return 0;
}

