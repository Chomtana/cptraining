#include <bits/stdc++.h>

using namespace std;

void printmonth(int m) {
    cout<<m;
    if (m==1) cout<<" month"<<endl;
    else cout<<" months"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    double m; cin>>m;
    while (m>=0) {
        bool run = true; //running?
        double salary,loan,t; cin>>salary>>loan>>t;
        double car = loan;
        int lastmonth = 0;
        int lastpercent = 0;
        while (t--) {
            int m; cin>>m;
            double percent; cin>>percent;
            if (run) {
                for (lastmonth++;lastmonth<m;lastmonth++) {
                    car -= car*lastpercent;
                    if (car+lastmonth*salary >= loan) {
                        printmonth(lastmonth);
                        run = false;
                        goto exitrun;
                    }
                }
                car -= car*percent;
                if (car+m*salary >= loan) {
                    printmonth(m);
                    run = false;
                }
            }
            
            exitrun:
            lastmonth = m;
            lastpercent = percent;
        }
        if (run) {
            for (lastmonth++;;lastmonth++) {
                car -= car*lastpercent;
                if (car+lastmonth*salary >= loan) {
                    printmonth(lastmonth);
                    cout<<car+lastmonth*salary<<endl;
                    run = false;
                    break;
                }
            }
        }
        cin>>m;
    }
}