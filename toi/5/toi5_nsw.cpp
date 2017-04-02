#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

deque<int> circle[3];

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    string key; cin>>key;
    string s; cin>>s;
    for1(i,0,3) {
        circle[i].push_back(key[i]-'0');
        for1(j,1,9) {
            circle[i].push_back(circle[i][j-1]%9+1);
        }
    }

    string out = "";

    for1(i,0,s.size()) {
        /*for1(i,0,9) {
            cout<<circle[0][i]<<' '<<circle[1][i]<<' '<<circle[2][i]<<endl;
        }
        cout<<endl;*/
        //decode
        out += circle[2][circle[1][circle[0][s[i]-'0'-1]-1]-1] + '0';
        for1(j,0,key[0]-'0') {
            circle[0].push_back(circle[0][0]);
            circle[0].pop_front();
        }
        circle[1].push_front(circle[1][circle[1].size()]);
        circle[1].pop_back();
        for1(j,0,key[2]-'0') {
            circle[2].push_back(circle[2][0]);
            circle[2].pop_front();
        }
    }

    cout<<out;

	return 0;
}
