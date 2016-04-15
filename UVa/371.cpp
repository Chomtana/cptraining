#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long i,j;
    while(cin>>i && cin>>j) {
        if (i==0 && j==0) break;
        long long currmax = 0;
        long long result = -1;
        if (min(i,j)<=1) {
            currmax = 4;
            result = 1;
        }
        for (long long k=min(i,j);k<=max(i,j);k++) {
            long long n = k;
            long long count = 1;
            while (n!=1) {
                count++;
                if (n%2 == 1) {
                    n = 3*n+1;
                } else n/=2;
            }
            
            if (count>currmax) {
                currmax = count;
                result = k;
            }
            
            //cout<<k<<endl;
        }
        cout<<"Between "<<min(i,j)<<" and "<<max(i,j)<<", "<<result<<" generates the longest sequence of "<<currmax-1<<" values.\n";
    }
    
    return 0;
}