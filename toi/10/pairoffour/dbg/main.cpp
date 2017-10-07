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

char data[1005];
bool rem[1005];
int n;
//int raw[1005][3];

int dp[1005][1005];


///dp mai dai prok me karn chai global state (changetonext donext reverse)
int recur(int i,int j) {

    if (j-i<=2) return 0;

    //if(dp[i][j]!=-1) return dp[i][j];

    int res = 0;

    char toright = 'Z';
    int lefti = -1;
    char toleft = 'Z';
    int righti = -1;
    for1(k,j+1,n) {
        if (!rem[k]) {
            toright = data[k];
            righti = k;
            break;
        }
    }

    for(int k = i-1;k>=0;k--) {
        if (!rem[k]) {
            toleft = data[k];
            lefti = k;
            break;
        }
    }

    for1(k,i,j+1) {
        if (k-1>=i && k+1<=j) {
            if (data[k-1]==data[k+1]) {
                rem[k-1] = true;
                rem[k] = true;
                rem[k+1] = true;
                res = max(res,recur(i,k-2) + recur(k+2,j) + 1);
                rem[k-1] = false;
                rem[k] = false;
                rem[k+1] = false;
            } else {
                rem[k] = true;
                res = max(res,recur(i,k-1) + recur(k+1,j));
                rem[k] = false;
            }
        } else {
            if (k==i) {
                if (data[k+1]==toleft) {
                    rem[lefti] = true;
                    rem[k] = true;
                    rem[k+1] = true;
                    res = max(res,recur(i,lefti-1) + recur(k+2,j) + 1);
                    rem[lefti] = false;
                    rem[k] = false;
                    rem[k+1] = false;
                }
            } else if(k==j) {
                if (data[k-1]==toright) {
                    rem[k-1] = true;
                    rem[k] = true;
                    rem[righti] = true;
                    res = max(res,recur(i,k-2) + recur(righti+1,j) + 1);
                    rem[k-1] = false;
                    rem[k] = false;
                    rem[righti] = false;
                }
            } else {
                rem[k] = true;
                res = max(res,recur(i,k-1) + recur(k+1,j));
                rem[k] = false;
            }
        }
    }

    return /*dp[i][j] = */res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
     cin>>n;
     memset(dp,-1,sizeof(dp));

    for1(i,0,n) {
        char raw[3];
        scanf("%s",raw);
        data[i] = raw[0];
    }

    cout<<recur(0,n-1);


	return 0;
}
