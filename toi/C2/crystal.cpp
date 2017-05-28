#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [] args
#define m 10001

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int C[1001][1001];

void gencnr() {
    C[0][0] = 1;
    //C[1][0] = C[0][-1] + C[0][0]
    for1(i,1,1001) {
        C[i][0] = C[i-1][0];
        C[i][i] = C[i-1][i-1];
        for1(j,1,i) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            //C[i][j] %= m;
        }
    }
}

int calres(int base) {
    //case fill next 1,...,base-1
    int res = 0;
    for1(fn,1,base) {
        res += C[base-1][fn];
        int next = calres(fn);
        res += next * (base-fn);
    }

    cerr<<base<<' '<<res<<endl;
    return res;

    //return res%m;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    gencnr();

    for1(i,0,10) {
        for1(j,0,i+1) {
            cerr<<C[i][j]<<' ';
        }
        cerr<<endl;
    }

    cout<<calres(n)+1;
	return 0;
}
