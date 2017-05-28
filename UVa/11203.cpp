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
    int t; cin>>t; cin.ignore(); while(t--) {
        string s; getline(cin,s);
        int bfm = 0;
        int btm = 0;
        int afm = 0;

        int pos = 0;

        bool ok = true;

        subfunc(void,doadd,()) {
            if (pos==0) bfm++; else if (pos==1) btm++; else if (pos==2) afm++;
        };

        for1(i,0,s.size()) {
            if(s[i]=='?') {
                doadd();
            } else if (s[i]=='M') {
                if (pos==0) pos++; else {
                    ok = false;
                    break;
                }
            } else if (s[i]=='E') {
                if (pos==1) pos++; else {
                    ok = false;
                    break;
                }
            } else {
                ok = false;
                break;
            }
        }

        if (btm<1) ok=false;

        if (!ok) {
            printf("no-theorem\n"); continue;
        }

        afm -= btm-1;

        if (bfm!=afm-1 || bfm<1 || afm<2) {
            ok = false;
        }

        if (ok) {
            printf("theorem\n");
        } else {
            printf("no-theorem\n");
        }
    }
	return 0;
}
