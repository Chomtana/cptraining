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
	int data[n];
	for1(i,0,n) cin>>data[i];
    make_heap(data,data+n);
    for1(i,0,n) cout<<data[i] << ' ';
    sort_heap(data,data+n);
    cout<<endl;
    for1(i,0,n) cout<<data[i]<<' ';
	return 0;
}
