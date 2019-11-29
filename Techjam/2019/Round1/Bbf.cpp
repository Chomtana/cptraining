#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
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
#define until(x) while(!x)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int k,m;
vector<int> data;
vector<vector<int>> pos;

/*bool check() {
	for1(i,1,k+1) {
		if (pos[i].size() >= 2) {
			for1(j,0,pos[i].size()) {
				int s = pos[i][j];
				for1(jj,j+1,pos[i].size()) {
					int e = pos[i][jj];

					set<int> contains;
					for1(k,s+1,e) {
						contains.insert(data[k]);
					}

					for1(k,0,s) {
						if (contains.find(data[k]) != contains.end()) {
							return false;
						}
					}

					for1(k,e+1,data.size()) {
						if (contains.find(data[k]) != contains.end()) {
							return false;
						}
					}
				}
			}
		}
	}

	return true;
}*/

bool check() {
	for1(i1,0,data.size()) {
		for1(i2,i1+1,data.size()) {
			for1(i3,i2+1,data.size()) {
				for1(i4,i3+1,data.size()) {
					if (data[i1] == data[i3] && data[i2] == data[i4]) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
	cin >> k >> m;
	pos.resize(k+5);
	for1(i,0,m) {
		int x; scanf("%d", &x);
		data.push_back(x);
		pos[x].push_back(i);
	}

	

	int hassump = -1;

	while (true) {
		bool alive = false;

		for1(ins,1,k+1) {
			if (ins == data[data.size() -1]) continue;

			vector<int> inspos;
			int inscount = pos[ins].size();

			pos[ins].push_back(data.size());
			data.push_back(ins);
			
			if (check()) {
				alive = true;
				break;
			}

			pos[ins].pop_back();
			data.pop_back();

			/*for1(i,0,data.size()) {
				if (data[i] == ins) {
					inscount++;
					inspos.push_back(i);
				}
			}*/

			/*if (inscount == 0) {
				pos[ins].push_back(data.size());
				data.push_back(ins);
				alive = true;
				break;
			}

			if (inscount == 1) {
				bool mebetween = false;
				for1(i,1,k+1) {
					for1(j,1,pos[i].size()) {
						for1(k,0,pos[ins].size()) {
							if (pos[i][j-1] < pos[ins][k] && pos[ins][k] < pos[i][j]) {
								mebetween = true;
							}
						}
					}

					if (mebetween) break;
				}

				if (!mebetween) {
					pos[ins].push_back(data.size());
					data.push_back(ins);
					alive = true;
					break;
				}
			}

			if (inscount == 2) {
				bool allunique = true;
				for(int i = data.size() - 1;i>=0;i--) {
					if (data[i] == ins) break;

					if (pos[data[i]].size() > 1) {
						allunique = false;
						break;
					}
				}

				if (allunique) {
					pos[ins].push_back(data.size());
					data.push_back(ins);
					alive = true;
					break;
				}
			}*/
		}

		if (!alive) break;
	}

	cout<<data.size()<<endl;
	for1(i,0,data.size()) {
		printf("%d\n",data[i]);
	}
	return 0;
}

/*
5 5
1
3
5
2
3
*/