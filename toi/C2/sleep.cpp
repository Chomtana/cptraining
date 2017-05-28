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
    int n; scanf("%d",&n);
    int maxs = 0;
    int mine = 2E9;
    while (n--) {
        int s,e; scanf("%d%d",&s,&e);
        maxs = max(maxs,s);
        mine = min(mine,e);
    }
    if (maxs>mine) cout<<"yes"; else cout<<"no";
	return 0;
}
