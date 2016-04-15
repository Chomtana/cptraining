#include <bits/stdc++.h>

#define for1(i,s,e) for(int (i)=(s);(i)<(e);(i)++)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    while (true) {
        int sel[3]; sel[0]=0; sel[1]=1; sel[2]=2;
        char firstres[4];
        int data[9];
        int sum = 0;
        for1(i,0,9) {
            if (!(cin>>data[i])) return 0;
            sum += data[i];
        }
        int currmin = sum;
        do {
            int res = sum;
            for1(i,0,3)  {
                res -= data[3*i+sel[i]];
            }
            
            if (res<=currmin) {
                char _res[4];
                for1(i,0,3) {
                    switch (sel[i]) {
                        case 0: _res[i]='B'; break;
                        case 1: _res[i]='G'; break;
                        case 2: _res[i]='C'; break;
                    }
                }
                //cout<<_res<<' '<<(res<currmin)<<endl;
                if (res<currmin || lexicographical_compare(_res,_res+3,firstres,firstres+3)) {
                    firstres[0]=_res[0];
                    firstres[1]=_res[1];
                    firstres[2]=_res[2];
                }
                
                currmin = res;
            }
            //cout<<sel[0]<<endl;
        } while (next_permutation(sel,sel+3));
        for1(i,0,3) {
            cout<<firstres[i];
        }
        cout<<' '<<currmin<<endl;
    }
    return 0;
}