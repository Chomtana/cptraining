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

int data[105][105];
int qs[105][105]; //qs[i][j] = sigma(data[i][0...j])

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;
	for1(i,0,n) {
		for1(j,0,n) scanf("%d",&data[i][j]);
	}
	
	for1(i,0,n) {
		qs[i][0] = data[i][0];
		for1(j,1,n) {
			qs[i][j] = qs[i][j-1]+data[i][j];
		}
	}
	
	int res = 0;
	
	for1(i,0,n) { //start col
		for1(j,i,n) { //end col
			
			//vector<int> domcs;
			int sum = 0;
			//int maxsum = 0;
			
			for1(k,0,n) {
				int x = 0;
				if (i==0) {
					//domcs.push_back(qs[k][j]);
					x = qs[k][j];
				} else {
					//domcs.push_back(qs[k][j]-qs[k][i-1]);
					x = qs[k][j]-qs[k][i-1];
				}
				
				sum += x;
				if (sum<0) sum=0;
				//maxsum = max(maxsum,sum);
				res = max(res,sum);
			}
			
			
			
			//for1(k,0,n)
			
		}
	}
	
	cout<<res<<endl;
	return 0;
}
