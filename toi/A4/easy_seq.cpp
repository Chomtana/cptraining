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
    int n; cin>>n;
    ll data[n];
    for1(i,0,n) {
        scanf("%lld",data+i);
        if (data[i]<=0) {
            cout<<"Not Easy"; return 0;
        }
    }

    if (n<=2) {
        cout<<"Easy"; return 0;
    }

    ll dif = abs(data[1]-data[0]);

    for1(i,2,n) {
        if (abs(data[i]-data[i-1])!=dif) {
            cout<<"Not Easy"; return 0;
        }
    }
    cout<<"Easy";
	return 0;
}
