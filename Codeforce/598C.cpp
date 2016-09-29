#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;

/*
angle between vector = delta (angle on x-axis)

tan (angle on x-axis) = y/x
angle on x-axis = arctan (y/x)

lowest angle between vector = a-b (a,b has nearest x-axis angle) (some case error (case coordinate 1 and 4))

lowest angle between vector = min(a_min+a(re)_min , 360-(a_max+a(re)_max))

*/

struct type {
    double x,y;
    double a,are; //x-axis angle
    int i;
};

int main() {
    ios::sync_with_stdio(false);
    int n; cin>>n;
    type data[n];

    int amax=0,aremax = 0,amaxi,aremaxi;
    int amin=999999,aremin=9999999,amini,aremini;

    for1(i,0,n) {
        cin>>data[i].x>>data[i].y;
        data[i].a = abs(atan(data[i].y/data[i].x));
        if (data[i].x>=0 && data[i].y>=0) {

        } else if (data[i].x<0 && data[i].y >= 0) {
            data[i].a = 180-data[i].a;
        } else if (data[i].x<0 && data[i].y < 0) {
            data[i].a = 180+data[i].a;
        } else if (data[i].x>=0 && data[i].y<0) {
            data[i].a = 360-data[i].a;
        }
        data[i].are = 360-data[i].a;
        data[i].i=i+1;

        if (data[i].a>amax) {
            amax = data[i].a;
            amaxi = i+1;
        }
        if (data[i].are>aremax) {
            aremax = data[i].a;
            aremaxi = i+1;
        }
        if (data[i].a<amin) {
            amin = data[i].a;
            amini = i+1;
        }
        if (data[i].are<aremin) {
            aremin = data[i].a;
            aremini = i+1;
        }
    }

    int res1 = amin+aremin;
    int res2 = 360-(amax+aremax);
    //if (res1<res2) {
        cout<<amini<<' '<<aremini;
    //} else {
        //cout<<amaxi<<' '<<aremaxi;
    //}

    //sort(data,data+n,[](type a,type b){return a.a<b.a;});

    /*for1(i,0,n-1) {
        auto it = data+i;
        it++;
        int updif = abs((*it).a-data[i].a);
        if (updif>180) updif = 360-updif;
        if (updif<res) {
            resa = data[i].i;
            resb = (*it).i;
            res = updif;
        }

    }*/

    //cout<<resa<<' '<<resb;




    return 0;
}
