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
    int data[256];
    data['0'] = 1;
    data['1'] = 0;
    data['2'] = 0;
    data['3'] = 0;
    data['4'] = 1;
    data['5'] = 0;
    data['6'] = 1;
    data['7'] = 0;
    data['8'] = 2;
    data['9'] = 1;
    int sum = 0;
    for1(i,0,s.size()) {
        sum += data[s[i]];
    }
    cout<<sum;
	return 0;
}
