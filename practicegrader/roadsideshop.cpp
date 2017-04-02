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
    int n,k; cin>>n>>k;
    k = 2*k+1;

    int currsum = 0;
    int maxsum = -1;

    deque<int> kinput(k);

    for1(i,0,k) {
        int x; cin>>x;
        currsum += x;
        kinput[i] = x;
    }

    maxsum = max(maxsum,currsum);

    for1(i,0,n-k) {
        int x; cin>>x;
        currsum -= kinput[0];
        currsum += x;
        kinput.pop_front();
        kinput.push_back(x);

        maxsum = max(maxsum,currsum);
    }

    cout<<maxsum;

	return 0;
}
