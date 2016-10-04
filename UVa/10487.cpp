#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    int n;
    int t = 0;
    while (t++ , cin>>n , n) {
        cout<<"Case "<<t<<":"<<endl;
        int data[n];
        vector<int> sum;
        for1(i,0,n) {
            cin>>data[i];
        }
        for1(i,0,n) {
            for1(j,i+1,n) {
                sum.push_back(data[i]+data[j]);
            }
        }
        sort(sum.begin(),sum.end());

        int k; cin>>k;
        for1(i,0,k) {
            int x; cin>>x;
            cout<<"Closest sum to "<<x<<" is ";
            auto it = upper_bound(sum.begin(),sum.end(),x);
            int d1 = abs(x-*it);
            if (it != sum.begin()) {
                it--;
                int d2 = abs(x-*it);
                if (d2<d1) {
                    cout<<*it;
                } else {
                    cout<<*(it+1);
                }
            } else {
                cout<<*it;
            }
            cout<<".\n";
        }
    }

    return 0;
}
