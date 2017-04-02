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
	int t; cin>>t;
	while (t--) {
        int n; cin>>n;
        vector<int> data(n);
        for1(i,0,n) {
            cin>>data[i];
        }

        priority_queue<int,vector<int>,greater<int>> pq;

        for1(i,0,n) pq.push(data[i]);

        int res = 0;

        while(true) {
            int freeze = pq.top();
            pq.pop();
            pq.push(freeze+1);
            res++;
            if (pq.top()==res) break;

        }

        cout<<res<<endl;

	}
	return 0;
}
