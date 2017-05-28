#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ld cal(ld p,ld q,ld r,ld s,ld t,ld u,ld x) {
    //decrease function
    /*for(ld x = 0;x<=1;x+=0.05) {
        cerr<<x<<' '<<p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u<<endl;
    }*/


    return p*expl(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(4);
    ld p,q,r,s,t,u;
    while (cin>>p>>q>>r>>s>>t>>u) {
        ld l = 0,h = 1; //(l,h) = (aow,aow) -> tud tua te mai pen kum tob ting ton next
        bool ok = false;
        ld mid = 0;
        for1(i,0,30) { //(aow,aow) ... if (l==h) then aow 1 tua pork [l,h] ... ex [3,3] = {3}
            mid = (l+h)/2;
            ld val = cal(p,q,r,s,t,u,mid);
            //cout<<val<<endl;
            if (abs(val)<0) {
                //cout<<mid<<endl;
                ok = true;
                h = mid-0.000001;
                //break;
            } else {
                if (val<0) {
                    h = mid-0.000001;
                } else {
                    l = mid+0.000001;
                }
            }
        }
        if (abs(cal(p,q,r,s,t,u,mid))<1E-5) ok = true;
        if (!ok) {
            cout<<"No solution"<<endl;
        } else cout<<abs(mid)<<endl;
    }
	return 0;
}
