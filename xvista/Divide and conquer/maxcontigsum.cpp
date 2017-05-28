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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; scanf("%d",&n);
    for1(i,0,n) scanf("%d",data+i);
    int res = -1;
    int currsum = 0;
    for1(i,0,n) {
        currsum += data[i];
        res = max(res,currsum);
        if (currsum<0) {
            currsum = 0;
        }
    }

    if (res==-1) {
        cout<<*max_element(data,data+n);
    } else {
        cout<<res;
    }
	return 0;
}
