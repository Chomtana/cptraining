#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; scanf("%d",&n);
    vector<pii> data(n);
    for1(i,0,n) scanf("%d %d",&data[i].first,&data[i].second);
    ll sum = 0;

    //This is meaning of jod

    for1(i,0,n) {
        for1(j,0,n) {
            if (i==j) continue;
            if (data[i].first > data[j].first && data[i].second < data[j].second) {
                sum += data[i].first + data[j].first;
            }
        }
    }

    cout<<sum;

	return 0;
}
