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
typedef pair<int,pii> piii;
typedef vector<int> vi;

int n,k;
int cost[10];
vector<vector<int>> data;
vector<vector<vector<piii>>> E;
bool have[6][105];
//int Al[6][105][6][105];
int dist[6][105];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	while(cin>>n>>k) {
		memset(have,false,sizeof(have));
		
		data.resize(n);
		E.resize(n,vector<vector<piii>>(105));
		//Al.resize(100,vector<int>(100));
		//for1(i,0,n) for1(j,0,105) for1(k,0,n) for1(l,0,105) Al[i][j][k][l] = 1E9;
		for1(i,0,n) {
			scanf("%d",cost+i);
		}
		
		//cerr<<"bbb\n";
		
		cin.ignore();
		
		for1(i,0,n) {
			string raw;
			getline(cin,raw);
			stringstream ss(raw);
			int x;
			while (ss>>x) {
				data[i].push_back(x);
				have[i][x] = true;
			}
			
			for1(j,0,data[i].size()) {
				for1(k,j+1,data[i].size()) {
					int w = abs(data[i][k]-data[i][j])*cost[i];
					/*Al[i][j][i][k] = min(Al[i][j][i][k],abs(data[k]-data[j])+1);
					Al[i][k][i][j] = min(Al[k][j],abs(data[k]-data[j])+1);*/
					E[i][data[i][j]].push_back(mp(w,mp(i,data[i][k])));
					E[i][data[i][k]].push_back(mp(w,mp(i,data[i][j])));
				}
			}
			
			//cerr<<"aaa"<<endl;
			

		}
		
		//cerr<<"aaa"<<endl;
		
		for1(i,0,n) {
			for1(j,i+1,n) {
				for1(k,0,105) {
					if (have[i][k] && have[j][k]) {
						E[i][k].push_back(mp(60,mp(j,k)));
						E[j][k].push_back(mp(60,mp(i,k)));
					}
				}
			}
		}
		
		int mindist = 1E9;
		
		for1(se,0,n) {
			for1(ee,0,n) {
				
				if (!have[se][0] || !have[ee][k]) continue;
				for1(i,0,6) for1(j,0,105) dist[i][j] = 1E9;
				dist[se][0] = 0;
				priority_queue<piii,vector<piii>,greater<piii>> q;
				q.push(mp(0,mp(se,0)));
				while (!q.empty()) {
					int ce = q.top().second.first;
					int cf = q.top().second.second;
					int cw = q.top().first;
					//cerr<<se<<' '<<ee<<' '<<ce<<' '<<cf<<' '<<cw<<endl;
					q.pop();
					
					for1(i,0,E[ce][cf].size()) {
						int ne = E[ce][cf][i].second.first;
						int nf = E[ce][cf][i].second.second;
						int w = E[ce][cf][i].first;
						
						if (dist[ce][cf]+w<dist[ne][nf]) {
							dist[ne][nf] = dist[ce][cf]+w;
							q.push(mp(dist[ne][nf],mp(ne,nf)));
						}
					}
				}
				mindist = min(mindist,dist[ee][k]);
			}
		}
		
		if (mindist>=1E9) cout<<"IMPOSSIBLE\n"; else
		cout<<mindist<<endl;
		/*for1(i,0,E[1][30].size()) {
			cerr<<E[1][30][i].second.first<<' '<<E[1][30][i].second.second<<' '<<E[1][30][i].first<<endl;
		}*/
		
		data.clear();
		E.clear();
		//Al.clear();
	}
	
	return 0;
}
