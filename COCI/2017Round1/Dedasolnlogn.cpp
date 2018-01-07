#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define vi vector<int>
#define vii vector< vector<int> >
#define PI 3.1415926535897932384626433832795
#define INF 9223372036854775807LL

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

/*
3 4
M 10 3
M 5 1
D 20 2
D 5 1
*/

int Segtree[524288],leftend[524288],n,segsiz;
bool isend[524288];

void build() {
    memset(Segtree,0x3f3f3f3f,sizeof(Segtree));
    memset(isend,false,sizeof(isend));
    segsiz = 1;
    isend[1] = true;
    while(segsiz < n) {
        segsiz*= 2;
        //cerr<<segsiz<<endl;
        isend[segsiz-1] = true;
    }
    isend[segsiz*2-1] = true;
    for(int i = segsiz; i < 2*segsiz; i++) {
        leftend[i] = i;
    }
    for(int i = segsiz-1; i>= 1; i--) {
        leftend[i] = leftend[2*i];
    }
}

void update(int ind, int val) {
    ind+= segsiz;
    Segtree[ind] = val;
    while(ind > 1) {
        ind/= 2;
        Segtree[ind] = min(val,Segtree[ind]);
    }
}

int query(int ind, int val) {
    ind+= segsiz;
    int from = ind; //first position (single element [start...start] position in segment tree
    while(!isend[ind] && Segtree[ind] > val) {
        if(ind%2 == 1) {
            ind++;
        } else {
            ind/= 2;
        }
    }
    if(Segtree[ind] > val) {
        return -1;
    }
    while(ind < segsiz) { //start binary search from first value that seem ok
        if(ind%2 == 1) {
            if(Segtree[ind*2] <= val) {
                ind *= 2;
            } else {
                ind = ind*2+1;
            }
        } else {
            if(from != segsiz) { //if ind!=0
                if(leftend[ind-1] >= from) { //left end mang you korn from
                    if(Segtree[ind-1] <= val) { //if ind-1 mang ok
                        ind--;
                        continue;
                    }
                }
            }
            if(Segtree[ind*2] <= val) {
                ind *= 2;
            } else {
                ind = ind*2+1;
            }
        }
    }
    return ind-segsiz+1;
}

int main() {
    int q;
    scanf("%d %d\n",&n,&q);
    build();
    for1(i,1,2*segsiz) {
        cerr<<isend[i]<<' ';
    }
    cerr<<endl;
    for1(i,1,2*segsiz) {
        cerr<<leftend[i]<<' ';
    }
    cerr<<endl;
    for(int i = 0; i < q; i++) {
        char ch;
        int a,b;
        if(i < q-1) {
            scanf("%c %d %d\n",&ch,&a,&b);
        } else {
            scanf("%c %d %d",&ch,&a,&b);
        }
        if(ch == 'M') {
            update(b-1,a);
        } else {
            printf("%d\n",query(b-1,a));
        }
    }
    return 0;
}
