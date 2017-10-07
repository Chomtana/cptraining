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

int F[50005];
int B[50005];
int S[50005];//f=F , t=B

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m; cin>>n>>m;
    for1(i,0,n) {
        scanf("%d%d",F+i,B+i);
    }

    while (m--) {
        int x; scanf("%d",&x);
        for1(i,0,n) {
            if(S[i]) {
                if (B[i]<=x) S[i]=!S[i];
            } else {
                if (F[i]<=x) S[i]=!S[i];
            }
        }

    }

    for1(i,0,n) {
        printf("%d\n",(S[i]?B[i]:F[i]));
    }
	return 0;
}
