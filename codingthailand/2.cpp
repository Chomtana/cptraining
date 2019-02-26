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

int main() {
    cout<<fixed;
    map<string,string> m;
    m["C"] = "D";
    m["Dm"] = "Em";
    m["Em"] = "F#m";
    m["F"] = "G";
    m["G"] = "A";
    m["Am"] = "Bm";
    int n = 1;
    for1(i,0,200) {
        string s; cin>>s;
        cout<<m[s];
        if (n%4==0) {
            cout<<endl;
        } else {
            cout<<' ';
        }
        n++;
    }
    return 0;
}