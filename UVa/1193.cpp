#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;

using namespace std;

struct xy{ double x,y; };

/*
Create circle from left to right has best speed (we can select before to check)
Create circle with left margin of circle nearest to point

If (x-h)^2+(y-k)^2-r^2 <= 0 then point is in circle / on circle margin
*/

bool sortpoint(xy a,xy b) {
    return a.x<b.x;
}

bool inside(xy hk,xy p,double r) {
    return ((p.x-hk.x)*(p.x-hk.x)+(p.y-hk.y)*(p.y-hk.y)-r*r <= 0);
}

double rinx(xy p,double r) { //return distance between p and circle center
    return sqrt(r*r-p.y*p.y);
}

int main() {
    cout<<fixed;
    ios::sync_with_stdio(false);
    
    int t = 1;
    while (true) {
        int n; double r; cin>>n>>r;
        if (n==0 && r==0) break;
        bool run = true;
        xy point[n];
        for1(i,0,n) {
            cin>> point[i].x >> point[i].y;
            if (abs(point[i].y)>r) {
                run = false;
            }
        }
        if (!run) {
            cout<<"Case "<<t++<<": "<<-1<<endl;
            continue;
        }
        
        sort(point,point+n,sortpoint);
        xy currcenter;
        currcenter.y = 0;
        currcenter.x = point[0].x+rinx(point[0],r);
        int count = 1;
        for1(i,1,n) {
            if (inside(currcenter,point[i],r)) continue;
            double previous = currcenter.x;
            currcenter.x = point[i].x+rinx(point[i],r);
            //cout<<point[i].x<<' '<<previous<<' '<<currcenter.x<<endl;
            if (currcenter.x > previous) count++;
        }
        cout<<"Case "<<t++<<": "<<count<<endl;
        
    }
    
    return 0;
}