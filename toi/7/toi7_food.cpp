#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n,m; cin>>n>>m;
	bool forbid[n+1];
	fill(forbid,forbid+n+1,false);
	for1(i,0,m) {
        int x; cin>>x;
        forbid[x] = true;
	}

	vector<int> data(n);
	for1(i,0,n) data[i]=i+1;
	do {
        if (!forbid[data[0]]) {
            for1(i,0,n) {
                printf("%d ",data[i]);
                //cout<<data[i]<<' ';
            }
            printf("\n");
        }
	} while (next_permutation(all(data)));
	return 0;
}
