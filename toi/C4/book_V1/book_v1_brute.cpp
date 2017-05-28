/*
Critical case:
This problem case insensitive
But c++ function case sensitive (use ascii table for compare multi case)
*/

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
    int n; cin>>n;
    vector<string> data;
    for1(i,0,n) {
        string s; cin>>s;
        transform(all(s),s.begin(),::tolower);
        data.push_back(s);
        sort(all(data));
        printf("%d\n",lower_bound(all(data),s)-data.begin()+1);
    }
	return 0;
}
