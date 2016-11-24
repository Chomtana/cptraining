#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<char>> matrix;

void rot(matrix &a) {
    matrix aa = a;
    for1(i,0,a.size()) {
        for1(j,0,a.size()) {
            a[j][a.size()-i-1] = aa[i][j];
        }
    }
}

int count(matrix &A,matrix &a) {
    int c = 0;
    for1(i,0,A.size()-a.size()+1) {
        for1(j,0,A.size()-a.size()+1) {
            bool ok = true;
            for1(x,i,i+a.size()) {
                for1(y,j,j+a.size()) {
                    if (a[x-i][y-j] != A[x][y]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            c += ok;
        }
    }
    return c;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int N,n;
    while (cin>>N>>n,N!=0) {
        matrix A(N,vector<char>(N));
        matrix a(n,vector<char>(n));
        for1(i,0,N) {
            for1(j,0,N) {
                cin>>A[i][j];
            }
        }
        for1(i,0,n) {
            for1(j,0,n) {
                cin>>a[i][j];
            }
        }

        cout<<count(A,a)<<' ';
        rot(a);
        cout<<count(A,a)<<' ';
        rot(a);
        cout<<count(A,a)<<' ';
        rot(a);
        cout<<count(A,a)<<'\n';
    }
	return 0;
}
