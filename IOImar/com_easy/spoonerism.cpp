#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;

bool isv(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main() {
    int n; cin>>n;
    for1(i,0,n) {
        string s; cin>>s;
        int fs = -1;
        int le = -1;
        for1(i,0,s.size()) {
            if (isv(s[i])) {
                le = i;
                if (fs==-1) fs = i;
            }
        }
        
        int fe = s.size()-1;
        int ls = 0;
        
        for1(i,fs,s.size()) {
            if (!isv(s[i])) {
                fe = i-1;
                break;
            }
        }
        
        for(int i = le;i>=0;i--) {
            if (!isv(s[i])) {
                ls = i+1;
                break;
            }
        }
        
        cerr<<fs<<' '<<fe<<' '<<ls<<' '<<le<<endl;
        
        cout<<s.substr(0,fs)<<' '<<s.substr(ls,le-ls+1)<<' '<<s.substr(fe+1,ls-fe-1)<<' '<<s.substr(fs,fe-fs+1)<<' '<<s.substr(le+1,s.size()-le+1)<<endl;
        
    }

    return 0;
}

// 
