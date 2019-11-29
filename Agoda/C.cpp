#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define for1(a,b,c) for(int a=b;a<c;a++)

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin>>t;
    for1(_,1,t+1) {
        int cas,len; scanf("%d %d",&cas,&len);
        if (len==0) {
            printf("%d\n",cas);
            continue;
        }
        cin.ignore();
        string s; getline(cin,s);
        s = s.substr(0,len);
        int n; scanf("%d",&n);
        int pos = 0;
        printf("%d ",cas);
        string res = "";
        for1(i,0,n) {
            int x; scanf("%d", &x);
            pos += x;
            if (pos >= 0) {
                pos %= len;
                res += s[pos];
            } else {
                int pos2 = (abs(pos)-1)%len;
                res += s[s.size() - pos2 - 1];
            }
        }
        
        cout<<res<<'\n';
    }
    return 0;
}
