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
    for(char &c:s) {
        if (c=='L') {
            printf("#\n#\n###\n\n");
        } else if (c=='O') {
            printf("###\n# #\n###\n\n");
        }
         else if (c=='V') {
            printf("# #\n# #\n # \n\n");
        }
         else if (c=='E') {
            printf("###\n##\n###\n\n");
        }

    }
	return 0;
}
