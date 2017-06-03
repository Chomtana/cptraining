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

//int data[10005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n;
    while(scanf("%d",&n),n!=0) {
        int maxsum = 0;
        int sum = 0;
        for1(i,0,n) {
            int x; scanf("%d",&x);
            sum += x;
            if (sum<0) {
                sum = 0;
            }
            maxsum = max(maxsum,sum);
        }
        if(maxsum<=0) {
            printf("Losing streak.\n");
        } else {
            printf("The maximum winning streak is %d.\n",maxsum);
        }
    }
	return 0;
}
