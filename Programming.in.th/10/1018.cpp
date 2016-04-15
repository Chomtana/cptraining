#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;

using namespace std;

void move(int &x,int &y,int dir,int n) {
    switch (dir) {
        case 0: y+=n; break;
        case 1: x+=n; break;
        case 2: y-=n; break;
        case 3: x-=n; break;
    }
}

int main() {
    cout<<fixed;
    ios::sync_with_stdio(false);
    int t; cin>>t;
    int x = 0,y=0;
    bool ok = true;
    int dir = 1; //NESW
    while (t--) {
        string com; cin>>com;
        int n; cin>>n;
        if(com=="LT") {
            dir--;
            if (dir==-1) {
                dir = 3;
            }
        } else if(com=="RT") {
            dir++;
        } else if(com=="FD") {
            
        } else if(com=="BW") {
            dir+=2;
        }
        dir %= 4;
        move(x,y,dir,n);
        if (abs(x)>=50000 || abs(y)>=50000) ok=false;
    }
    if(!ok) {
        cout<<"DEAD"; return 0;
    }
    cout<<x<<' '<<y<<endl;
    switch (dir) {
        case 0: cout<<'N'; break;
        case 1: cout<<'E'; break;
        case 2: cout<<'S'; break;
        case 3: cout<<'W'; break;
    }
    return 0;
}