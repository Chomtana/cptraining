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
	int n; cin>>n;
    int curr = 1;
    vector<vector<char>> data(n,vector<char>(n,' '));
    for(int i = n-1;i>=1;i--) {
        data[i][0] = curr%10+'0';
        curr++;
    }
    for1(i,0,n) {
        data[i][i] = curr%10+'0';
        curr++;
    }
    for(int i = n-2;i>=0;i--) {
        data[i][n-1] = curr%10+'0';
        curr++;
    }
    for1(i,0,n) {
        for1(j,0,n) {
            cout<<data[i][j]<<' ';
        }
        cout<<endl;
    }
	return 0;
}
