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

bool isinc(string &s) {
    for1(i,1,s.size()) {
        if (s[i]<s[i-1]) return false;
    }
    return true;
}

string main2() {
    string s; cin>>s;
    while (!isinc(s)) {
        int decpos = -1;
        for2(i,s.size()-1,0) {
            if (s[i]<'9') {
                s[i] = '9';
                decpos = i-1;
                break;
            }
        }
        s[decpos]--;
        while (s[decpos]<'0') {
            s[decpos] = '9';
            decpos--;
            s[decpos]--;
        }
    }
    if (s[0]=='0') {
        return s.substr(1);
    }
    return s;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        cout<<"Case #"<<_<<": "<<main2()<<endl;
    }
	return 0;
}
