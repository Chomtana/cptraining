#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);++(a))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    int n; cin>>n;
    map<string,string> data;
    for1(i,0,n) {
        string a,b; cin>>a>>b;
        data[a] = b;
    }
    int t; cin>>t; while(t--) {
        string s; cin>>s;
        cout<<data[s]<<endl;
    }
    return 0;
}
