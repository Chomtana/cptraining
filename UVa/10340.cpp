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
    string child,mother;
    while (cin>>child>>mother) {
        int currpos = -1;
        bool ok = true;
        for(char &c:child) {
            currpos = mother.find(c,currpos+1);
            if (currpos==string::npos) {
                ok = false;
                break;
            }
        }

        cout<<(ok?"Yes":"No")<<endl;

    }
	return 0;
}
