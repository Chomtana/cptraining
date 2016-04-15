#include <bits/stdc++.h>

using namespace std;

int main() {
    int w,h,n;cin>>w>>h>>n;
    vector<int> level(w); //level= 0:filter0% 1:50% 2:100% 3:100% ....
    while(n--) {
        int start,size;cin>>start>>size;
        for (int i = 0;i<size;i++) {
            if (i+start >= w) break;
            level[i+start]++;
        }
    }
    int ans1=0,ans2=0; //filter 0% , 50%
    for (int i=0;i<w;i++) {
        if (level[i] == 0) ans1 += h;
        else if (level[i] == 1) ans2 += h;
    }
    cout << ans1 << " " << ans2;
    return 0;
}

//fix array index out of bound bug