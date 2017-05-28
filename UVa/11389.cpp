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
    int n,d,r;
    while (scanf("%d %d %d",&n,&d,&r) , n!=0) {
        int a1[n]; for1(i,0,n) scanf("%d",a1+i);
        int a2[n]; for1(i,0,n) scanf("%d",a2+i);
        sort(a1,a1+n);
        sort(a2,a2+n,greater<int>());

        int res = 0;

        for1(i,0,n) {
            int sum = (a1[i]+a2[i]-d);
            if (sum<=0) sum = 0;
            res += sum*r;

        }

        printf("%d\n",res);
    }
	return 0;
}
