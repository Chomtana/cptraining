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

bool isp[200001];
vector<int> p;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;

	p.reserve(20000);

    int n; cin>>n;
    for1(i,0,200001) isp[i] = true;
    isp[1] = false;
    isp[0] = false;
    for(ll i=2;i<=200000;i++) {
        if (isp[i]) {
            for(ll j = i*i;j<=200000;j+=i) {
                isp[j] = false;
            }
        }
    }
    for1(i,0,200001) if (isp[i]) p.push_back(i);

    int mindif = 1E9;
    for1(i,0,p.size()) {
        int dif = abs(p[i]-n);
        mindif = min(mindif,dif);
    }

    cout<<mindif;

	return 0;
}
