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

bool isopen(char c) { return c=='(' or c=='[' or c=='{';}
bool isclose(char op,char cl) {
    if (op=='(') {
        return cl==')';
    } else if (op=='[') {
        return cl==']';
    } else if (op=='{') {
        return cl=='}';
    }
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while (t--) {
        string s; cin>>s;
        stack<char> st;
        bool ok = true;
        for(char &c:s) {
            if (isopen(c)) {
                st.push(c);
            } else {
                if (st.empty()) {
                    ok = false;
                    break;
                }
                if (!isclose(st.top(),c)) {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty()) ok=false;
        if (ok) cout<<"yes"<<endl; else cout<<"no"<<endl;
    }
	return 0;
}
