#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

vector< vector<int> > resarr;
int resscanner[8];

void bt(int col) {
	if (col>=8) {
		resarr.push_back(vector<int>(8));
		copy(resscanner,resscanner+8,resarr[resarr.size()-1].begin());
		return;
	}
	for1(i,0,8) {
		resscanner[col]=i;

		bool ok = true;
		bool found[8];
		for1(j,0,8) found[j]=false;
		for1(j,0,col+1) {
			if (found[resscanner[j]]) {
				ok = false;
				break;
			}
			found[resscanner[j]] = true;
		}
		for1(j,0,col+1) {
			for1(k,1,j+1) {
				if (abs(resscanner[j]-resscanner[j-k])==k) {
					ok = false;
					break;
				}
			}
		}

		/*for1(j,0,8) cout<<resscanner[j]<<' ';
		cout<<endl;
		cout<<col<<' '<<ok<<endl;*/

		if (ok) {
			bt(col+1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	for1(i,0,8) resscanner[i]=0;
	bt(0);
	//cout<<resarr.size();
	/*for1(i,0,resarr.size()) {
		for1(j,0,resarr[i].size()) {
			cout<<resarr[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int t=1;;t++) {
		int data[8];
		for1(i,0,8) {if(!(cin>>data[i])) return 0; data[i]--;}
		//if (t!=1) cout<<endl;


		//check all possible result
		bool first = true;
		int res = 0;
		for1(i,0,resarr.size()) {
			int resc = 0;
			for1(j,0,8) {
				if (data[j]!=resarr[i][j]) {
					resc++;
				}
			}
			//cout<<resc<<endl;
			if (first) {
				res = resc;
				first = false;
			} else {
				res = min(res,resc);
			}
			/*if (resc==4) {
				for1(j,0,8) cout<<resarr[60][j]<<' ';
				cout<<endl;
			}*/
		}

		cout<<"Case "<<t<<": "<<res<<endl;
	}
	return 0;
}
