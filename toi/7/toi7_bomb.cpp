#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef pair<int,int> pii;

/*
select all left>:
if sum of right[i+...] < n(i+...)*right[i] then all right[i+...] < right[i] -> don't select
*/

int main() {
    int n; cin>>n;
    pii data[n];
    for1(i,0,n) {
        cin>>data[i];
    }
    sort(data,data+n);
    for1(i,0,n) {
        int remain = len-i-1;

    }



    return 0;
}
