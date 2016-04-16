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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t;
	for (int _t=1;_t<=t;_t++) {
		int n; cin>>n;
		vector<int> data(n);
		//vector< vector<int> > re(n);
		for1(i,0,n) {
			cin>>data[i];
			data[i]--;
			//re[data[i]].push_back(i);
		}
		//debugv1(data);
		int maxcount = 0;
		for1(i,0,n) {
			vector<bool> selected(n,false);
			selected[i] = true;
			int j = i;
			int count = 1;
			while (true) {
				bool end = true;
				if (!selected[data[j]]) {
					count++;
					selected[data[j]] = true;
					end = false;
					j = data[j]; continue;
				}
				
				for1(k,0,n) {
					if (!selected[k] && data[k]==j) {
						cout<<i<<' '<<k<<endl;
						count++;
						selected[k] = true;
						end = false;
						j = k; break;
					}
				}
				
				/*for1(k,0,re[data[j]].size()) {
					if (!selected[data[re[data[j]][k]]]) {
						count++;
						selected[data[re[data[j]][k]]] = true;
						end = false;
						j = re[data[j]][k]; break;
					}
				}*/
				
				if(end) break;
			}
			//last = j first = i
			if (data[j]==i) {
			
				maxcount = max(maxcount,count);
			}
		}
		cout<<"Case #"<<_t<<": "<<maxcount<<endl;
	}
	return 0;
}