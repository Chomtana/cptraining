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
    int a,b,n; scanf("%d%d%d",&a,&b,&n);
    while (n--) {
        int x; scanf("%d",&x);
        int res = 1E9;
        for1(i,0,10001) {
            if (a*i>=x) {
                res = min(res,a*i);
                break;
            }

            int needmore = x-a*i;
            int use2 = needmore/b;
            if (needmore%b!=0) {
                use2++;
            }

            res = min(res,a*i+b*use2);
        }

        printf("%d\n",res);
    }
	return 0;
}
