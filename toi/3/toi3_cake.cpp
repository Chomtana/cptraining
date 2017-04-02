#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; scanf("%d",&n);
	int order[5];
	for1(i,0,5) order[i] = 0;
    for1(i,0,n) {
        int a,b,c,d,e; scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        order[0] += a;
        order[1] += b;
        order[2] += c;
        order[3] += d;
        order[4] += e;
    }

    /*for1(i,0,5) cout<<order[i]<<' ';
    cout<<endl;*/

    int res = 0;
    res += order[0];
    res += order[1];
    order[3] -= order[1];

    if (order[3]<0) {
        order[4] -= abs(order[3])*2;
        order[3] = 0;
        if (order[4]<0) order[4] = 0;
    }
    res += order[2]/2;
    if (order[2]%2!=0) {
        res++;
        //cake size 4 1 remaining sub to size 2 -> 2 aun (4 dai 2 2 aun)
        order[3] -= 2;
        if (order[3]<0) {
            order[4] -= abs(order[3])*2;
            order[3] = 0;
            if (order[4]<0) order[4] = 0;
        }
    }
    if (order[3]>0) {
        int add = (order[3]-1)/4+1;
        int remain = 2*(4-(order[3]%4));
        //cout<<4<<endl;
        if (order[3]%4 == 0) remain = 0;
        res += add;
        order[4] -= remain;
        if (order[4]<0) order[4] = 0;

    }
    if (order[4]>0) {
        res += (order[4]-1)/8+1;
    }

    cout<<res;
	return 0;
}
