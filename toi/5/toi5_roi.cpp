#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    double c; cin>>c;
    double currmin = 1E9;
    int nres;
    int pres;
    for(double n = 1000;n<=15000;n+=500) {
        for(double p = 74;p<=144;p++) {
            double rawprofit = (100-(0.8569*exp(0.09*(p-100))))*n*p/100;
            double spend = (c+n*(100-(n-1000)/500));
            double profit = rawprofit-spend;
            if (profit > 0) {
                if (profit<currmin) {
                    currmin = profit;
                    nres = n;
                    pres = p;
                }
            }
        }

    }

    printf("%d\n%d\n%.2f",nres,pres,currmin);
	return 0;
}
