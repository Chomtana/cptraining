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
typedef pair<double,double> pdd;
typedef vector<int> vi;

int n; double w;
pdd data[100005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>w>>n;
    for1(i,0,n) {
        scanf("%lf",&data[i].first);
    }
    for1(i,0,n) {
        scanf("%lf",&data[i].second);
    }
    sort(data,data+n,[](pdd a,pdd b) {
        return a.first/a.second > b.first/b.second;
    });

    double cw = 0;
    double cv = 0;

    for1(i,0,n) {
        cw += data[i].second;
        if (cw<=w) {
            cv += data[i].first;
        } else {
            cw -= data[i].second;
            double r = (w-cw)/data[i].second;
            cv += r*data[i].first;
            break;
        }
    }

    cout<<fixed<<setprecision(4)<<cv;
	return 0;
}
