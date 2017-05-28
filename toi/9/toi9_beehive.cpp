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

int data[1001][1001];
int sumdp[1001][1001];
int countdp[1001][1001];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; cin>>nr>>nc;

    for1(i,0,nr) {
        for1(j,0,nc) {
            scanf("%d",&data[i][j]);
        }
    }

    subfunc(int,getsumdp,(int i,int j)) {
        if (i<0 || i>=nr || j<0 || j>=nc) return 0;
        return sumdp[i][j];
    };

    subfunc(int,getcountdp,(int i,int j)) {
        if (i<0 || i>=nr || j<0 || j>=nc) return 0;
        return countdp[i][j];
    };

    for1(i,0,nc) {
        sumdp[0][i] = data[0][i];
        countdp[0][i] = 1;
    }

    for1(i,1,nr) {
        for1(j,0,nc) {
            if (i%2==0) {
                int maxdpbf = max(getsumdp(i-1,j-1),getsumdp(i-1,j));
                sumdp[i][j] = maxdpbf + data[i][j];
                if (getsumdp(i-1,j-1) == getsumdp(i-1,j)) {
                    countdp[i][j] = getcountdp(i-1,j-1) + getcountdp(i-1,j);
                } else if (getsumdp(i-1,j-1) == maxdpbf) {
                    countdp[i][j] = getcountdp(i-1,j-1);
                } else if (getsumdp(i-1,j) == maxdpbf) {
                    countdp[i][j] = getcountdp(i-1,j);
                }
            } else {
                int maxdpbf = max(getsumdp(i-1,j),getsumdp(i-1,j+1));
                sumdp[i][j] = maxdpbf + data[i][j];
                if (getsumdp(i-1,j)==getsumdp(i-1,j+1)) {
                    countdp[i][j] = getcountdp(i-1,j) + getcountdp(i-1,j+1);
                } else if (getsumdp(i-1,j)==maxdpbf) {
                    countdp[i][j] = getcountdp(i-1,j);
                } else if (getsumdp(i-1,j+1)==maxdpbf) {
                    countdp[i][j] = getcountdp(i-1,j+1);
                }
            }
        }
    }

    int maxsum = -1;
    vector<int> maxi;
    for1(i,0,nc) if (sumdp[nr-1][i]>maxsum) {
        maxsum = sumdp[nr-1][i];
        maxi.clear();
        maxi.push_back(i);
    } else if (sumdp[nr-1][i]==maxsum) {
        maxi.push_back(i);
    }

    cout<<maxsum<<' ';

    int countsum = 0;
    for(int &i:maxi) countsum += countdp[nr-1][i];

    cout<<countsum;

	return 0;
}
