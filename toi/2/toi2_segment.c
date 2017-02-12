#include <stdio.h>
#define for1(a,b,c) for((a)=(b);(a)<(c);(a)++)
#define macro(a,b,c,d,e,f,g,h,i,j) if (digits[0][0]==a && digits[0][1]==b && digits[0][2]==c && digits[1][0]==d && digits[1][1]==e && digits[1][2]==f && digits[2][0]==g && digits[2][1]==h && digits[2][2]==i) return j;

typedef long long ll;

ll digitmul[11] = {1,1E1,1E2,1E3,1E4,1E5,1E6,1E7,1E8,1E9,1E10};

char digits[3][3];

ll getdigit() {
    macro(
          ' ','_',' ',
          '|',' ','|',
          '|','_','|',
          0
          )
    macro(
          ' ',' ',' ',
          ' ',' ','|',
          ' ',' ','|',
          1
          )
    macro(
          ' ','_',' ',
          ' ','_','|',
          '|','_',' ',
          2
          )
    macro(
          ' ','_',' ',
          ' ','_','|',
          ' ','_','|',
          3
          )
    macro(
          ' ',' ',' ',
          '|','_','|',
          ' ',' ','|',
          4
          )
    macro(
          ' ','_',' ',
          '|','_',' ',
          ' ','_','|',
          5
          )
    macro(
          ' ','_',' ',
          '|','_',' ',
          '|','_','|',
          6
          )
    macro(
          ' ','_',' ',
          ' ',' ','|',
          ' ',' ','|',
          7
          )
    macro(
          ' ','_',' ',
          '|','_','|',
          '|','_','|',
          8
          )
    macro(
          ' ','_',' ',
          '|','_','|',
          ' ','_','|',
          9
          )
}

int main() {
    int n1,n2; scanf("%d %d",&n1,&n2);
    int i = 0;
    int j = 0;
    int k = 0;
    char raw1[3][n1*4+1];
    char raw2[3][n2*4+1];
    ll num1 = 0;
    ll num2 = 0;
    gets(raw1[0]);
    for1(i,0,3) {
        for1(j,0,n1*4+1) raw1[i][j]=0;
        gets(raw1[i]);
    }
    for1(i,0,3) {
        for1(j,0,n2*4+1) raw2[i][j]=0;
        gets(raw2[i]);
    }
    /*for1(i,0,3) {
        printf("%s\n",raw1[i]);
    }
    for1(i,0,3) {
        printf("%s\n",raw2[i]);
    }*/
    int currstart = 0;
    for1(i,0,n1) {
        //extract digit raw1
        //lai to make digits and call getdigit
        for1(j,0,3) {
            for1(k,0,3) {
                if (raw1[j][currstart+k] == 0) raw1[j][currstart+k] = ' ';
                digits[j][k] = raw1[j][currstart+k];
            }
        }
        currstart += 4;
        ll d = getdigit();
        num1 += d*digitmul[n1-i-1];
    }

    //printf("%lld\n",num1);

    currstart = 0;
    for1(i,0,n2) {
        //extract digit raw2
        //lai to make digits and call getdigit
        for1(j,0,3) {
            for1(k,0,3) {
                if (raw2[j][currstart+k] == 0) raw2[j][currstart+k] = ' ';
                digits[j][k] = raw2[j][currstart+k];
            }
        }
        currstart += 4;
        ll d = getdigit();
        num2 += d*digitmul[n2-i-1];
    }
    //printf("%lld\n",num2);

    printf("%lld",num1+num2);
    return 0;
}
