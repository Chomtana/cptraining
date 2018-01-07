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

int n,m;
int data[500000];

int oob(int mid) {
    int res = 0;
    for1(i,0,n) {
        res += ceil(double(data[i])/double(mid));
    }
    return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;
    for1(i,0,n) {
        scanf("%d",data+i);
    }

    int res = -1;

    int l = 0,r=2000000;
    while(l<=r) {
        int mid = (l+r)/2;

        int midres = oob(mid);

        /*if (midres==m) {
            res=mid;
            break;
        }*/
        if (midres>m) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout<<l;
	return 0;
}
