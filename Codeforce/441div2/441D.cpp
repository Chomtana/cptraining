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

int n;
bool data[300005];
int currtail = 0;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    printf("1 ");
    for1(i,0,n) {
        int p; scanf("%d",&p); p--;
        data[p] = true;
        int res = currtail;
        int k;
        for(k = n-1-currtail;k>=0;k--) {
            if (!data[k]) break;
            res++;
        }
        currtail = n-k-1;
        res = (i+1)-res+1;
        printf("%d ",res);
    }
	return 0;
}
