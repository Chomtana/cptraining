#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;

using namespace std;

int main() {
    char dir[3];
    int _n = 0;
    scanf("%d%s",&_n,dir);
    double n  =_n;
    //printf("%f %s",n,dir);
    double x=0;
    double y = 0;
    double sqrt2 = sqrt(2);
    //cout<<n;
    while (_n!=0) {
        //n^2 = 2x^2
        //x = n/sqrt(2)
        if (dir[0]=='N' && dir[1]=='E') {
            double d = n/sqrt2;
            x+=d;
            y+=d;
        } else if (dir[0]=='N' && dir[1]=='W') {
            double d = n/sqrt2;
            x-=d;
            y+=d;
        } else if (dir[0]=='S' && dir[1]=='W') {
            double d = n/sqrt2;
            x-=d;
            y-=d;
        } else if (dir[0]=='S' && dir[1]=='E') {
            double d = n/sqrt2;
            x+=d;
            y-=d;
        } else if (dir[0]=='N') {
            y+=n;
        } else if (dir[0]=='E') {
            x+=n;
        } else if (dir[0]=='S') {
            y-=n;
        } else if (dir[0]=='W') {
            x-=n;
        }
        
        _n=0; dir[0]=0; dir[1]=0; dir[2]=0;
        scanf("%d%s",&_n,dir);
        n=_n;
    }
    printf("%.3f %.3f\n",x,y);
    printf("%.3f",sqrt(x*x+y*y));
    return 0;
}