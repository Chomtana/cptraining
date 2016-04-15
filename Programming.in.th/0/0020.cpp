#include <stdio.h>
#include <iostream>

using namespace std;

int max(int a,int b) {
    if (a >b ) {
        return a;
    } else {
        return b;
    }
    return 0;        
}

int main() {
    int score[6][5];
    int sum[6];
    int result = 0;
    scanf("%d %d %d %d",&score[0][0],&score[0][1],&score[0][2],&score[0][3]);
    scanf("%d %d %d %d",&score[1][0],&score[1][1],&score[1][2],&score[1][3]);
    scanf("%d %d %d %d",&score[2][0],&score[2][1],&score[2][2],&score[2][3]);
    scanf("%d %d %d %d",&score[3][0],&score[3][1],&score[3][2],&score[3][3]);
    scanf("%d %d %d %d",&score[4][0],&score[4][1],&score[4][2],&score[4][3]);
    sum[0] = score[0][0]+score[0][1]+score[0][2]+score[0][3];
    sum[1] = score[1][0]+score[1][1]+score[1][2]+score[1][3];
    sum[2] = score[2][0]+score[2][1]+score[2][2]+score[2][3];
    sum[3] = score[3][0]+score[3][1]+score[3][2]+score[3][3];
    sum[4] = score[4][0]+score[4][1]+score[4][2]+score[4][3];
    sum[5] = max(max(max(max(sum[0],sum[1]),sum[2]),sum[3]),sum[4]);
    if (sum[5] == sum[0]) {
        result = 1;
    } else if (sum[5] == sum[1]) {
        result = 2;
    } else if (sum[5] == sum[2]) {
        result = 3;
    } else if (sum[5] == sum[3]) {
        result = 4;
    } else if (sum[5] == sum[4]) {
        result = 5;
    }
    cout << result << " " << sum[5];
    return 0;
}

