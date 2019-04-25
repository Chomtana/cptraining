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
typedef pair<bool,bool> pbb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int n;
string rival;

int main() {
    cout<<fixed;
    int t; cin>>t;
    for1(_,1,t+1) {
      //cannot.clear();
      cin>>n;
      cin>>rival;
      //resolveCannot();
      printf("Case #%d: ",_);
      for1(i,0,rival.size()) {
        if (rival[i]=='S') {
          printf("E");
        } else {
          printf("S");
        }
      }
      printf("\n");
    }
    return 0;
}