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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m; cin>>n>>m;
    int data[n][m];
    for1(i,0,n) for1(j,0,m) cin>>data[i][j];
    int nm = max(n,m);
    int brute[nm];
    for1(i,0,nm) brute[i] = i;

    int maxsum = 0;

    do {
        int sum = 0;
        if (n<m) {
            for1(i,0,n) {
                sum += data[i][brute[i]];
            }
        } else {
            for1(i,0,m) {
                sum += data[brute[i]][i];
            }
        }

        maxsum = max(maxsum,sum);
    } while (next_permutation(brute,brute+nm));

    cout<<maxsum;
	return 0;
}
