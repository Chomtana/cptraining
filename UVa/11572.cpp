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
    int t; cin>>t;
    while (t--) {
        int n; scanf("%d",&n);
        int data[n];
        for1(i,0,n) scanf("%d",data+i);
        set<int> curr;
        int res = 0;
        int f = 0;
        for1(i,0,n) {
            if(curr.find(data[i])==curr.end()) {
                curr.insert(data[i]);
                res = max(res,int(curr.size()));
            } else {
                res = max(res,int(curr.size()));
                while (data[f]!=data[i]) {
                    curr.erase(data[f]);
                    f++;
                }
                f++;
            }
        }
        printf("%d\n",res);
    }
	return 0;
}
