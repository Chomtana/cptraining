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

int ages[2000005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n;
    while (scanf("%d", &n), n) {
        int c[105];
        fill(c,c+105,0);
        for1(i,0,n) {
            int in; scanf("%d",&in);
            c[in]++;
        }

        int curr = 0;
        for1(i,0,105) {

            while (c[i]--) {
                ages[curr] = i;
                curr++;
            }
        }
		for (int i = 0; i < n; i++) {
			printf("%d", ages[i]);
			if(i!=n-1)printf(" ");
		}
		printf("\n");
    }
	return 0;
}
