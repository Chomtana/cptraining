#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int minusmod(int x,int m) {
    if (x>=0) return x%m;
    int y = m-(abs(x)%m);
    if (y == m) return 0; else return y;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n,k; cin>>n>>k;
    int data[n][n];
	for1(i,0,n) {
	    if (i%(2*k) < k) {
            for1(j,0,n) {
                data[i][(i+j)%n] = (j+1)%10;
            }
	    } else {
            for1(j,0,n) {
                //cout<<i<<' '<<j<<' '<<minusmod(i-j,n)<<endl;
                data[i][minusmod(i-j,n)] = (j+1)%10;
            }
	    }
	}
	for1(i,0,n) {
        for1(j,0,n) {
            cout<<data[i][j]<<' ';
        }
        cout<<endl;
	}
	return 0;
}
