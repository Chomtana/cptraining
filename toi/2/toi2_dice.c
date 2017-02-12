#include <stdio.h>
#include <string.h>
#define for1(a,b,c) for((a)=(b);(a)<(c);(a)++)

#define macro(a,b,c,d,e,f) data[0] = a; data[1] = b; data[2] = c; data[3] = d; data[4] = e; data[5] = f;

typedef long long ll;

int main() {
    int t; scanf("%d",&t);
    int i;
    while (t--) {
        char s[2000]; scanf("%s",s);
        int n = strlen(s);
        int data[6] = {1,2,3,5,4,6};
        for1(i,0,n) {
            int top = data[0];
            int front = data[1];
            int left = data[2];
            int back = data[3];
            int right = data[4];
            int bottom = data[5];
            switch (s[i]) {
            case 'F':
                macro(back,top,left,bottom,right,front);
                break;
            case 'B':
                macro(front,bottom,left,top,right,back);
                break;
            case 'L':
                macro(right,front,top,back,bottom,left);
                break;
            case 'R':
                macro(left,front,bottom,back,top,right);
                break;
            case 'C':
                macro(top,right,front,left,back,bottom);
                break;
            case 'D':
                macro(top,left,back,right,front,bottom);
                break;
            }
        }
        printf("%d ",data[1]);
    }
    return 0;
}
