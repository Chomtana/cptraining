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
	double P[n][3];
	for1(i,0,n) {
        cin>>P[i][0]>>P[i][1]>>P[i][2];
	}
    double val[n][3];
    for1(i,0,n) cin>>val[i][0]>>val[i][1]>>val[i][2];

    double sum = 0;

    for1(i,0,n) {
        for1 (j,0,3) {
            sum += (P[i][j]-val[i][j])*(P[i][j]-val[i][j]);
        }
    }

    sum /= n;

    printf("%.2f",sum);

	return 0;
}
