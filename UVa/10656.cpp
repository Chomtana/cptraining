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
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n;
    while (scanf("%d",&n),n!=0) {
        bool p = false;
        while (n--) {
            int x; scanf("%d",&x);
            if (x!=0) {
                printf("%d",x);
                if (n!=0) printf(" ");
                p = true;
            }
        }
        if (!p) printf("0");
        printf("\n");

    }
	return 0;
}
