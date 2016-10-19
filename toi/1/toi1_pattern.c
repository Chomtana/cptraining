#include <stdio.h>

int main() {
    int n=10000; //scanf("%d",&n);
    char data[n][70];
    int i = 0;
    int j = 0;
    for(i = 0;i<n;i++) {
        for(j=0;j<70;j++) {
            data[i][j] = 'o';
        }
    }
    int printn = 0;
    for(i = 0;i<n;i++) {
        int r=i+1,s=1,l=30; //scanf("%d%d%d",&r,&s,&l);
        r--;
        s--;
        int e = s+l-1;
        if (r>printn) {
            printn = r;
        }
        for (;s<=e&&s<70;s++) {
            data[r][s] = 'x';
        }
    }

    for(i = 0;i<=printn;i++) {
        for(j=0;j<70;j++) {
            printf("%c",data[i][j]);
        }
        printf("\n");
    }
    return 0;
}
