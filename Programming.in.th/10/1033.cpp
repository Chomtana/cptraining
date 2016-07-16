#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

struct rc {
	int r,c;

	bool operator == (rc x) {
		return this->r==x.r && this->c==x.c;
	}
};

int main() {
	int n; scanf("%d",&n); int k; scanf("%d",&k);

	int data[n][n];
	rc pos[4];

	for1(i,0,n) {
		for1(j,0,n) {
			data[i][j] = -1;
		}
	}

	data[0][0]=3;
	data[n-1][0]=2;
	data[0][n-1]=0;
	data[n-1][n-1]=1;

	pos[3].r=0;pos[3].c=0;
	pos[2].r=n-1;pos[2].c=0;
	pos[0].r=0;pos[0].c=n-1;
	pos[1].r=n-1;pos[1].c=n-1;

	char move[4][k];

	for1(p,0,4) {
		for1(j,0,k) {
			char c; scanf(" %c",&c);
			move[p][j] = c;
		}
	}

	//process 00 10 20 30 01 11 21 31
	for1(j,0,k) {
		for1(p,0,4) {
			rc newp;
			newp.r=pos[p].r;
			newp.c=pos[p].c;

			switch (move[p][j]) {
				case 'N': newp.r--; break;
				case 'E': newp.c++; break;
				case 'S': newp.r++; break;
				case 'W': newp.c--; break;
			}

			//isok
			bool ok = true;
			if (newp.r<0 || newp.r>=n || newp.c<0 || newp.c>=n) ok=false;
			if (newp==pos[0] || newp==pos[1] || newp==pos[2] || newp==pos[3]) ok = false;

			//cout<<move[p][j]<<endl;

			if (ok) {
				pos[p].r=newp.r;
				pos[p].c=newp.c;
				data[newp.r][newp.c] = p;
			}
		}
	}

	int count[4];
	for1(i,0,4) count[i]=0;

	for1(i,0,n) {
		for1(j,0,n) {
			//cout<<data[i][j]<<' ';
			count[data[i][j]]++;
			if (data[i][j]==-1) {
				printf("No");
				return 0;
			}
		}
		//cout<<endl;
	}

	int maxcount = max(count[0],max(count[1],max(count[2],count[3])));

	vector<int> pres;
	if (maxcount==count[0]) pres.push_back(1);
	if (maxcount==count[1]) pres.push_back(2);
	if (maxcount==count[2]) pres.push_back(3);
	if (maxcount==count[3]) pres.push_back(4);

	printf("%d %d\n",pres.size(),maxcount);
	for1(i,0,pres.size()) {
		printf("%d\n", pres[i]);
	}

	return 0;
}
