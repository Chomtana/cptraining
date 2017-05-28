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
    int n;
    while (cin>>n) {
        int data[1<<n];
        for1(i,0,1<<n) {
            scanf("%d",data+i);
        }

        int po[1<<n];

        for1(i,0,1<<n) {
            po[i] = 0;
            for1(j,0,n) {
                int k = i;
                k^=(1<<j);
                po[i] += data[k];
            }
        }

        int res = 0;

        for1(i,0,1<<n) {
            int subres = po[i];
            for1(j,0,n) {
                int k = i;
                k^=(1<<j);
                res = max(res,subres+po[k]);
            }
        }

        printf("%d\n",res);
    }
	return 0;
}
