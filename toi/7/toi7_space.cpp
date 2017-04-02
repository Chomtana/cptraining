#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int d;

void printbs(bitset<32> &bs) {
    for(int i = d-1;i>=0;i--) {
        printf("%d",(int)bs[i]);
    }
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    scanf("%d",&d);
    for(int i = 0;i<(1<<d);i++) {
        //cout<<i<<endl;
        //int n = i;
        bitset<32> n(i);
        for1(j,0,d) {
            bitset<32> nn(i);
            nn.flip(j);
            if ((i^(1<<j))>i) {
                printbs(n);
                printf(" ");
                printbs(nn);
                printf("\n");
            }
        }

    }
	return 0;
}
