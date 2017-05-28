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
	string data[] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
	map<string,int> mid;
mid["JAN"]                  = 0;
mid["FEB"]                   = 1;
mid["MAR"]                 = 2;
mid["APR"]                  = 3;
mid["MAY"]                 = 4;
mid["JUN"]          = 5;
mid["JUL"]          = 6;
mid["AUG"]          = 7;
mid["SEP"]          = 8;
mid["OCT"]          = 9;
mid["NOV"]          = 10;
mid["DEC"]          = 11;
    string month; cin>>month;
    int n; cin>>n;
    int id = (mid[month]+n)%12;
    if (id<0) {
        id += 12;
    }
    cout<<data[id];
	return 0;
}
