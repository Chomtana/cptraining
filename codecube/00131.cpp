#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m; cin>>n>>m;
    int A[n]; int B[m];
    for1(i,0,n) cin>>A[i];
    for1(i,0,m) cin>>B[i];
    sort(A,A+n);
    sort(B,B+m);
    int type = -1;
    int currmin = 1E9;
    if (n>1) {
        int x = A[0]+A[1];
        if (x<currmin) {
            currmin = x;
            type = 0;
        }
    }
    if (m>1) {
        int x = B[0]+B[1];
        if (x<currmin) {
            currmin = x;
            type = 1;
        }
    }
    int x = A[0]+B[0]+100;
    if (x<currmin) {
        currmin = x;
        type = 2;
    }

    cout<<currmin;

	return 0;
}
