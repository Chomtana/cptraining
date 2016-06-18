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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	string linein;
	stringstream coutt;
	while (getline(cin,linein)) {
		if (linein[0]=='0') break;
		stringstream ss(linein);
		int k; ss>>k;
		int in;
		vector<int> data;
		while (ss>>in) {
			data.push_back(in);
		}
		
		sort(data.begin(),data.end());
		
		for1(i1,0,k) {
			for1(i2,i1+1,k) {
				for1(i3,i2+1,k) {
					for1(i4,i3+1,k) {
						for1(i5,i4+1,k) {
							for1(i6,i5+1,k) {
								coutt<<data[i1]<<' '<<data[i2]<<' '<<data[i3]<<' '<<data[i4]<<' '<<data[i5]<<' '<<data[i6]<<endl;
							}
						}
					}
				}
			}
		}
		
		coutt<<endl;
	}
	string couts = coutt.str();
	cout<<couts.substr(0,couts.size()-2);
	return 0;
}