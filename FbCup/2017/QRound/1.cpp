#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

double pi = acos(-1);

bool incircle(double x,double y) {
    if ((x-50)*(x-50)+(y-50)*(y-50)<=2500) return true;
    return false;
}

double angle(double x,double y) {
    if (x==50 && y==50) return 0;
    double c = hypot(x-50,y-100);
    double a = 50;
    double b = hypot(x-50,y-50);
    double res = acos((a*a+b*b-c*c)/(2*a*b));
    res = 180*res/pi;
    if (x<50) {
        res = 360-res;
    }
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t;
    for1(_t,1,t+1) {
        double pp,x,y; cin>>pp>>x>>y;
        double p = 18*pp/5;
        bool res = true; //true = white false = black
        cout<<"Case #"<<_t<<": ";
        //test is in circle or not
        if (incircle(x,y)) {
            //if not in circle return white
            //if in circle check next
            //cerr<<"circle";
            //if angle < input angle (input pen percent) then black else white
            double a = angle(x,y);
            //cerr<<p<<' '<<a<<endl;
            if (a<=p) {
                res = false;
            }
        }

        cout<<(res?"white":"black")<<endl;
    }

	return 0;
}
