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
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t;
    map<string,int> p;
    p["A"] = 1;
    p["J"] = 10;
    p["Q"] = 10;
    p["K"] = 10;
    p["2"] = 2;
    p["3"] = 3;
    p["4"] = 4;
    p["5"] = 5;
    p["6"] = 6;
    p["7"] = 7;
    p["8"] = 8;
    p["9"] = 9;
    p["10"] = 10;
    while (t--) {
        int curr = 0;
        bool pr = false;
        for1(i,0,5) {
            string s; cin>>s;
            if (pr) continue;
            curr += p[s];
            if (curr>16) {
                if(curr<=21)
                cout<<curr<<endl; else cout<<"busted\n";
                pr = true;
            }
        }
        if (!pr) {
                    if(curr<=21)
                    cout<<curr<<endl; else cout<<"busted\n";
        }

    }
	return 0;
}
