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
    int n,m; while (cin>>n>>m) {
        //int data[n];
        vector<vector<int>> cache(1000005);
        for1(i,0,n) {
            //scanf("%d",data+i);
            int x; scanf("%d",&x);
            cache[x].push_back(i+1);
        }

        while (m--) {
            int o,v; scanf("%d%d",&o,&v);
            if (o>cache[v].size()) {
                printf("0\n");
            } else {
                printf("%d\n",cache[v][o-1]);
            }
        }
    }
	return 0;
}
