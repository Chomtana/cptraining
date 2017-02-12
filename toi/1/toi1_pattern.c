#include <stdio.h>

#define for1(a,b,c) for((a)=(b);(a)<(c);(a)++)

int main() {
    int n; scanf("%d",&n);
    int i = 0;
    int j = 0;
    char data[n][71];
    for1(i,0,n) {
        for1(j,0,70) {
            data[i][j] = 'o';
        }
        data[i][70] = 0;
    }

    int print = 0;
    for1(i,0,n) {
        int r,s,len; scanf("%d %d %d",&r,&s,&len);
        if (r>print) print=r;
        r--;
        s--;
        for1(j,0,len) {
            if (s+j>=70) break;
            data[r][s+j] = 'x';
        }
    }
    for1(i,0,print) {
        printf("%s\n",data[i]);
    }
    return 0;
}
