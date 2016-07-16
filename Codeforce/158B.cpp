#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
    int n; cin>>n;
    //int c = 0;
    int res = 0;
    int data[n];
    int count[5];
    fill(count,count+5,0);
    for1(i,0,n) {
        int x; cin>>x; count[x]++;
    }
    res += count[4];
    res += count[2]/2;
    if (count[2]&1 == 1) {
        count[2] = 1;
    } else {
        count[2] = 0;
    }
    res += min(count[1],count[3]);
    //cout<<count[3]<<endl;
    int xx = min(count[1],count[3]); //min at time before decrease count
    count[1] -= xx;
    count[3] -= xx;
    
    res += count[3];
    count[3] = 0;
    res += count[1]/4;
    count[1] %= 4;
    if (count[1] > 0) {
        if (count[2]==0) {
            res += 1;
        } else {
            if (count[1]<3) {
                res += 1;
            } else {
                res += 2;
            }
        }
    } else {
        if (count[2]>0) {
            res += 1;
        }
    }
    cout<<res;
    return 0;
}