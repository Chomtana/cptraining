#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int ispal(string &s) {
    for1(i,0,s.size()/2) {
        if (s[i] != s[s.size()-1-i]) return 0;
    }
    return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    string s; cin>>s;
    cout<<ispal(s);
	return 0;
}
