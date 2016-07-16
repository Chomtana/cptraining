#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)

using namespace std;

char data[8][8];

int main() {
	for1(i,0,8) {
		for1(j,0,8) {
			data[i][j] = '.';
		}
	}
	data[3][3]='O';
	data[3][4]='X';
	data[4][3]='X';
	data[4][4]='O';

	bool Xturn = true;
	int t; cin>>t; while (t--) {
		char _c; int r; cin>>_c>>r; r--;
		int c = _c-'a';

		char xc = (Xturn?'O':'X'); //inverse of data[r][c]
		data[r][c] = (Xturn?'X':'O');

		//check rule
		if (
			(r-1>=0 && data[r-1][c]!=xc)&&
			(r+1<8 && data[r+1][c]!=xc)&&
			(c-1>=0 && data[r][c-1]!=xc)&&
			(c+1<8 && data[r][c+1]!=xc)&&
			(r-1>=0 && c-1>=0 && data[r-1][c-1]!=xc)&&
			(r+1<8 && c-1>=0 && data[r+1][c-1]!=xc)&&
			(r-1>=0 && c+1<8 && data[r-1][c+1]!=xc)&&
			(r+1<8 && c+1<8 && data[r+1][c+1]!=xc)
		) continue;

		//check
		for1(i,r+1,8) {
			if (data[i][c]=='.') break;
			if (data[i][c]==data[r][c]) {
				for1(j,r+1,i) {
					data[j][c]=data[r][c];
				}
				break;
			}
		}
		for2(i,r-1,0) {
			if (data[i][c]=='.') break;
			if (data[i][c]==data[r][c]) {
				for2(j,r-1,i) {
					data[j][c]=data[r][c];
				}
				break;
			}
		}
		for2(i,c-1,0) {
			if (data[r][i]=='.') break;
			if (data[r][i]==data[r][c]) {
				for2(j,c-1,i) {
					data[r][j]=data[r][c];
				}
				break;
			}
		}
		for1(i,c+1,8) {
			if (data[r][i]=='.') break;
			if (data[r][i]==data[r][c]) {
				for1(j,c+1,i) {
					data[r][j]=data[r][c];
				}
				break;
			}
		}
		for1(i,1,8) {
			if (r+i>=8 || c+i>=8) break;
			if (data[r+i][c+i]=='.') break;
			if (data[r+i][c+i]==data[r][c]) {
				for1(j,1,i) {
					data[r+j][c+j]=data[r][c];
				}
				break;
			}
		}
		for1(i,1,8) {
			if (r-i<0 || c-i<0) break;
			if (data[r-i][c-i]=='.') break;
			if (data[r-i][c-i]==data[r][c]) {
				for1(j,1,i) {
					data[r-j][c-j]=data[r][c];
				}
				break;
			}
		}
		for1(i,1,8) {
			if (r+i>=8 || c-i<0) break;
			if (data[r+i][c-i]=='.') break;
			if (data[r+i][c-i]==data[r][c]) {
				for1(j,1,i) {
					data[r+j][c-j]=data[r][c];
				}
				break;
			}
		}
		for1(i,1,8) {
			if (r-i<0 || c+i>=8) break;
			if (data[r-i][c+i]=='.') break;
			if (data[r-i][c+i]==data[r][c]) {
				for1(j,1,i) {
					data[r-j][c+j]=data[r][c];
				}
				break;
			}
		}

		Xturn = !Xturn;
	}

	for1(i,0,8) {
		for1(j,0,8){
			cout<<data[i][j];
		}
		cout<<endl;
	}
	return 0;
}
