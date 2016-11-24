#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

/**
list of up and down state change
1U,3D,7U,13D,...,x
  2  4  6
   2   2

x ÍÂÙè¾¨¹ì·Õè ?
x=3 -> x = 1+2 = ¾¨¹ì·Õè 2
x=7 -> x = 1+2+4 = 1+2(1+2) = ¾¨¹ì·Õè 3
x=13 -> x = 1+2+4+6 = 1+2(1+2+3) = ¾¨¹ì·Õè 4
x = 1+2(1+...+n) = ¾¨¹ì·Õè n+1
ËÒ n -> ÃÙé¾¨¹ì
x = 1+2(n/2(1+n)) = 1+n(1+n)
n(1+n) = x-1
n+n^2 = x-1
n+n^2+1-x = 0
n^2+n+(1-x) = 0
n = [-1+sqrt((-1)^2-4(1)(1-x))]/2
n = [-1+sqrt(1-4(1-x))]/2
n = [-1+sqrt(1-4+4x)]/2
n = [-1+sqrt(4x-3)]/2

n = 0 -> up
n = 1 -> down
n = 2 -> up
n = 3 -> down
*/

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    double s,x;
    while (cin>>s>>x,s!=0) {
        ll n = floor((-1+sqrt(4*x-3))/2);
        ll y = 1+n*(n+1);
        //cerr<<n<<' '<<y<<endl;
        bool up = true; //true=up false=down
        if ((n&1)==0) {
            up = false;
        }
        ll nn = ((n&1)==0?n/2:n/2+1);

        ll r = s/2 , c = s/2;

        if (!up) {
            r -= nn;
            c += nn;
        } else {
            r += nn;
            c -= nn;
        }

        if (x-y <= n+1) {
            if (up) {
                r -= x-y;
            } else {
                r += x-y;
            }
        } else {
            if (up) {
                r -= n+1;
                c += x-y-n-1;
            } else {
                r += n+1;
                c -= x-y-n-1;
            }
        }

        cout<<"Line = "<<r+1<<", column = "<<c+1<<"."<<endl;
    }
	return 0;
}
