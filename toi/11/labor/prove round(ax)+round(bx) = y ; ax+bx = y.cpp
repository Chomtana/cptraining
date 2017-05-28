//prove fail for general case (work with very high prob in low a,b,c,d length)

#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args
#define random(s,e) uniform_int_distribution<long long>(s,e)(eng)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	while (true) {
        default_random_engine eng(time(0));
        long double a[10000]; //a = random(1,1000000); b = random(1,1000000);
        for1(i,0,100) {
            a[i] = random(1,1000);
        }
        long double y = random(1,1000);
        long double suma = 0;
        for1(i,0,100) suma+=a[i];
        long double x = y/suma;
        long double ry = 0;
        for1(i,0,100) ry += round(a[i]*x);

        cout<<(ry==y)<<' '<<y<<' '<<ry<<endl;
	}

	return 0;
}
