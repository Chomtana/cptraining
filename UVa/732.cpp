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

string s,t;
vector<bool> op;
int c = 0;
stack<char> st;
deque<char> res;

void process(int i) {
    if (i>=2*s.size()) {
        bool ok = true;
        for1(i,0,t.size()) {
            if (t[i]!=res[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for1(i,0,op.size()) printf("%c ",(op[i]?'i':'o'));
        }
        return;
    }

    if (op[i-1]) { //if last operation is insert
        if (c<s.size()) { //if c is ok
            st.push(s[c]);
            c++;
        } else {
            return;
        }
    } else {
        if (st.empty()) return;
        res.push_back(st.top());
        st.pop();
    }

    op.push_back(true);
    process(i+1);
    op.pop_back();
    c--;

    op.push_back(false);
    process(i+1);
    op.pop_back();
    st.push(res.back());
    res.pop_back();
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;

    while (cin>>s>>t) {
        op.reserve(2*s.size());
        process(0);
    }
	return 0;
}
