#include <stdio.h>
#define for1(a,b,c) for((a) = (b);(a)<(c);(a)++)

/**
final digit
I
II
III
IV
V
VI
VII
VIII
IX
X
*/

int I=0,V=0,X=0,L=0,C=0;

int process(int n) { //convert x to roman by add number of IVXLC
    int i = 0;
    int lastdigit = n%10;
    if (lastdigit<4) {
        I+=lastdigit;
    } else if (lastdigit == 4) {
        I+=1; V+=1;
    } else if (lastdigit <= 8) {
        V+=1; I+=lastdigit-5;
    } else {
        X+=1; I+=10-lastdigit;
    }

    int ten = n/10%10;

    if (ten<4) {
        X+=ten;
    } else if (ten == 4) {
        X+=1; L+=1;
    } else if (ten <= 8) {
        L+=1; X+=ten-5;
    } else {
        C+=1; X+=10-ten;
    }

    int roi = n/100;

    C+=roi;
}

int main() {
    int n; scanf("%d",&n);
    int i = 0;
    for1(i,1,n+1) {
        process(i);
        //printf("%d\n",i);
    }
    //process(n);

    printf("%d %d %d %d %d",I,V,X,L,C);



    return 0;
}
