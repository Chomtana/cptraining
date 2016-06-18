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
typedef pair<int,char> pic;

bool sortd(pic a,pic b) {
	return a.first>b.first;
}

bool major(vector<pic> &v) {
	int sum=0;
	
	for1(i,0,v.size()) sum+=v[i].first;
	for1(i,0,v.size()) if ((float)(v[i].first)>(float)(sum/2)) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t;
	for1(_t,1,t+1) {
		cout<<"Case #"<<_t<<":";
		
		int n; cin>>n;
		vector<pic> data(n);
		for1(i,0,n) {
			cin>>data[i].first;
			data[i].second = 'A'+i;
		}
		
		int x = 2;
		vector<string> result;
		while (true) {
			
			bool end = true;
			for1(i,0,n) {
				if (data[i].first!=0) {
					end = false;
					break;
				}
			}
			if (end) break;
			//cout<<' ';
			
			sort(data.begin(),data.end(),sortd);
			
			string res = "";
			
			res+=data[0].second;
			data[0].first--;
			
			if (data[0].first != 0) {
				data[0].first--;
				
				if (!major(data)) {
					data[0].first++;
					if (data[1].first != 0) {
						res+=data[1].second;
						data[1].first--;
					}
				} else {
					res+=data[0].second;
				}
			} else {
				if (data[1].first != 0) {
					res+=data[1].second;
					data[1].first--;
				}
			}
			/*if (data[1].first != 0) {
				cout<<data[1].second;
				data[1].first--;
			}*/
			result.push_back(res);
			// /cout<<' '<<res;
		}
		
		for (int k = 0;k<(int)(result.size())-2;k++) cout<<' '<<result[k];
		if (result[(int)(result.size())-1].size()==1) {
			cout<<' '<<result[(int)(result.size())-1];
			if ((int)result.size() >= 2) {
				cout<<' '<<result[(int)(result.size())-2];
			}
		} else {
			if ((int)result.size() >= 2) {
				cout<<' '<<result[(int)(result.size())-2];
			}
			cout<<' '<<result[(int)(result.size())-1];
		}
		
		cout<<endl;
	}
	return 0;
}