#include <stdio.h>
#define for1(a,b,c) for((a)=(b);(a)<(c);(a)++)

typedef long long ll;

int max(int a,int b) {
    if (a>b) return a; else return b;
}

int main() {
    int n; scanf("%d",&n);
    int i;
    int j;
    int data[256];
    for1(i,0,256) data[i]=0;
    for1(i,0,n) {
        int l,h,r; scanf("%d %d %d",&l,&h,&r);
        for1(j,l,r) {
            data[j] = max(data[j],h);
        }
    }
    for1(i,1,256) {
        if (data[i]!=data[i-1]) {
            printf("%d %d ",i,data[i]);
        }
    }
    return 0;
}
