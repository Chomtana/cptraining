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
	int n; cin>>n;
    //start (n/2.n/2);
    vector<vector<int>> data(n,vector<int>(n));
    int pr = n/2;
    int pc = n/2;
    int pn = 2;
    int curr = 1;
    try {
        while(true) {
            for1(i,0,pn) {
                data.at(pr).at(pc) = curr;
                pc++;
                curr++;
            }
            pc--;
            curr--;
            for1(i,0,pn) {
                data.at(pr).at(pc) = curr;
                pr++;
                curr++;
            }
            pr--;
            curr--;
            pn++;
            for1(i,0,pn) {
                data.at(pr).at(pc) = curr;
                pc--;
                curr++;
            }
            pc++;
            curr--;
            for1(i,0,pn) {
                data.at(pr).at(pc) = curr;
                pr--;
                curr++;
            }
            pr++;
            curr--;
            pn++;
        }
    } catch (exception &e) {
        for1(i,0,n) {
            for1(j,0,n) {
                cout<<data[i][j]%10<<' ';
            }
            cout<<endl;
        }
    }
	return 0;
}
