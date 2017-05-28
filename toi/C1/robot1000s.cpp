#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int dir = 0; //NESW
    string s; cin>>s;
    int k; cin>>k;
    //sort(all(s));
    int cn=0,ce=0,cs=0,cw=0;
    int res = 0;

    subfunc(int,process,()) {
        if (cn>cs) {
            if (cs>k) {
                cs -= k;
                k = 0;
            } else {
                k -= cs;
                cs = 0;
            }
        } else {
            if (cn>k) {
                cn -= k;
                k = 0;
            } else {
                k -= cn;
                cn = 0;
            }
        }

        if (ce>cw) {
            if (cw>k) {
                cw -= k;
                k = 0;
            } else {
                k -= cw;
                cw = 0;
            }
        } else {
            if (ce>k) {
                ce -= k;
                k = 0;
            } else {
                k -= ce;
                ce = 0;
            }
        }

        return (abs(cn-cs)+abs(ce-cw)-k)*2;
    };

    for(char &c:s) {
        switch (c) {
            case 'N':cn++;break;
            case'E':ce++;break;
            case'S':cs++;break;
            case'W':cw++;break;
            case'Z':
                //res = max(res,process());
                //cn=0,ce=0,cs=0,cw=0;
                break;
        }
    }

    cout<<process();
	return 0;
}
