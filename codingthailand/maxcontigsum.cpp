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
typedef vector<vector<int>> vvi;

int data[1000005];

int main() {
    cout<<fixed;
    int n; cin>>n;
    for1(i,0,n) {
        scanf("%d",data+i);
    }
    
    int res = 0;
    int sum = 0;
    for1(i,0,n) {
        sum += data[i];
        if (sum < 0) {
            sum = 0;
        }
        res = max(res,sum);
    }
    
    cout<<res;
    return 0;
}