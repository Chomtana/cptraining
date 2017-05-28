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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        cout<<"Case #"<<_<<":\n";
        int nr,nc; cin>>nr>>nc;
        string data[nr]; for1(i,0,nr) cin>>data[i];
        for1(i,0,nr) {
            for1(j,0,nc) {
                if (data[i][j]!='?') {
                    for1(k,1,nr) {
                        if (i+k<nr) {
                            if (data[i+k][j]!='?') break;
                            data[i+k][j] = data[i][j];
                        } else break;
                    }
                    for1(k,1,nr) {
                        if (i-k>=0) {
                            if (data[i-k][j]!='?') break;
                            data[i-k][j] = data[i][j];
                        } else break;
                    }
                }
            }
        }
        subfunc(bool,found,()) {
            for1(i,0,nr) {
                for1(j,0,nc) {
                    if (data[i][j]=='?') return true;
                }
            }
            return false;
        };
        while (found()) {
            for1(i,0,nr) {
                for1(j,0,nc) {
                    if (data[i][j]=='?') {
                        if (j-1>=0 && data[i][j-1]!='?') {
                            data[i][j] = data[i][j-1];
                        } else {
                            data[i][j] = data[i][j+1];
                        }
                    }
                }
            }
        }
        for1(i,0,nr) {
            cout<<data[i]<<endl;
        }
    }
	return 0;
}
