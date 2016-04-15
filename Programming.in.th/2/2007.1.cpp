#include <bits/stdc++.h>

using namespace std;

int gn,n;
string g,s;

void reset(int data[256]) {
    for (char i = 'a';i<='z';i++) data[i] = 0;
    for (char i = 'A';i<='Z';i++) data[i] = 0;
}

int main() {
    cin>>gn>>n;
    cin.ignore();
    getline(cin,g);
    getline(cin,s);
    int result = 0;
    int base[256]; //g charcount
    int current[256]; //processing charcount
    reset(base); reset(current);
    for (int i = 0;i<gn;i++) {
        base[g[i]]++;
    }
    for (int i = 0;i<n-gn+1;i++) {
        bool add = false;
        if (base[s[i]] >= 1) {
            add = true;
            current[s[i]]++;
            for (int j=i+1;j<i+gn;j++) {
                current[s[j]]++;
                if (current[s[j]] > base[s[j]]) {
                    add = false;
                }
            }
            if (add) { //affect very less
                while (i+gn<n && s[i] == s[i+gn]) {
                    result++;
                    i++;
                }
            }
            //if (add) cout << i << '\n';
            reset(current);
        }
        /*while (s[i+j] == g[j] && j<gn) {
            j++;
            if (j == gn) goto doadd;
        }
        add = false;*/
        //doadd:
        if (add) result++;
    }
    cout << result;


    return 0;
}
