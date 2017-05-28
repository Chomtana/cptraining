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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    string a,b; cin>>a>>b;
    deque<char> res;
    int i = a.size()-1;
    int j = b.size()-1;
    bool add = false;
    while (i>=0 || j>=0) {
        int digiti,digitj;
        if (i<0) {
            digitj = b[j]-'0';
            digitj += add;
            add = false;
            if (digitj>9) {
                digitj=0;
                add = true;
            }
            res.push_front(digitj+'0');
            j--;
            continue;
        } else if (j<0) {
            digiti = a[i]-'0';
            digiti += add;
            add = false;
            if (digiti>9) {
                digiti=0;
                add = true;
            }
            res.push_front(digiti+'0');
            i--;
            continue;
        } else {
            digiti = a[i]-'0';
            digitj = b[j]-'0';
            int digitres = digiti+digitj+add;
            add = false;
            if (digitres>9) {
                digitres -= 10;
                add = true;
            }
            res.push_front(digitres+'0');
            i--;
            j--;
        }
    }
    if (add) res.push_front('1');
    cout<<string(all(res));
	return 0;
}
