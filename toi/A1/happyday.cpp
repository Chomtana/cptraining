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
	int before; cin>>before;
	n--;
	int res = 0;
	while (n--) {
        int curr; cin>>curr;

        if (curr >= 80) {
            res++;
        } else if (curr >= 20 && curr-before>=10) res++;


        before = curr;
	}
	cout<<res;
	return 0;
}
