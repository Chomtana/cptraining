#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	//cout<<setprecision(2);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        map<char,double> price;
        //fill(price,price+256,0);
        while (n--) {
            char c; double x; cin>>c>>x;
            price[c] = x;
        }
        cin>>n;
        cin.ignore();
        /*for(auto x:price) {
            cerr<<x.first<<' '<<x.second<<endl;
        }*/
        double p = 0;
        while (n--) {
            string s; getline(cin,s);
            for(char c:s) {
                p += price[c];
            }
            //cerr<<s<<endl;
        }
        printf("%0.2lf$\n", p/100.0);
    }
	return 0;
}
