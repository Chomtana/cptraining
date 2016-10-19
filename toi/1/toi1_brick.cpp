#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
    int nr,nc; cin>>nr>>nc;
    char data[nr][nc];
    int opos[nc];
    for1(i,0,nc) opos[i]=nr;
    for1(i,0,nr) {
        for1(j,0,nc) {
            cin>>data[i][j];
            if (data[i][j]=='O') {
                opos[j]=min(opos[j],i);
            }
        }
    }
    int n;
    for1(c,0,nc) {
        cin>>n;
        for(int i = opos[c]-1;i>=0&&n--;i--) {
             data[i][c]='#';
        }
    }

    for1(i,0,nr) {
        for1(j,0,nc) {
            cout<<data[i][j];
        }
        cout<<endl;
    }



    return 0;
}
