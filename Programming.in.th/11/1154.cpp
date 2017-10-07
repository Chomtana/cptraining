#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

#define hk 53

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n,m;
char data[15005];

bool check(int k) {
    if (k==0) return true;
    unordered_map<ll,int> c(1000000);
    ll h = 0;
    ll powmax = 1;
    for1(i,0,k) {
        h *= hk;
        h += data[i]-'a';
        if (i>0) powmax *= hk;
    }
    c[h]++;
    //cerr<<h<<endl;
    //cerr<<"bbb "<<n<<endl;
    for1(i,1,n-k+1) {
        //cerr<<"aaa "<<i<<endl;
        h -= (data[i-1]-'a')*powmax;
        h *= hk;
        h += data[i+k-1]-'a';
        c[h]++;
        //cerr<<h<<endl;
    }

    for(auto p:c) {
        if (p.second>=m) return true;
    }

    return false;
}


int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m; cin.ignore();
    gets(data);
    int l = 0;int r = n;
    while (l<=r) {
        int mid = (l+r)/2;
        if (check(mid)) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    //cerr<<check(0)<<endl;
    cout<<l-1;
	return 0;
}
