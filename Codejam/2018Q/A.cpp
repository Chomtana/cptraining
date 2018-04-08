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

void calsize(int &sz,string &s) {
    while (sz-1>=0) {
        if (s[sz-1]=='C') sz--; else break;
    }
}

int calfi(int sz,string &s) {
    int i = sz-1;
    for(i = sz-1;i>=0;i--) {
        if (s[i]=='C') return i;
    }
    return -1;
}

ll calpow(string &s) {
    ll res = 0;
    ll curr = 1;
    for1(i,0,s.size()) {
        if (s[i]=='S') res+=curr;
        else curr*=2;
    }
    return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t;
    for1(_,1,t+1) {
        cout<<"Case #"<<_<<": ";
        ll d; string s; cin>>d>>s;
        int sz = s.size();

        int res = 0;
        bool possible = true;

        while(calpow(s)>d) {
            calsize(sz,s);
            int fi = calfi(sz,s);
            if (fi==-1) {
                possible = false;
                cout<<"IMPOSSIBLE\n";
                break;
            }
            swap(s[fi],s[fi+1]);
            res++;
        }

        if (possible) cout<<res<<endl;
    }
	return 0;
}
