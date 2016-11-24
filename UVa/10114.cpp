#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

void printmonth(int m) {
    cout<<m;
    if (m==1) cout<<" month"<<endl;
    else cout<<" months"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    double m = 0;
    while (cin>>m , m>=0) {
        double down,loan,n; cin>>down>>loan>>n;
        double monthbf,percentbf; cin>>monthbf>>percentbf;
        double month,percent;
        double car = (down+loan);
        double monthly = loan/m;
        n--;
        bool running = true;
        for1(i,0,n) {
            cin>>month>>percent;
            if (running) {
                for1(j,monthbf,month) {
                    car *= (1-percentbf);
                    //cerr<<"DEBUG : "<<j<<' '<<car<<' '<<loan-monthly*j<<endl;
                    if (car >= loan-monthly*j) {
                        printmonth(j);
                        running = false;
                        break;
                    }

                }
            }

            monthbf = month;
            percentbf = percent;
        }
        if (running) {
            for1(j,monthbf,m+1) {

                car *= (1-percentbf);
                //cerr<<"DEBUG : "<<j<<' '<<car<<' '<<loan-monthly*j<<endl;
                if (car >= loan-monthly*j) {
                    printmonth(j);
                    running = false;
                    break;
                }

            }
        }
    }
}
