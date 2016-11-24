#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    int s,b;
    while (cin>>s>>b,s!=0) {
        vi left(s);
        vi right(s);
        for1(i,0,s) {
            left[i] = i-1;
            right[i] = i+1;
        }
        right[s-1] = -1;
        while (b--) {
            int l,r; cin>>l>>r;
            l--; r--;
            if (right[r]!=-1) {
                left[right[r]] = left[l];
            }
            if (left[l] == -1) {
                cout<<'*';
            } else {
                cout<<left[l]+1;
            }
            cout<<' ';
            if (left[l] != -1) {
                right[left[l]] = right[r];
            }
            if (right[r] == -1) {
                cout<<'*';
            } else {
                cout<<right[r]+1;
            }
            cout<<'\n';
        }
        cout<<"-\n";
    }
    return 0;
}
