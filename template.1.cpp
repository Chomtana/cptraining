#include <bits/stdc++.h>

#define for1(i,a,b) for(int i=a;i<b;i++)
#define for2(i,a,b) for(int i=a-1;i>=b;i--)
#define for3(i,a,b,c) for(int i=a;i<b;i+=c)
#define for4(i,a,b,c) for(int i=a-1;i>=b;i-=c)
#define debugv1(v) for1(_____,0,v.size()) cout<<v[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<v[_____]<<' '; cout<<endl;
#define debugv3(v,start,end) for1(_____,start,end) cout<<v[_____]<<' '; cout<<endl;

using namespace std;

int main() {
    cout<<fixed;
    ios::sync_with_stdio(false);
    vector<int> dd(10);
    dd[0]=5;
    dd[1]=8;
    dd[2]=4;
    dd[3]=3;
    dd[4]=7;
    dd[5]=9;
    dd[6]=0;
    dd[7]=833;
    dd[8]=223;
    dd[9]=1231232;
    debugv1(dd);
    debugv2(dd,5);
    debugv3(dd,3,8);
    
    return 0;
}