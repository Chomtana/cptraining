#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int cd(int a,int b) {
    if(a%b==0) return a/b; else return a/b+1;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,k; cin>>n>>k;
    int curr = 0;
    while(n--) {
        int x; scanf("%d",&x);
        if (curr<x) {
            x -= curr;
            int ans = cd(x,k);
            curr = ans*k;
            curr -= x;
            printf("%d\n",ans);
        } else {
            curr -= x;
            printf("0\n");
        }
    }
	return 0;
}
