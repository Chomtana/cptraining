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

vector<pii> data;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    data.resize(n);
    for1(i,0,n) scanf("%d",&data[i].first);
    for1(i,0,n) scanf("%d",&data[i].second);
    sort(all(data),[](const pii& a,const pii &b) {
        if (a.second<b.second) return true;
        if (a.second>b.second) return false;

        return a.first<b.first;
    });
    int curr = 0;
    int res = 0;
    for1(i,0,n) {
        if (data[i].first>=curr) {
            res++;
            curr = data[i].second;
        }
    }
    cout<<res;
	return 0;
}
