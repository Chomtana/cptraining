#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int w,h;
    scanf("%d %d",&w,&h);
    long int mat1[w][h];
    long int mat2[w][h];
    for (int i = 0;i<h;i++) {
        for (int i2 = 0;i2<w;i2++) {
            scanf("%ld",&mat1[i2][i]);
        }
    }
    for (int i = 0;i<h;i++) {
        for (int i2 = 0;i2<w;i2++) {
            scanf("%ld",&mat2[i2][i]);
        }
    }
    for (int i = 0;i<w;i++) {
        for (int i2 = 0;i2<h;i2++) {
            printf("%d ", mat1[i2][i]+mat2[i2][i]);
        }
        printf("\n");
    }
    /*int n,m,i,j;

    scanf("%d %d",&n,&m);

    int matrix1 [n][m];
    int matrix2 [n][m];
    int matrixS [n][m];

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
                scanf("%d",&matrix1[i][j]);
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
                scanf("%d",&matrix2[i][j]);
        }
    //	printf("\n");
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
                matrixS[i][j]= matrix1 [i][j] + matrix2 [i][j];
                printf("%d ",matrixS[i][j]);
        }
    printf("\n");
    }*/
    return 0;
}

