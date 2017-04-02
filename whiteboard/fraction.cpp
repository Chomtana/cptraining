#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

class Fraction {
private:
    int num;
    int denom;
public:
    Fraction() {
        num = 1;
        denom = 1;
    }

    Fraction(int n,int d) {
        num = n;
        denom = d;
    }

    void setFraction(int n,int d) {
        num = n;
        denom = d;
    }

    void getFraction(int &n,int &d) {
        n = num;
        d = denom;
    }

    int getNum() {return num;}
    int getDenom() {return denom;}

    Fraction add(Fraction other) {
        //1/2 + 3/4 =
        Fraction res(this->num*other.getDenom()+this->denom*other.getNum(),this->denom*other.getDenom());
        return res;
    }

    Fraction sub(Fraction other) {
        Fraction res(this->num*other.getDenom()-this->denom*other.getNum(),this->denom*other.getDenom());
        return res;
    }

    Fraction mul(Fraction other) {
        Fraction res(this->num*other.getNum(),this->denom*other.getDenom());
        return res;
    }

    Fraction div(Fraction other) {
        Fraction res(this->num*other.getDenom(),this->denom*other.getNum());
        return res;
    }

    bool isEqualTo(Fraction other) {
        return (this->num==other.getNum() && this->denom==other.getDenom());
    }

    void print() {
        cout<<this->num<<'/'<<this->denom;
    }

    string str() {
        stringstream ss;
        ss<<this->num<<'/'<<this->denom;
        return ss.str();
    }

};

int main() {
    Fraction f1(2,3),f2(4,7),f3,f4;
    int x,y;
    f2.getFraction(x,y);
    f3.setFraction(x,y);
    f4=f3.mul(f1);
    f1.print(); cout<<" x ";
    f3.print(); cout<<" = ";
    f4.print(); cout<<endl;
    Fraction *f5=new Fraction(1,2);
    cout<<f4.str()+" / "+f5->str();
    cout<<" = "+f4.div(*f5).str()+"\n";
    if(f2.isEqualTo(f3))
    cout<<"Equal.\n";
    else
    cout<<"Not equal.\n";
	return 0;
}
