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

//int data[2005][2005];
int d1cache[2005][2005];
int d2cache[2005][2005];
int vcache[2005][2005];
int hcache[2005][2005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc,k; cin>>nr>>nc>>k;
    for1(i,0,nr) {
        for1(j,0,nc) {
            int x; scanf("%d",&x);
            if (i==0) {
                vcache[i][j] = x;
            } else {
                vcache[i][j] = vcache[i-1][j] + x;
            }
            if (j==0) {
                hcache[i][j] = x;
            } else {
                hcache[i][j] = hcache[i][j-1] + x;
            }
            if (i==0 || j==0) {
                d1cache[i][j] = x;
            } else {
                d1cache[i][j] = d1cache[i-1][j-1] + x;
            }
            if (i==0 || j==nc-1) {
                d2cache[i][j] = x;
            } else {
                d2cache[i][j] = d2cache[i-1][j+1] + x;
            }
        }
    }

    int currmax = -2E9;

    //do d1
    //int cache[2005];
    //cache[0] = 0;

    for1(i,0,nr-k+1) {
        int curr = 0;
        //cache[0] = 0;
        for1(j,0,k) {
            curr += hcache[i+j][j];
        }
        currmax = max(currmax,curr);
        //cerr<<i<<' '<<cache[0]<<endl;
        for1(j,1,nc-k+1) {
            curr = curr - vcache[i+k-1][j-1] + d1cache[i+k-1][j+k-1];
            if (i>0) {
                curr += vcache[i-1][j-1];
                curr -= d1cache[i-1][j-1];
            }
            currmax = max(currmax,curr);
            //cerr<<i<<' '<<j<<' '<<curr<<endl;
        }
    }

    //cerr<<endl;

    //do d2;
    for1(i,0,nr-k+1) {
        int curr = 0;
        //cache[0] = 0;
        for1(j,0,k) {
            curr += hcache[i+j][nc-1]-hcache[i+j][nc-j-2];
        }
        currmax = max(currmax,curr);
        //cerr<<i<<' '<<curr<<endl;
        for2(j,nc-2,k-1) {
            curr = curr - vcache[i+k-1][j+1] + d2cache[i+k-1][j-k+1];
            if (i>0) {
                curr += vcache[i-1][j+1];
                curr -= d2cache[i-1][j+1];
            }
            currmax = max(currmax,curr);
            //cerr<<i<<' '<<j<<' '<<curr<<' '<<currmax<<endl;
        }
    }


    cout<<currmax;
	return 0;
}

/*
10 11 4
-99 -99 -99 -99 -99 -99 -99 -99 -99 -99 -99
-99 -99 -99 -99 -99 -99 -99 -99 -99 -99 -99
-99 -99 -99 -99 -99 -99 -99 -99 -99 -99 -99
-99 -99 -99 -5 -99 -99 -99 -99 -99 -99 -99
-99 -99 -99 -5 -5 -99 -99 -99 -4 -99 -99
-99 -99 -99 -5 -5 -5 -99 -5 -6 -99 -99
-99 -99 -99 -5 -5 -5 -2 -5 -6 -99 -99
-99 -99 -99 -99 -99 -5 -5 -5 -4 -99 -99
-99 -99 -99 -99 -99 -99 -99 -99 -99 -99 -99
-99 -99 -99 -99 -99 -99 -99 -99 -99 -99 -99

8 11 4
-99 -99 -99 -99 -99 -99 -99 -99 -99 -99 -99
-99 -99 -99 -99 -99 -99 -99 -99 -99 -99 -99
-99 -99 -99 -99 -99 -99 -99 -99 -99 -99 -99
-99 -99 -99 -99 -99 -99 -99 -99 -99 -99 -99
-99 -99 -99 -99 -99 -99 -99 -99 -4 -99 -99
-99 -99 -99 -99 -99 -99 -99 -5 -6 -99 -99
-99 -99 -99 -99 -99 -99 -2 -5 -6 -99 -99
-99 -99 -99 -99 -99 -5 -5 -5 -4 -99 -99
*/
