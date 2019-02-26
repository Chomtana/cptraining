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

queue<char> q;
stack<char> st;

int priority(char c) {
    if (c=='(') return -1;
    if (c=='+' || c=='-') return 0;
    if (c=='*' || c=='/') return 1;
}

bool isop(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/';
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    string s; cin>>s;
    for (char c:s) {
        if (isdigit(c)) {
            q.push(c);
        } else if (c=='(') {
            st.push(c);
        } else if (c==')') {
            while (!st.empty() && st.top()!='(') {
                q.push(st.top());
                st.pop();
            }
            st.pop();
        } else if (isop(c)) {
            while (!st.empty() && priority(st.top())>priority(c)) {
                q.push(st.top());
                st.pop();
            }
            st.push(c);
        }

    }

    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    while (!q.empty()) {
        printf("%c ",q.front());
        q.pop();
    }
	return 0;
}
