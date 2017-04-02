#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int hp; scanf("%d",&hp);
    int hpeven = hp;
    int hpodd = hp;
    int evenc = 0;
    int oddc = 0;
    for1(i,0,2*hp) {
        int n; scanf("%d",&n);
        if (n%2==0) {
            oddc = 0;
            evenc++;
            if (evenc>=3) {
                hpodd -= 3;
            } else {
                hpodd--;
            }
        } else {
            evenc = 0;
            oddc++;
            if (oddc>=3) {
                hpeven -= 3;
            } else {
                hpeven--;
            }
        }
        if (hpeven<=0) {
            printf("%d\n%d",1,n);
            return 0;
        } else if (hpodd<=0) {
            printf("%d\n%d",0,n);
            return 0;
        }
    }
	return 0;
}
