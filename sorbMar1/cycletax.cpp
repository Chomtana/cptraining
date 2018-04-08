#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,m;
int minw = 1e9;
int minws = -1;
int minwe = -1;

int main() {
    cin>>n>>m;
    for1(i,0,m) {
        int s,e,w; scanf("%d %d %d",&s,&e,&w);
        if (w<minw) {
            minw = w;
            minws = s;
            minwe = e;
        }
    }
    if (m==n*(n-1)/2) {
        printf("%d %d\n",minw,1);
        for1(i,1,n+1) {
            for1(j,i+1,n+1) {
                printf("%d %d ",i,j);
                if ((i==minws && j==minwe) || (i==minwe && j==minws)) {
                    printf("1\n");
                } else {
                    printf("0\n");
                }
            }
        }
    }
    return 0;
}

/*
4 6
1 2 19
1 3 11
1 4 8
2 3 5
2 4 81
3 4 8
*/