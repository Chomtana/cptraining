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

int nr,nc;
int data[505][505];
vector<vector<int>> diag;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	while (scanf("%d%d",&nr,&nc),nr!=0&&nc!=0) {
		for1(i,0,nr) for1(j,0,nc) scanf("%d",&data[i][j]);
		
		/*///build diagonal array
		//main diagonal
		diag.push_back(vector<int>());
		for1(i,0,min(nr,nc)) {
			diag[0].push_back(data[i][i]);
		}
		
		for1(i,1,nr) {
			diag.push_back(vector<int>());
			for1(j,0,max(nr,nc)) {
				if (i+j>=nr || j>=nc) break;
				diag.back().push_back(data[i+j][j]);
			}
		}
		
		for1(i,1,nc) {
			diag.push_back(vector<int>());
			for1(j,0,max(nr,nc)) {
				if(j>=nr || i+j>=nc) break;
				diag.back().push_back(data[j][i+j]);
			}
		}
		
		for1(i,0,diag.size()) {
			for1(j,0,diag[i].size()) {
				cerr<<diag[i][j]<<' ';
			}
			cerr<<endl;
		}
		
		
		//ยุ่งยาก เขียน bs เองดีกว่า
		*/
		
		int nq; scanf("%d",&nq);
		//greedy : select first element in row then find end with diagonal bs
		
		while (nq--) {
			int bs,be; scanf("%d%d",&bs,&be);
			int currmax = 0;
			for1(i,0,nr) {
				int sr = i;
				int sc = lower_bound(data[i],data[i]+nc,bs)-data[i];
				if (sc!=nc) {
					int l = 0; int r = max(nr,nc);
					while (l<=r) {
						int mid = (l+r)/2;
						if (sr+mid>=nr || sc+mid>=nc) {
							r = mid-1;
						} else {
							if (data[sr+mid][sc+mid]<=be) {
								l = mid+1;
							} else {
								r = mid-1;
							}
							
						}
						
					}
					currmax = max(currmax,l);
				}
			}
			printf("%d\n",currmax);
		}
		
		printf("-\n");
		
	}
	return 0;
}
