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
	int a[4][4];
	for1(i,0,4) {
		for1(j,0,4) scanf("%d",&a[i][j]);
	}
	
	bool res = false;
	
	if (a[0][3]) {
		if (a[0][0]||a[0][1]||a[0][2]) res = true;
		if (a[1][0]||a[2][1]||a[3][2]) res = true;
	}
	if (a[1][3]) {
		if (a[1][0]||a[1][1]||a[1][2]) res = true;
		if(a[0][2]||a[2][0]||a[3][1]) res = true;
	}
	if (a[2][3]) {
		if (a[2][0]||a[2][1]||a[2][2]) res = true;
		if (a[0][1] || a[1][2] || a[3][0]) res = true;
	}
	if (a[3][3]) {
		if (a[3][0]||a[3][1]||a[3][2]) res = true;
		if (a[0][0] || a[1][1] || a[2][2]) res = true;
	}
	
	if (res) cout<<"YES"; else cout<<"NO";
	
	return 0;
}
