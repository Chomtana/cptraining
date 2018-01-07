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

int n;
int m;
int data[105][105];
bool nf[105][105];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
        memset(nf,0,sizeof(nf));
        scanf("%d%d",&n,&m);
        int res = 0;
        for1(i,0,m) {
            int sr,sc,er,ec; scanf("%d%d%d%d",&sr,&sc,&er,&ec);
            for1(r,sr,er+1) for1(c,sc,ec+1) {
                nf[r][c] = true;
            }
        }

        for1(sr,1,n+1) {
            bool found[105]; //found ... in that col
            for1(i,0,105) found[i] = false;
            for1(er,sr,n+1) {
                int sc = 1;
                for1(ec,1,n+1) {
                    if (found[ec-1] || nf[er][ec-1]) {
                        sc = ec;
                    }
                    if (!found[ec] && !nf[er][ec]) {
                        res = max(res,(er-sr+1)*(ec-sc+1));
                        //cerr<<sr<<' '<<sc<<' '<<er<<' '<<ec<<' '<<((er-sr+1)*(ec-sc+1))<<endl;
                    } else {
                        found[ec] = true;
                    }
                }
            }
        }

        printf("%d\n",res);
    }
	return 0;
}
