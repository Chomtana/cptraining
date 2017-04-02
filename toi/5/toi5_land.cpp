#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; scanf("%d %d",&nr,&nc);
    double databak[nr][nc];
    double data[nr][nc];
    int n = nr*nc;
    pii permu[n];
    for1(i,0,nr) for1(j,0,nc) {
        scanf("%lf",&data[i][j]);
        databak[i][j] = data[i][j];
        permu[i*nc+j] = mp(i,j);
    }

    double minres = 1E15;

    do {
        for1(i,0,nr) for1(j,0,nc) data[i][j] = databak[i][j];
        double res = 0;
        for1(i,0,n) {
            int r = permu[i].first;
            int c = permu[i].second;
            res += data[r][c];
            double up = 0.1*data[r][c];
            int dr[] = {0,0,1,-1,1,1,-1,-1};
            int dc[] = {1,-1,0,0,1,-1,1,-1};
            for1(j,0,8) {
                int nextr = r+dr[j];
                int nextc = c+dc[j];
                if (nextr>=0 && nextc>=0 && nextr<nr && nextc<nc) {
                    data[nextr][nextc] += up;
                }
            }
        }

        minres = min(minres,res);
    } while (next_permutation(permu,permu+n));

    printf("%.2f",minres);
	return 0;
}
