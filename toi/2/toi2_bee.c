#include <stdio.h>
#define for1(a,b,c) for((a)=(b);(a)<(c);(a)++)

typedef long long ll;

int main() {
    int n;
    while (scanf("%d",&n),n!=-1) {
        int bee[2]; //work , sol
        bee[0] = 1;
        bee[1] = 0;
        while (n--) {
            int _bee0 = bee[0];
            int _bee1 = bee[1];
            bee[0] += _bee1;
            bee[0] += _bee0;
            bee[1] += _bee0;
            bee[0]++;

            bee[0] -= _bee0;
            bee[1] -= _bee1;
        }

        printf("%d %d\n",bee[0],bee[0]+bee[1]+1);
    }
    return 0;
}
