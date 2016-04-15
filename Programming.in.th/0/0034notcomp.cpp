#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

struct ac {
    int a,c;
};

struct bd {
    int b,d;
};

//bddata[<b*d>] = (b,d) (if found)
vector<bd> bddata;
vector<ac> acdata;
int asol,bsol,csol,dsol;
bool havesol = false;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    if (B*B-4*A*C < 0) {
        cout << "No Solution";
        return 0;
    }
    
    //get bddata
    for (int b = 1;b<=abs(C);b++) {
        //if (b==0) continue; //No divide by zero
        if (C%b == 0) {
            int d = C/b;
            bd _bd;
            _bd.b=b; _bd.d=d;
            bddata.push_back(_bd);
        }
    }
    
    //get acdata
    for (int a = 1;a<=abs(A);a++) {
        //if (a==0) continue; //No divide by zero
        if (A%a == 0) {
            int c = A/a;
            ac _ac;
            _ac.a=a; _ac.c=c;
            acdata.push_back(_ac);
        }
    }
    
    //check B=ad+bc
    for (int i = 0;i<acdata.size();i++) {
        for (int j = 0;j<bddata.size();j++) {
            int a = acdata[i].a;
            int b = bddata[j].b;
            int c = acdata[i].c;
            int d = bddata[j].d;
            //cout << "aaa" << " " << a << " " << b << " " << c << " " << d << "\n";
            
            if (a*d+b*c == B) {
                asol = a;
                bsol = b;
                csol = c;
                dsol = d;
                havesol = true;
                
                int aold = a; int cold = c;
                if (A<0) {
                    a = -a;
                    c = -c;
                    if (a*d+b*c == B) {
                        asol = a;
                        bsol = b;
                        csol = c;
                        dsol = d;
                    }
                }
                if (C<0) {
                    b = -b;
                    d = -d;
                    if (a*d+b*c == B) {
                        asol = a;
                        bsol = b;
                        csol = c;
                        dsol = d;
                    }
                    a = aold;
                    c = cold;
                    if (a*d+b*c == B) {
                        asol = a;
                        bsol = b;
                        csol = c;
                        dsol = d;
                    }
                }
                goto end;
            }
        }
    }
    
    end:
    if (havesol) {
        cout << asol << " " << bsol << " " << csol << " " << dsol; 
    } else { cout << "No Solution"; }
    return 0;
}