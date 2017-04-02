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
	int n,k; cin>>k>>n;
    int data[n];
    for1(i,0,n) cin>>data[i];

    int res = -1;
    int currmin = 2E9+100;
    int subcurrmin = 2E9+100;
    int resi = -1;
    int resj = -1;

    for1(i,0,n) {
        for1(j,i+1,n) {
            if (data[i]==data[j]) continue;
            int sum = data[i]+data[j];
            int subdif = abs(data[i]-data[j]);
            int dif = abs(sum-k);
            if (dif<currmin) {
                currmin = dif;
                resi = i;
                resj = j;
                res = sum;
                subcurrmin = 2E9+100;
            } else if (dif==currmin && subdif < subcurrmin) {
                subcurrmin = subdif;
                resi = i;
                resj = j;
                res = sum;
            }
        }
    }

    cout<<res<<endl<<min(data[resi],data[resj])<<' '<<max(data[resj],data[resi]);
	return 0;
}
