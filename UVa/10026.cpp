#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;
#define debug1(a) cout<<(a)<<endl;
#define debug2(a,b) cout<<(a)<<' '<<(b)<<endl;
#define debug3(a,b,c) cout<<(a)<<' '<<(b)<<' '<<(c)<<endl;
#define debug4(a,b,c,d) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<' '<<(e)<<endl;

typedef long long ll;

using namespace std;

/*
Assume there are two task
1 1000
3 4
1->2 : do 1 antiprofit = 0 then do 2 antiprofit = 4*1
1->2 antiprofit = (s2)*(t1)
2->1 antiprofit = (s1)*(t2)
if task 1 optimal than task 2
antiprofit1 < antiprofit2
(s2)*(t1) < (s1)*(t2)
(t1)/(s1) < (t2)/(s2)
if (t1)/(s1) < (t2)/(s2) then select task 1 before task 2 (select less t/s first)

*/

struct type {
    int i;
    double t,s;
    double ts;
};

bool typesort(type a,type b) {
    if(a.ts<b.ts) return true;
    if(a.ts>b.ts) return false;
    
    if(a.i<b.i) return true;
    if(a.i>b.i) return false;
}

int main() {
    ios::sync_with_stdio(false);
    cout<<fixed;
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        type data[n];
        for1(i,0,n) {
            cin>>data[i].t>>data[i].s;
            data[i].i = i;
            data[i].ts = data[i].t/data[i].s;
        }
        sort(data,data+n,typesort);
        cout<<data[0].i+1;
        for1(i,1,n) {
            cout<<' '<<data[i].i+1;
        }
        cout<<endl;
        if(t) cout<<endl;
    }
    return 0;
}