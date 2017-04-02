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

    int n;
    while (cin>>n,n!=0) {
        map<tuple<int,int,int,int,int>,int> count;

        for1(i,0,n) {
            int a[5]; cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
            sort(a,a+5);
            count[make_tuple(a[0],a[1],a[2],a[3],a[4])]++;
        }


        int countmax = 0;
        for(auto it = count.begin();it != count.end();it++) {
            countmax = max(countmax,it->second);
        }

        int res = 0;
        for(auto it = count.begin();it != count.end();it++) {
            if (it->second == countmax) {
                res++;
            }
        }

        cout<<res*countmax<<endl;
    }


	return 0;
}
