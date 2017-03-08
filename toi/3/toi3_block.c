#include <stdio.h>
#define for1(a,b,c) for((a)=(b);(a)<(c);(a)++)
#define bool int
#define true 1
#define false 0

typedef long long ll;

int nr,nc;
char data[10][10];

void makedown() {
    int i,j,r,c;
    for1(r,1,nr+1) {
        for1(c,1,nc+1) {
            if (data[r][c] != '#' && data[r][c]!='-') {
                for1(i,r+1,nr+1) {
                    if (data[i][c]=='-') {
                        data[i][c] = data[i-1][c];
                        data[i-1][c] = '-';
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

int main() {
     scanf("%d %d ",&nr,&nc);

    int i,j,k;
    for1(i,0,nr+2) {
        for1(j,0,nc+2) {
            data[i][j] = '#';
        }
    }
    for1(i,1,nr+1) {
        for1(j,1,nc+1) {
            scanf("%c ",&data[i][j]);
        }
    }

    int score = 0;
    int t; scanf("%d",&t); while(t--) {
        int r,c; char op; scanf("%d %d %c",&r,&c,&op);
        //printf("%d %d %c\n",r,c,op);
        r++; c++;
        if (data[r][c]=='#' || data[r][c]=='-') {
            score -= 5;
            continue;
        }
        switch (op) {
        case 'L': {
            if (data[r][c-1]!='-') {
                score -= 5;
                continue;
            }
            data[r][c-1] = data[r][c];
            data[r][c] = '-';
            for1(i,r+1,nr+1) {
                if (data[i][c-1]=='-') {
                    data[i][c-1] = data[i-1][c-1];
                    data[i-1][c-1] = '-';
                } else {
                    break;
                }
            }
            i--;
            bool del = false;
            if (data[i][c] == data[i][c-1]) {
                del = true;
                score += 5;
                data[i][c] = '-';
            }
            if (data[i][c-2] == data[i][c-1]) {
                del = true;
                score += 5;
                data[i][c-2] = '-';
            }
            if (data[i-1][c-1] == data[i][c-1]) {
                del = true;
                score += 5;
                data[i-1][c-1] = '-';
            }
            if (data[i+1][c-1] == data[i][c-1]) {
                del = true;
                score += 5;
                data[i+1][c-1] = '-';
            }

            if (del) {
                data[i][c-1] = '-';
                score += 5;
            }
        }
            break;
        case 'R': {
            if (data[r][c+1]!='-') {
                score -= 5;
                continue;
            }
            data[r][c+1] = data[r][c];
            data[r][c] = '-';
            for1(i,r+1,nr+1) {
                if (data[i][c+1]=='-') {
                    data[i][c+1] = data[i-1][c+1];
                    data[i-1][c+1] = '-';
                } else {
                    break;
                }
            }
            i--;
            bool del = false;
            if (data[i][c] == data[i][c+1]) {
                del = true;
                score += 5;
                data[i][c] = '-';
            }
            if (data[i][c+2] == data[i][c+1]) {
                del = true;
                score += 5;
                data[i][c+2] = '-';
            }
            if (data[i-1][c+1] == data[i][c+1]) {
                del = true;
                score += 5;
                data[i-1][c+1] = '-';
            }
            if (data[i+1][c+1] == data[i][c+1]) {
                del = true;
                score += 5;
                data[i+1][c+1] = '-';
            }

            if (del) {
                data[i][c+1] = '-';
                score += 5;
            }
        }
            break;
        }
        makedown();
    }

    printf("%d\n",score);
    for1(i,1,nr+1) {
        for1(j,1,nc+1) {
            printf("%c ",data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
