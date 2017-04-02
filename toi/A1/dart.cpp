#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define macro(a,b) if (in(x,y,a)) { sum += b; }

bool in(int x,int y,int r){
    //x^2+y^2 <= r^2
    return x*x+y*y <= r*r;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int sum = 0;
    int t; cin>>t; while(t--) {
        int x,y; cin>>x>>y;
        macro(2,5)
        else macro(4,4)
        else macro(6,3)
        else macro(8,2)
        else macro(10,1)
    }
    cout<<sum;
	return 0;
}
