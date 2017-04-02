#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int data[1000][1000]; //highest optimal use normal (must set as global -> use max size) because not need to set start value
int mastersum[1000][1000]; //highest optimal use normal (must set as global -> use max size) because only need to set (0,0) = 0

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    //sliding window
    //freeze first col to master var
    //for each first col freezed do col 1,2,3,4,5 sliding window in child var
    int nr,nc,k; scanf("%d %d %d",&nr,&nc,&k);
    //vector<vector<int>> data(nr,vector<int>(nc)); //highest optimal use normal (must set as global -> use max size) because not need to set start value

    for1(i,0,nr) {
        for1(j,0,nc) {
            scanf("%d",&data[i][j]);
        }
    }

    //vector<vector<int>> mastersum(nr-k+1,vector<int>(nc-k+1,0)); //highest optimal use normal (must set as global -> use max size) because only need to set (0,0) = 0


    mastersum[0][0] = 0;

    int currmax = -1;

    for1(i,0,k) {
        for1(j,0,k) {
            mastersum[0][0] += data[i][j];
        }
    }

    //first col
    /*for1(i,1,nr-k+1) {
        //copy value
        mastersum[i][0] = mastersum[i-1][0];
        //minus row i-1
        for1(j,0,k) {
            mastersum[i][0] -= data[i-1][j];
        }
        //add row i+k-1
        for1(j,0,k) {
            mastersum[i][0] += data[i+k-1][j];
        }
    }*/

    //first row
    for1(i,1,nc-k+1) {
        //copy value
        mastersum[0][i] = mastersum[0][i-1];
        //minus row i-1
        for1(j,0,k) {
            mastersum[0][i] -= data[j][i-1];
        }
        //add row i+k-1
        for1(j,0,k) {
            mastersum[0][i] += data[j][i+k-1];
        }
    }

    for1(i,1,nr-k+1) {
        int minus = 0;
        int add = 0;
        for1(a,0,k) {
            minus += data[i-1][a];
        }
        for1(a,0,k) {
            add += data[i+k-1][a];
        }
        for1(j,0,nc-k+1) {
            //must dai mastersum[i][j]
            mastersum[i][j] = mastersum[i-1][j];
            /*//minus col j-1
            for1(a,0,k) {
                mastersum[i][j] -= data[i+a][j-1];
            }
            //add col j+k-1
            for1(a,0,k) {
                mastersum[i][j] += data[i+a][j+k-1];
            }*/

            mastersum[i][j] -= minus;
            mastersum[i][j] += add;

            minus -= data[i-1][j];
            add -= data[i+k-1][j];
            if (j+k < nc) {
                minus += data[i-1][j+k];
                add += data[i+k-1][j+k];
            }

            currmax = max(currmax,mastersum[i][j]);

        }
    }


    printf("%d",currmax);
    /*for1(i,0,nr-k+1) {
        cout<<mastersum[i][0]<<endl;
    }*/

    /*cerr<<endl;
    for1(i,0,nr-k+1) {
        for1(j,0,nc-k+1) {
            cerr<<mastersum[i][j]<<' ';
        }
        cerr<<endl;
    }*/
	return 0;
}
