#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; cin>>nr>>nc;

    char data[nr+5][nc+5];

    for1(i,0,nr) {
        scanf("%s",data[i]);
    }

    int res = 0;

    for1(i,0,nr) {
        for1(j,1,nc) {
            if (data[i][j]=='W'&&data[i][j-1]=='E')res++;
        }
    }

    for1(j,0,nc) {
        for1(i,1,nr) {
            if (data[i-1][j]=='S'&&data[i][j]=='N')res++;
        }
    }

    cout<<res;
	return 0;
}
