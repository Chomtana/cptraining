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
    int n,k; scanf("%d %d",&n,&k);
    int data[n];
    for1(i,0,n) scanf("%d",data+i);
    int currmax = 0;
    for1(i,0,n) {
        int highest = data[i]+k;
        auto it = upper_bound(data,data+n,highest)-1;
        currmax = max(currmax,int(it-data-i));
    }
    printf("%d",currmax);
	return 0;
}
