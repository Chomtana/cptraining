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
	string s; cin>>s;
	int x = 0;
	int y = 0;
	for1(i,0,s.size()) {
        if (s[i]=='N') {
            y++;
        } else if (s[i]=='E') {
            x++;
        } else if (s[i]=='S') {
            y--;
        } else if (s[i]=='W') {
            x--;
        } else {
            x = 0;
            y = 0;
        }
	}
	cout<<x<<' '<<y;
	return 0;
}
