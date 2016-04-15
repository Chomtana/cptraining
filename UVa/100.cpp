#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int i,j;
    while(cin>>i && cin>>j) {
        int currmax = 0;
        for (int k=min(i,j);k<=max(i,j);k++) {
            int n = k;
            int count = 1;
            while (n!=1) {
                count++;
                if (n%2 == 1) {
                    n = 3*n+1;
                } else n/=2;
            }
            
            currmax = max(count,currmax);
        }
        cout<<i<<' '<<j<<' '<<currmax<<endl;
    }
    
    return 0;
}