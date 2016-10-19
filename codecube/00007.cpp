#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a) = (b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    string a,b; cin>>a>>b;
    transform(a.begin(),a.end(),a.begin(),::tolower);
    transform(b.begin(),b.end(),b.begin(),::tolower);
    string s ="";
    for1(i,0,a.size()) {
        int x;
        if (a[i]>b[i]) {
            x = a[i]-b[i];
        } else {
            x = 'z'-b[i]+a[i]-'a'+1;
        }
        if (a[i]==b[i]) x=0;
        //cout<<x<<' '<<(int)a[i]<<' '<<(int)b[i]<<endl;
        if (x>9) {
            cout<<"R.I.P.";
            return 0;
        } else {
            s += x+'0';
        }
    }
    cout<<s;
    return 0;
}
