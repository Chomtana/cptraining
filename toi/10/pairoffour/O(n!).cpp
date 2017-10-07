#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

char backup[1005];
char raw[1005][3];
char data[1005];

int subres = 0;

void rem(int p) {

}


int main() {
	//ios::sync_with_stdio(false);
    int n; cin>>n;
    for1(i,0,n) {
        scanf("%s",raw[i]);
        backup[i] = raw[i][0];
    }

    int bruter[n];
    for1(i,0,n) bruter[i] = i;
    do {
        for1(i,0,n) data[i] = backup[i];

    } while (next_permutation(bruter,bruter+n));
	return 0;
}
