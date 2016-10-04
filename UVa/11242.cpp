#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
using namespace std;
int main () {
    int nf,nr;
    while (cin>>nf , nf) {
        cin>>nr;
        double f[nf];
        double r[nr];
        for1(i,0,nf) {
            cin>>f[i];
        }
        for1(i,0,nr) {
            cin>>r[i];
        }

        vector<double> dr;
        for1(i,0,nr) {
            for1(j,0,nf) {
                if (f[j]!=0) dr.push_back(r[i]/f[j]);
            }
        }
        sort(dr.begin(),dr.end());

        double res = 0;
        for1(i,1,dr.size()) {
            if (min(dr[i],dr[i-1])!=0) res = max(res,max(dr[i],dr[i-1])/min(dr[i],dr[i-1]));
        }

        printf("%.2f\n",res);
    }
    return 0;
}
