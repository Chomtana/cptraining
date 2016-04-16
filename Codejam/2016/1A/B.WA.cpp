#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;
#define debug1(a) cout<<(a)<<endl;
#define debug2(a,b) cout<<(a)<<' '<<(b)<<endl;
#define debug3(a,b,c) cout<<(a)<<' '<<(b)<<' '<<(c)<<endl;
#define debug4(a,b,c,d) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<' '<<(e)<<endl;

typedef long long ll;

using namespace std;

int n;

bool sortarr(vector<int> a,vector<int> b) {
	for1(i,0,n) {
		if (a[i]<b[i]) return true;
		if (a[i]>b[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t;
	for(int _t=1;_t<=t;_t++) {
		cout<<"Case #"<<_t<<":";
		cin>>n;
		vector< vector<int> > data(2*n-1,vector<int>(n));
		for1(i,0,2*n-1) {
			for1(j,0,n) {
				cin>>data[i][j];
			}
		}
		//debug1(n);
		sort(data.begin(),data.end(),sortarr);
		for1(i,0,2*n-1) {
			for1(j,0,n) {
				cout<<data[i][j]<<' ';
			}
			cout<<endl;
		}
		vector<int> last(n,0);
		for1(i,0,n) last[i]=i;
		bool ok = false;
		for1(i,0,2*n-1) {
			for1(j,0,n) {
				int oldlast = last[j];
				last[j] = data[i][j];
				//debug2(oldlast,last[j]);
				if (last[j]-oldlast > 1) {
					int mis = oldlast+1;
					for1(k,0,n) {
						//cout<<i<<endl;
						if (k==j) cout<<' '<<mis;
						else cout<<' '<<data[i][k];
					}
					ok = true;
					goto next;
				}
			}
		}
		
		for1(k,0,n) {
			cout<<' '<<data[2*n-2][k]+1;
		}
		next: cout<<endl; continue;
	}
	return 0;
}