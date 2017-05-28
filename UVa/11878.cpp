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
    string s;
    int res = 0;
    while (cin>>s) {
        int first = 0;
        int second = 0;
        int ans = 0;
        int op = 0;
        bool anspart = false;
        for1(i,0,s.size()) {
            if (s[i]=='+') {
                op=1;
            } else if (s[i]=='-') {
                op=2;
            } else if (s[i]=='=') {
                anspart = true;
            } else {
                if (!anspart) {
                    if (op==0) {
                        first *= 10;
                        first += s[i]-'0';
                    } else {
                        second *= 10;
                        second += s[i]-'0';
                    }
                } else {
                    if (s[i]=='?') {
                        ans = -1;
                    } else {
                        ans *= 10;
                        ans += s[i]-'0';
                    }
                }
            }
        }

        if (ans==-1) continue;
        if (op==1) {
            res += (first+second==ans);
        } else {
            res += (first-second==ans);
        }
    }
    cout<<res<<endl;
	return 0;
}
