#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; while(t--) {
        string s; cin>>s;
        if (s=="1" || s=="4" || s=="78") {
            cout<<"+\n";
        } else if (s.size()>=2 && s[s.size()-1]=='5' && s[s.size()-2]=='3') {
            cout<<"-\n";
        } else if (s.size()>=2 && s[0]=='9' && s[s.size()-1]=='4') {
            cout<<"*\n";
        } else if (s.size()>=3 && s[0]=='1' && s[1]=='9' && s[2]=='0') {
            cout<<"?\n";
        } else {
            cout<<"?\n";
        }
	}
	return 0;
}
