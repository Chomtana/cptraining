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

int n;
vector<int> data;

bool process() {
    stack<int> st;
    int curr = 0;
    for1(i,1,n+1) {
        st.push(i);
        while (!st.empty() && st.top()==data[curr]) {
            st.pop();
            curr++;
        }
    }
    return st.size()==0;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    while (scanf("%d",&n),n!=0) {
        data.resize(n);

        int first;
        while (scanf("%d",&first),first!=0) {
            data[0] = first;
            for1(i,0,n-1) {
                scanf("%d",&data[i+1]);
            }

            if (process()) printf("Yes\n"); else printf("No\n");
        }

        printf("\n");

        data.clear();
    }
	return 0;
}
