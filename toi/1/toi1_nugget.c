#include <stdio.h>
#define true 1
#define false 0

int res[101]; //res[i] = i is nugget?
//res[6x+9y+20z] = true

int main() {
    //pre process
    int i = 0;
    for(i=0;i<101;i++) {
        res[i] = false;
    }

    int x=0,y=0,z=0;
    for(x = 0;x<=100;x+=6) {
        for(y = 0;y<=100;y+=9) {
            for(z=0;z<=100;z+=20) {
                res[x+y+z] = true;
            }
        }
    }

    res[0] = false;

    int n; scanf("%d",&n);

    int printed = false;
    for(i = 1;i<=n;i++) {
        if (res[i]) {printf("%d\n",i); printed = true;}
    }

    if (!printed) {
        printf("no");
    }

    return 0;
}
