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
    int sum3 = 0;
    int sum11 = 0;
    for1(i,0,s.size()) {
        sum3 += s[i]-'0';
        sum11 += (s[s.size()-i-1]-'0')*(i%2==0?1:10);

    }
    cout<<sum3%3<<' '<<sum11%11;
	return 0;
}
