#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int base[9][9]; //row col
int data[9][9]; //curr input

bool isok(int rs,int re,int cs,int ce) {
	bool f[10]; //is found
	fill(f,f+10,false);

	for1(i,rs,re) {
		for1(j,cs,ce) {
			if (base[i][j]==0 || data[i][j]==base[i][j]) {
				f[data[i][j]] = true;
			} else {
				return false;
			}
		}
	}

	for1(i,1,10) {
		if (!f[i]) return false;
	}
	return true;
}

bool rowok(int i) {
	bool f[10]; //is found
	fill(f,f+10,false);

	for1(j,0,9) {
		if (base[i][j]==0 || data[i][j]==base[i][j]) {
			f[data[i][j]] = true;
		} else {
			return false;
		}
	}

	for1(x,1,10) {
		if (!f[x]) return false;
	}
	return true;
}

bool colok(int j) {
	bool f[10]; //is found
	fill(f,f+10,false);

	for1(i,0,9) {
		if (base[i][j]==0 || data[i][j]==base[i][j]) {
			f[data[i][j]] = true;
		} else {
			return false;
		}
	}

	for1(i,1,10) {
		if (!f[i]) return false;
	}
	return true;
}

int main() {
	int t; scanf("%d",&t);
	//in base
	for1(i,0,9) {
		for1(j,0,9) {
			scanf("%d",&base[i][j]);
		}
	}

	//in data
	for1(_t,0,t) {
		bool ok = true;

		for1(i,0,9) {
			for1(j,0,9) {
				scanf("%d",&data[i][j]);
			}
		}

		if(!isok(0,3,0,3)) ok=false;
		if(!isok(0,3,3,6)) ok=false;
		if(!isok(0,3,6,9)) ok=false;
		if(!isok(3,6,0,3)) ok=false;
		if(!isok(3,6,3,6)) ok=false;
		if(!isok(3,6,6,9)) ok=false;
		if(!isok(6,9,0,3)) ok=false;
		if(!isok(6,9,3,6)) ok=false;
		if(!isok(6,9,6,9)) ok=false;

		for1(i,0,9)	{
			if(!rowok(i)) ok=false;
			if(!colok(i)) ok=false;
		}

		/*cout<<endl;
		for1(i,0,9) {
			for1(j,0,9) {
				cout<<base[i][j]<<' ';
			}
			cout<<endl;
		}*/

		if (ok) cout<<_t+1<<endl;
	}

	cout<<"END"<<endl;

	return 0;
}
