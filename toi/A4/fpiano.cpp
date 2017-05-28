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
    int n; cin>>n; n--; n%= 7;
    switch (n) {
    case 0: cout<<'C'; break;
    case 1: cout<<'D'; break;
    case 2: cout<<'E'; break;
    case 3: cout<<'F'; break;
    case 4: cout<<'G'; break;
    case 5: cout<<'A'; break;
    case 6: cout<<'B'; break;
    }
	return 0;
}
