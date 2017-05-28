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
	//ios::sync_with_stdio(false);
	cout<<fixed;
    string s; cin>>s;
    int t; cin>>t;
    while (t--) {
        string q; cin>>q;
        int j = 0;
        bool ok = true;
        int firstj = 0;
        for1(i,0,q.size()) {
            while (j<s.size()&&s[j]!=q[i]){
                j++;
            }
            if (i==0) firstj = j;
            if (j>=s.size()) {
                ok = false;
                break;
            }
            j++;
        }
        if (ok) {
            cout<<"Matched "<<firstj<<' '<<j-1<<endl;
        } else {
            cout<<"Not matched\n";
        }
    }
	return 0;
}
