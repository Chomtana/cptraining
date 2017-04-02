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
    int t; cin>>t;
    while (t--) {
        int n,m; scanf("%d:%d",&n,&m);
        vector<int> data(n);
        for1(i,0,n) data[i]=i+1;
        int curr = m-1;
        while (data.size()>0) {
            cout<<data[curr];
            if (data.size()>1) {
                cout<<"->";
            } else {
                cout<<endl;
                break;
            }
            data.erase(data.begin()+curr);
            curr += m-1;
            if (curr>=data.size()) curr %= data.size();
        }
    }
	return 0;
}
