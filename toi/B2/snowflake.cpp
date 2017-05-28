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

void pn(int n,char c) {
    while(n--) printf("%c",c);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    for(int i = 0,j=2*n-1;j>=1;j-=2,i++) {
        pn(i,' ');
        pn(1,'*');
        pn(j,' ');
        pn(1,'*');
        printf("\n");
    }
    pn(2*n+1,'*');
    printf("\n");
    for(int i = n-1,j=1;i>=0;j+=2,i--) {
        pn(i,' ');
        pn(1,'*');
        pn(j,' ');
        pn(1,'*');
        printf("\n");
    }
	return 0;
}
