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

string notuse;
int xx;

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    getline(cin,notuse);
    for1(i,0,9) {
        cin>>xx;
    }
    char c;
    int count = 0;
    int maxcount = 0;
    int line = 1;
    while (cin>>c) {
        if (c=='P') {
            cin>>xx;
            count=0;
        } else {
            cin>>xx>>xx;
            count++;
        }
        maxcount = max(maxcount,count);
        if (count == 56) cout<<"Line "<<line<<endl;
        line++;
    }
    cout<<maxcount;
    return 0;
}
