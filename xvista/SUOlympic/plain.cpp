#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(a,b,c) for(int (a)=(b);((b)<(c)?(a)<(c):(a)>=(c));a+=((b)<(c)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int ep[1000005];
int data[1000005];

int main() {
    int n,m; cin>>n>>m;
    for1(i,0,n) {
        int s,e; scanf("%d%d",&s,&e);
        s--; e--;
        ep[s] += 1;
        ep[e+1] -= 1;
    }
    
    data[0] = ep[0];
    
    for1(i,1,1000005) {
        data[i] = data[i-1]+ep[i];
    }
    
    
    if (data[0]==m) printf("%d ",1);
    for1(i,1,1000005) {
        if (data[i]!=data[i-1]) {
            if (data[i]==m) printf("%d ",i+1); else if (data[i-1]==m) printf("%d\n",i);
        }    
    }

    return 0;
}
