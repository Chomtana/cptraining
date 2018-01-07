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

bool check(int x) {
    int sum = x;
    while (x) {
        sum += x%10;
        x /= 10;
    }
    return sum==n;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    //for1(nn,10000000,10000006) {
        //n=nn;
        int k = 0;
        vector<int> res;
        //for1(i,1,n+1) {
        for(int i = n;i>=n-100000;i--) {
            if (check(i)) {
                k++;
                res.push_back(i);
            }
        }
        sort(all(res));
        cout<<k<<endl;
        for1(i,0,k) {
            printf("%d\n",res[i]);
        }
    //}
	return 0;
}
