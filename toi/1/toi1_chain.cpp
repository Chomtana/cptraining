#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int l,n; cin>>l>>n;
    string before; cin>>before;
    //bool printed = false;
    n--;
    while (n--) {
        string s; cin>>s;
        int noteqc = 0;
        for1(i,0,s.size()) {
            if (s[i] != before[i]) {
                noteqc++;
            }
        }

        if (noteqc>2) {
            //printed = true;
            cout<<before;
            return 0;
        }

        before = s;
    }
    //if(!printed) {
        cout<<before;
    //}


    return 0;
}
