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

vector<char> data;

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    int n; cin>>n;
    data.resize(n);
    for1(i,0,n) {
        cin>>data[i];
    }
    
    //sort(all(data));
    
    cout<<(unique(all(data))-data.begin())+1;
    

    return 0;
}
