#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

char data[1005][1005];
int dp[1005][1005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; cin>>nr>>nc;
    for1(i,0,nr) for1(j,0,nc) dp[i][j] = -1;
    for1(i,0,nr) {
        scanf("%s",data[i]);
    }

    int currmax = 0;

    for1(i,0,nr) {
        for1(j,0,nc) {
            if (dp[i][j]!=-1) {
                currmax = max(currmax,dp[i][j]);
                continue;
            }
            if (data[i][j]=='1') {
                int k = 1;
                while(true) {
                    if (i+k-1>=nr || j+k-1>=nc) break;
                    if (data[i+k-1][j+k-1]=='0') break;
                    //check left , up of (i+k,j+k) k tua
                    bool ok = true;
                    for1(l,1,k) {
                        if (data[i+k-l-1][j+k-1]=='0' || data[i+k-1][j+k-l-1]=='0') {
                            ok = false;
                            break;
                        }
                    }
                    if(!ok) break;
                    k++;
                }

                k--;

                //cerr<<i<<' '<<j<<' '<<k<<endl;

                for1(a,0,k) {
                    for1(l,0,a+1) {
                        /*if (data[i+k-l][j+k]=='0' || data[i+k][j+k-l]=='0') {
                            ok = false;
                            break;
                        }*/
                        dp[i+a-l][j+a] = k-a;
                        dp[i+a][j+a-l] = k-a;
                    }
                }

                currmax = max(currmax,dp[i][j]);
            }
        }
    }

    cout<<currmax;
	return 0;
}
