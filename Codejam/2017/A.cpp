/*
Use do only one and then expand to k

+-+-+-+ 3
++-++-+
+++---+
+++++++

+-+-+-+-+ 3
++-++-+-+
+++---+-+
+++++++-+
+++++++XX
*/

#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool allplus(string &s) {
    for1(i,0,s.size()) {
        if(s[i]!='+') {
            return false;
        }
    }
    return true;
}

bool flip(string &s,int st,int en) {
    for1(i,st,en) {
        if (s[i]=='-') {
            s[i]='+';
        } else s[i]='-';
    }
}

int main2() {
    string s; int k; cin>>s>>k;
    int res = 0;
    while (!allplus(s)) {
        bool ok = false;
        for1(i,0,s.size()-k+1) {
            if (s[i]=='-') {
                flip(s,i,i+k);
                res++;
                ok = true;
                break;
            }
        }
        if(!ok) return -1;
    }
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        cout<<"Case #"<<_<<": ";
        int res = main2();
        if (res==-1) cout<<"IMPOSSIBLE"; else cout<<res;
        cout<<endl;
    }
	return 0;
}
