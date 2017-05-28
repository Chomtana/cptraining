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

int k[1000005];
set<pii,greater<pii>> bid[1000005];
int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m,t; cin>>n>>m>>t;
    for1(i,0,n) scanf("%d",k+i);
    while (t--) {
        char c; scanf("%d",&c);
        if (c=='B') {
            int buyer,item,p; scanf("%d%d%d",&buyer,&item,&p);
            item--;
            bid[item].insert(mp(p,buyer));
            if (bid[item].size()>k[item]) {
                bid.erase(--bid.end());
            }
        } else {
            int buyer,item; scanf("%d%d",&buyer,&item);
            item--;
            //vector<set<pii,greater<pii>>::iterator> rem;
            auto it = bid[item].begin();
            while (it!=bid[item].end()) {
                if (it->second==buyer) {
                    it = bid[item].erase(it);
                } else {
                    it++;
                }
            }
        }
    }
	return 0;
}
