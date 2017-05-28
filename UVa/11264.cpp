#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;




int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
        int n; scanf("%d",&n);
        vector<ll> data(n);
        ll count = 0;

        for1(i,0,n) scanf("%lld",&data[i]);

        stack<ll> st;
        ll sum = 0;

        for1(i,0,n) {
            while (sum>=data[i]) {
                sum -= st.top();
                st.pop();
            }

            sum += data[i];
            st.push(data[i]);

            count = max(count,(ll)st.size());
        }

        printf("%d\n",count);
    }
	return 0;
}
