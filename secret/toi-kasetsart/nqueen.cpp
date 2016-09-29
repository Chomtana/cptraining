#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

vector< int > data;
int n;
int c = 0;

bool check(int i) {
    //bool ok = true;
    int nn = 0;
    while (data[nn]!=-1 && nn<n) nn++;
    //for1(i,1,nn) {
        //if (data[i]==-1) break;
        for (int j = i-1;j>=0;j--) {
            if (data[i]==data[j]) return false;//ok = false;
            if (abs(data[i]-data[j])==i-j) return false;//ok = false;
        }
        for (int j = i+1;j<nn;j++) {
            if (data[i]==data[j]) return false;//ok = false;
            if (abs(data[i]-data[j])==j-i) return false;//ok = false;
        }
    //}
    return true;
}

void bt(int row) {
    if (row>=n) {
        //if (check()) {
            //for1(i,0,n) cout<<data[i]<<' ';
            //cout<<endl;
            c++;
        //}
        //for1(i,0,n) cout<<data[i]<<' ';
        //cout<<endl;
        return;
    }
    for1(i,0,n) {
        data[row] = i;
        /*for1(i,0,n) cout<<data[i]<<' ';
        cout<<','<<check();
        cout<<endl;*/
        if (check(row)) bt(row+1);
        data[row] = -1;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin>>n;
    data.resize(n,-1);
    bt(0);
    cout<<c;
    /*data[0]=1;
    data[1]=3;
    data[2]=0;
    data[3]=2;
    cout<<check();*/

    return 0;
}
