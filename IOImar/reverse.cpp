#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool check(int ans) {
    
}

int a[15];

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    int t,n; cin>>t>>n; //n=10
    
    printf("FILE reverse %d\n",t);

    int x = 0; //x=1
    while (8*x+8<n) x++;
    
    if (x==0) { //bug
        for(int i = 1;i<=9;i++) {
            a[i] = i-1;
        }
        for(int i = 1;i<=9;i++) printf("%d ",a[i]);
        printf("\n");
        for(int i = n;i>=0;i--) printf("P %d\n",i);
        return 0;
    }
    
    for(int i = 1;i<=9;i++) { //0 1 2 3 4 5 6 7 8
        a[i] = (i-1)*(x);
    }
    for(int i = 9;i>=1;i--) { //0 1 2 3 4 5 6 8 10
        a[i] = max(a[i],n-((9-i)*(x+1)));
    }
    for(int i = 1;i<=9;i++) printf("%d ",a[i]);
    printf("\n");
    
    
    
    int start = 9;
    while (a[start]>n) start--;
    
    //do first
    while(a[start]<n) {
        printf("S %d %d\n",start,start);
        a[start]++;
    }
    printf("P %d\n",start);
    //cerr<<"err "<<a[start]<<endl;
    
    int curr = n-1; //first block (at right) already done
    
    int p = start-1;
    
    while(p>=1) {
        if (a[p]==curr) {
            printf("P %d\n",p);
            curr--;
            //cerr<<"err "<<a[p]<<endl;
            p--;
            continue;
        }
        a[p+1] = a[p]+1;
        printf("S %d %d\n",p,p+1);
        while (a[p+1]<curr) {
            a[p+1] = a[p+1]+1;
            printf("S %d %d\n",p+1,p+1);
        }
        printf("P %d\n",p+1);
        curr--;
        //cerr<<"err "<<a[p+1]<<endl;
    }
    
    return 0;
}

/*
9

9 8 7 6 5 4 3 2 0
...
9 8 7 6 5 4 3 1 0

-------------------------------------------------

10

10 9 8 7 6 5 4 2 0
...
10 9 8 7 6 5 3 2 0
...
10 9 8 7 6 5 3 1 0
...

--------------------------------------------------

11

11 10 9 8 7 6 4 2 0
...
11 10 9 8 7 5 4 2 0
...
11 10 9 8 7 5 3 2 0
...
11 10 9 8 7 5 3 1 0

--------------------------------------------------

Pattern found !!!

dod tua kun mod
bound mang
x
0 (x+1) 2(x+1) 3(x+1) ... 8(+1)

x = 2
0 3 6 9 12 15 18 21 24
n = 24 = 8(x+1)

x = 2 18 17 16

*/