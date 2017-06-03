#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(a,b,c) for(int (a)=(b);((b)<(c)?(a)<(c):(a)>=(c));a+=((b)<(c)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    int n; cin>>n;
    vector<vector<int>> data(n);
    for1(i,0,n) {
        int m; scanf("%d",&m);
        data[i].resize(m);
        for1(j,0,m) {
            scanf("%d",&data[i][j]);
        }
        sort(all(data[i]));
        
    }

    int k; cin>>k;
    for1(i,0,n) {
        if (k>data[i].size()) {
            printf("%d\n",-1);
        } else {
            printf("%d\n",data[i][k-1]);
        }
    }
    return 0;
}
