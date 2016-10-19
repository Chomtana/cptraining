#include <stdio.h>

#define true 1
#define false 0
#define max(a,b) ((a>b)?a:b)

int main() {
    int n; scanf("%d",&n);
    int i = 0;
    int data[n];
    for (i=0;i<n;i++) {
        scanf("%d",data+i);
    }

    int isempty = true;
    for (i=0;i<n;i++) {
        if (data[i]>0) {
            isempty=false;
        }
    }

    if (isempty) {
        printf("Empty sequence");
        return 0;
    }

    int sum = 0;
    int maxsum = 0;
    int s = 0,ss = 0,e = 0;
    for (i = 0;i<n;i++) {
        sum += data[i];
        if (sum > maxsum) {
            maxsum = sum;
            e=i;
            s = ss;
        }
        if(sum<0) {
            maxsum = max(maxsum,sum);
            sum=0;
            ss = i+1;
        }
    }

    //printf("%d %d",s,e);
    for (i=s;i<=e;i++) {
        printf("%d ",data[i]);
    }
    printf("\n%d",maxsum);


    return 0;
}
