#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int data[100][100];
int n;

#define macro(a,b,c,d,e,f) if (get(a,j)==get(i,j) && get(i,b)==get(i,j) && get(c,j)!=get(i,j) && get(i,d)!=get(i,j) && get(a,b)!=get(i,j) && get(e,j)!=get(i,j) && get(i,f)!=get(i,j) && get(a,f)!=get(i,j) && get(e,b)!=get(i,j)) {data[a][j] = -1; data[i][b] = -1; data[i][j]=-1; res++;}

int get(int i,int j) {
    if (i>=0 && j>=0 && i<n && j<n) return data[i][j];
    return -2;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    scanf("%d",&n);
    for1(i,0,n) {
        for1(j,0,n) {
            scanf("%d",&data[i][j]);
        }
    }

    //bool ans[10];
    //for1(i,0,10) ans[i] = false;

    int res = 0;

    for1(i,0,n) {
        for1(j,0,n) {
            /*if (get(i-2,j)==get(i,j) || get(i+2,j)==get(i,j) || get(i,j-2)==get(i,j) || get(i,j+2)==get(i,j) || get(i-1,j-1)==get(i,j) || get(i-1,j+1)==get(i,j) || get(i+1,j-1)==get(i,j) || get(i+1,j+1)==get(i,j)) {
                continue;
            }*/


            macro(i-1,j-1,i-2,j-2,i+1,j+1)
            else macro(i-1,j+1,i-2,j+2,i+1,j-1)
            else macro(i+1,j-1,i+2,j-2,i-1,j+1)
            else macro(i+1,j+1,i+2,j+2,i-1,j-1)
        }
    }

    /*for1(i,0,n) {
        for1(j,0,n) {
            ans[data[i][j]] = false;
        }
    }*/

    //int res = 0;
    //for1(i,0,10) res+=ans[i];
    cout<<res;
	return 0;
}
