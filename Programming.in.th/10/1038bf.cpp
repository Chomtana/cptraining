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
double data[25][25];
int curr[25];
bool ban[25];
double res = 0;

void f(int c) {
    if (c>=n) {
        double subres = 1;
        for1(i,0,n) {
            subres *= data[i][curr[i]];
        }
        res = max(res,subres);
        return;
    }

    for1(i,0,n) {
        if (!ban[i]) {
            curr[c] = i;
            ban[i] = true;
            f(c+1);
            ban[i] = false;
            curr[c] = -1;
        }
    }

    curr[c] = -1;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    for1(i,0,n) {
        for1(j,0,n) {
            cin>>data[i][j];
            data[i][j] /= 100;
        }
    }
    memset(curr,-1,sizeof(curr));
    f(0);
    printf("%.6f",res*100);
	return 0;
}
