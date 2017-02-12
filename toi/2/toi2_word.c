#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define for1(a,b,c) for((a)=(b);(a)<(c);(a)++)

#define bool int
#define true 1
#define false 0

typedef long long ll;

char data[50][50];

//using namespace std;

int main() {
    int nr,nc; scanf(" %d %d ",&nr,&nc);
    int i,j,k;
    for1(i,0,50) {
        for1(j,0,50) {
            data[i][j] = 0;
        }
    }
    for1(i,1,nr+1) {
        for1(j,1,nc+1) {
            scanf(" %c ",&data[i][j]);
            data[i][j] = tolower(data[i][j]);
            //printf("%c",data[i][j]);
        }
    }

    int t; scanf(" %d ",&t);
    while (t--) {
        char s[20];
        for1(i,0,20) s[i]=0;
        scanf("%s",s);
        //printf("%s",s);
        for1(i,0,20) s[i] = tolower(s[i]);
        int slen = strlen(s);
        for1(i,1,nr+1) {
            for1(j,1,nc+1) {
                if (data[i][j]==s[0]) {
                    bool res1 = true;//for all equal
                    bool res2 = true;//for all equal
                    bool res3 = true;//for all equal
                    bool res4 = true;//for all equal
                    bool res5 = true;//for all equal
                    bool res6 = true;//for all equal
                    bool res7 = true;//for all equal
                    bool res8 = true;//for all equal
                    //find left , right
                    for1(k,1,slen) {
                        if (data[i][j+k]!=s[k]) {
                            res1 = false;
                            break;
                        }
                    }
                    for1(k,1,slen) {
                        if (data[i][j-k]!=s[k]) {
                            res2 = false;
                            break;
                        }
                    }
                    //find up , down
                    for1(k,1,slen) {
                        if (data[i+k][j]!=s[k]) {
                            res3 = false;
                            break;
                        }
                    }
                    for1(k,1,slen) {
                        if (data[i-k][j]!=s[k]) {
                            res4 = false;
                            break;
                        }
                    }

                    //find diag
                    for1(k,1,slen) {
                        if (data[i+k][j+k]!=s[k]) {
                            res5 = false;
                            break;
                        }
                    }
                    for1(k,1,slen) {
                        if (data[i+k][j-k]!=s[k]) {
                            res6 = false;
                            break;
                        }
                    }
                    for1(k,1,slen) {
                        if (data[i-k][j+k]!=s[k]) {
                            res7 = false;
                            break;
                        }
                    }
                    for1(k,1,slen) {
                        if (data[i-k][j-k]!=s[k]) {
                            res8 = false;
                            break;
                        }
                    }

                    if (res1 || res2 || res3 || res4 || res5 || res6 || res7 || res8) {
                        printf("%d %d\n",i-1,j-1);
                        goto nextcase;
                    }
                }
            }
        }

        nextcase:
            continue;
    }
    return 0;
}
