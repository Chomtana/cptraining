#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    string s; cin>>s;
    int level = 0;
    int res = 0;
    if(s[0]==')') res++; else level++;
    for1(i,1,s.size()) {
        if (s[i]=='(') {
            /*if (s[i-1]=='(') level++; else {
                res += level;
                level = 1;
            }*/
            level++;
        } else {
            level--;
            if (level<0) {
                res++;
                level = 0;
            }
        }
    }

    cout<<res+level;
	return 0;
}
