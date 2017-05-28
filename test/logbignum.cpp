#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll floorlog2(ll a) {
    ll res = 0;
    while (a) {
        a>>=1;
        res++;
    }
    return res-1;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(25)<<boolalpha;
    //crit test case :
    //log_2(288230376151711743) = 57.999999999999999994994646087789 not equal to 58
    //but computer think it is 58 because it has many 9
    //use normal way
    cout<<"Normal : "<<log2(288230376151711743)<<" fail"<<endl;
    //use double
    double x = log2(288230376151711743);
    cout<<"Double : "<<x<<" fail"<<endl;
    //use long double
    long double zz = log2(288230376151711743);
    cout<<"Long double : "<<zz<<" fail"<<endl;
    //use log2(double(...))
    double y = log2(double(288230376151711743));
    cout<<"log2(double(...)) : "<<y<<" fail"<<endl;
    //use floor(log2(double(...)))
    long long fy = floor(log2(double(288230376151711743)));
    cout<<"Floor log2(double(...)) : "<<fy<<" fail"<<endl;
    //use log2(long double(...))
    long double z = log2((long double)288230376151711743);
    cout<<"log2((long double)(...)) : "<<z<<" success but not perfect"<<endl;
    //use floor(log2(long double(...)))
    long long fz = floor(log2((long double)288230376151711743));
    cout<<"Floor log2((long double)(...)) : "<<fz<<" success"<<endl;
    //use log2l(n)
    long double l = log2l(288230376151711743);
    cout<<"log2l(n) : "<<l<<" success but not perfect"<<endl;
    //use log2l((long double)n)
    long double l2 = log2l((long double)288230376151711743);
    cout<<"log2l((long double)n) : "<<l2<<" success but not perfect"<<endl;
    //use floor(log2l(n))
    long double fl = floor(log2l(288230376151711743));
    cout<<"floor(log2l(n)) : "<<fl<<" success"<<endl;
    //Amazing ... log2(long double(n)) != log2l(n)
    cout<<"log2((long double)(n)) == log2l(n) : "<<(log2((long double)288230376151711743) == log2l(288230376151711743))<<" ... fail"<<endl;
    //use floor(log2(...)) = index of leftmost bit 1 (count from right , start from 0)
    cout<<"use bitwise floorlog2(...) : "<<floorlog2(288230376151711743)<<" success"<<endl;
	return 0;
}
