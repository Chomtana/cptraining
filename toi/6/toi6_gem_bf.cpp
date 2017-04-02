#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n,m;
vector<pii> needselect;
vector<pii> banmaster;



int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t = 5;
    while (t--) {
        scanf("%d %d",&n,&m);

        needselect.resize(n);
        banmaster.resize(m);

        for1(i,0,n) scanf("%d %d",&needselect.first,&needselect.second);
        for1(i,0,m) scanf("%d %d",&banmaster.first,&banmaster.second);

        needselect.clear();
        banmaster.clear();
    }
	return 0;
}
