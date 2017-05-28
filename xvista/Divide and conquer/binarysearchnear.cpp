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

int data[100005];

int n;

int bs(int x) {
    //remember : answer is +-1 ... if answer +-1 is not correct -> toggle (add or delete) = in next condition (data[mid]...x) step
    //use [s,e] (aow,aow) style
    int s = 0;
    int e = n-1;
    while (s<=e) {
        int mid = (s+e)/2;
        //we want ans<=x
        if (data[mid]>x) {
            e = mid-1;
        } else {
            s = mid+1;
        }
    }

    return (s-1<0?-1:data[s-1]);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; scanf("%d%d",&n,&t);
     for1(i,0,n) scanf("%d",data+i);
    while (t--) {
        int x; scanf("%d",&x);
        printf("%d\n",bs(x));
    }
	return 0;
}
