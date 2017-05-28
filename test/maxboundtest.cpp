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

#define n 1000000

ll data[n];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	default_random_engine eng(time(0));
	srand(time(0));

	/*vector<ll> data;
	data.reserve(n);*/

    for1(i,0,n) {
        //data.push_back(true);
        data[i] = rand()%1000;
    }

    sort(data,data+n);

    ll sum = 0;

    for1(i,0,60) for1(j,1,n) {
        sum += data[j]/(data[j-1]==0?1:data[j-1]);
    }

    /*ll sum = 0;

    for1(i,0,n) {
        sum += data[i];
    }

    cout<<sum<<endl;*/
	return 0;
}
