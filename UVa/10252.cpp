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
    string a,b;
    while (getline(cin,a),getline(cin,b)) {
        vector<int> ca(256);
        vector<int> cb(256);
        vector<int> c(256);
        for(char &c:a) ca[c]++;
        for(char &c:b) cb[c]++;
        for1(i,'a','z'+1) c[i] = min(ca[i],cb[i]);
        string res = "";
        for1(i,'a','z'+1) {
            for1(j,0,c[i]) {
                res += i;
            }
        }
        cout<<res<<endl;
    }
	return 0;
}
