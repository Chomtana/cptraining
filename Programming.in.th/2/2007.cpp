#include <bits/stdc++.h>

using namespace std;

int gn,n;
string g,s;

int base[256]; //g charcount
int current[256]; //processing charcount

void reset(int data[256]) {
    for (char i = 'a';i<='z';i++) data[i] = 0;
    for (char i = 'A';i<='Z';i++) data[i] = 0;
}

bool check() {
    bool result = true;
    for (char i = 'a';i<='z';i++) if(base[i]!=current[i]) result = false;
    for (char i = 'A';i<='Z';i++) if(base[i]!=current[i]) result = false;
    return result;
}

int main() {
    cin>>gn>>n;
    cin.ignore();
    getline(cin,g);
    getline(cin,s);
    int result = 0;
    reset(base); reset(current);
    for (int i = 0;i<gn;i++) {
        base[g[i]]++;
        current[s[i]]++;
    }
    result += check();
    for (int i = gn;i<n;i++) {
        //i == gn -> delete index 0 = i-gn
        current[s[i-gn]]--;
        current[s[i]]++;
        result += check();
    }
    cout << result;


    return 0;
}
