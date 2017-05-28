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

int data[105][105];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc,t; cin>>nr>>nc>>t;
    for1(i,0,nr) for1(j,0,nc) scanf("%d",&data[i][j]);
    while (t--) {
        int sr,sc,er,ec; scanf("%d%d%d%d",&sr,&sc,&er,&ec);
        sr--;sc--;er--;ec--;
        if (sr>er || sc>ec) {
            printf("INVALID\n");
            continue;
        }
        bool ob = true;
        int currmax = -1E9;
        //cerr<<sr<<' '<<sc<<' '<<er<<' '<<ec<<endl;
        for1(i,sr,er+1) {
            for1(j,sc,ec+1) {
                if (i>=0 && j>=0 && i<nr && j<nc) {
                    ob = false;
                    currmax = max(currmax,data[i][j]);
                }
            }
        }

        if (!ob) {
            printf("%d\n",currmax);
        } else {
            printf("OUTSIDE\n");
        }
    }
	return 0;
}
