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
    int n,m; cin>>n>>m;
    //cin.ignore();
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for1(_,0,n+m) {
        char _c[2]; scanf("%s",_c);
        char c = _c[0];
        if (c=='T') {
            int a,b; scanf("%d%d",&a,&b);
            pq.push(mp(a,b));
        } else {
            if (pq.empty()) printf("0\n"); else {
                int val = pq.top().second;
                pq.pop();
                printf("%d\n",val);
            }
        }
        //cin.ignore();
    }
	return 0;
}
