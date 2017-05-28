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
    int b; cin >>b;
    int cases = 0;
    while (b--) {
        int n; scanf("%d",&n);
        int data[n-1]; for1(i,0,n-1) scanf("%d",data+i);

        int sum = 0;
        int currmax = 0;
        int starti = 0;
        int maxstarti = -1;
        //int maxendi = -1; //maxendi = maxstarti+len
        int len = -1;
        for1(i,0,n-1) {
            sum += data[i];
            if (sum<0) {
                sum = 0;
                starti = i+1;
                continue;
            }
            if (sum>currmax) {
                currmax = sum;
                maxstarti = starti;
                //maxendi = i+1;
                len = i - starti + 1;
            } else if (sum==currmax) {
                int currlen = i - starti + 1;
                if (currlen > len) {
                    len = currlen;
                    maxstarti = starti;
                }
            }
        }

        if (currmax>0) {
            printf("The nicest part of route %d is between stops %d and %d\n", ++cases, maxstarti+1, maxstarti+len+1);
        } else {
            printf("Route %d has no nice parts\n", ++cases);
        }


    }
	return 0;
}
