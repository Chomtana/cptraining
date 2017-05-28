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
    string res = "";

    subfunc(void,changedir,(int target)) {
        while (dir!=target) {
            res += 'R';
            dir++;
            if (dir>3) dir=0;
        }
    };

    for(char &c:s) {
        switch (c) {
            case 'N': {
                changedir(0);
                res += 'F';
            } break;
            case 'E': {
                changedir(1);
                res += 'F';
            } break;
            case 'S': {
                changedir(2);
                res += 'F';
            } break;
            case 'W': {
                changedir(3);
                res += 'F';
            } break;
            case 'Z': {
                res += 'Z';
                dir = 0;
            } break;
        }
    }

    cout<<res;
	return 0;
}
