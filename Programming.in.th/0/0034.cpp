#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int gcd(int a,int b) {
    return (b==0?a:gcd(b,a%b));
}

bool isrootable(int x) {
    return (int)sqrt(x)*(int)sqrt(x)==x;
}

int main() {
    ios::sync_with_stdio(false);
    int a,b,c; cin>>a>>b>>c;
    if (b*b-4*a*c<0 || !isrootable(b*b-4*a*c)) {
        cout<<"No Solution";
        return 0;
    }

    int p1 = -b+sqrt(b*b-4*a*c);
    int q = 2*a;
    int p2 = -b-sqrt(b*b-4*a*c);
    /*
    x = p/q
    qx-p = 0
    -qx+p = 0
    */

    if (q<0) {
        q = -q;
        p1 = -p1;
        p2 = -p2;
    }

    int gcd1 = gcd(max(abs(p1),abs(q)),min(abs(p1),abs(q)));
    int gcd2 = gcd(max(abs(p2),abs(q)),min(abs(p2),abs(q)));

    p1/=gcd1;
    p2/=gcd2;

    int q1 = q/gcd1;
    int q2 = q/gcd2;

    p1 = -p1;
    p2 = -p2;

    int qa = q1*q2;
    int r = a/qa; //r(...x-...)(...x-...) = (...x-...)r(...x-...)

    if (q1<q2) {
        cout<<q1<<' '<<p1<<' '<<r*q2<<' '<<r*p2<<endl;
    } else if (q1==q2) {
        if (p1<p2) {
            cout<<q1<<' '<<p1<<' '<<r*q2<<' '<<r*p2<<endl;
        } else {
            cout<<q2<<' '<<p2<<' '<<r*q1<<' '<<r*p1<<endl;
        }
    } else {
        cout<<q2<<' '<<p2<<' '<<r*q1<<' '<<r*p1<<endl;
    }


    return 0;
}
