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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; cin>>nr>>nc;
    int data[nr][nc];
    int res[nr][nc];
    for1(i,0,nr) {
        for1(j,0,nc) {
            scanf("%d",&data[i][j]);
            res[i][j] = data[i][j];
        }
    }

    for1(i,0,nr) {
        for1(j,0,nc) {
            if (data[i][j]==0) {
                int dr[] = {0,0,1,-1};
                int dc[] = {1,-1,0,0};
                int n = 0;
                int sum = 0;
                for1(k,0,4) {
                    int ner = i+dr[k];
                    int nec = j+dc[k];
                    if (ner>=0&&nec>=0&&ner<nr&&nec<nc&&data[ner][nec]!=0) {
                        n++;
                        sum+=data[ner][nec];
                    }
                }
                if (n!=0) {
                    res[i][j] = sum/n;
                }
            }
        }
    }

    for1(i,0,nr) {
        for1(j,0,nc) printf("%d ",res[i][j]); printf("\n");
    }
    /*for1(i,0,nr) {
        for1(j,0,nc) printf("%d ",data[i][j]); printf("\n");
    }*/
	return 0;
}
