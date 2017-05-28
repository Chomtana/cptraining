#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n;
    while (cin>>n) {
        string s; cin>>s;
        map<string,int> c;
        for1(i,0,s.size()-n+1) {
            c[s.substr(i,n)]++;
        }
        string res;
        int currmax=0;
        for(auto &p:c) {
            if (p.second>currmax) {
                currmax = p.second;
                res = p.first;
            }
        }
        cout<<res<<endl;
    }
	return 0;
}
