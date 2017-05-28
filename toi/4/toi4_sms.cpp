#include <stdio.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

#define macro1(a,b,x) if(s==a) {r=b; c=x;}
#define ifrc(a,b) if(r==a && c==b)

char res[1000];
int currptr = 0;

void del(int m) {
	while (m--) {
		if (currptr==0) break;
		res[currptr-1] = 0;
		currptr--;
	}
}

void process(int r,int c,int m) {
	ifrc(0,0) {
		del(m);
	} else {
		m--;
		ifrc(0,1) {
			m %= 3;
			res[currptr] = 'A'+m;
		} else ifrc(0,2) {
			m%=3;
			res[currptr] = 'D'+m;
		} else ifrc(1,0) {
			m%=3;
			res[currptr] ='G'+m;
		} else ifrc(1,1) {
			m%=3;
			res[currptr] = 'J'+m;
		} else ifrc(1,2) {
			m%=3;
			res[currptr] = 'M'+m;
		} else ifrc(2,0) {
			m%=4;
			res[currptr] = 'P'+m;
		} else ifrc(2,1) {
			m%=3;
			res[currptr] = 'T'+m;
		} else ifrc(2,2) {
			m%=4;
			res[currptr] = 'W'+m;
		} else {
			currptr--;
		}
		currptr++;
	}
}

int main() {
	int n,s,sm; scanf("%d %d %d",&n,&s,&sm);
	int r,c;
	macro1(1,0,0);
	macro1(2,0,1);
	macro1(3,0,2);
	macro1(4,1,0);
	macro1(5,1,1);
	macro1(6,1,2);
	macro1(7,2,0);
	macro1(8,2,1);
	macro1(9,2,2);

	process(r,c,sm);

	n--;
	while(n--) {
		int dc,dr,m; scanf("%d %d %d",&dc,&dr,&m);
		r = r+dr;
		c = c+dc;

		process(r,c,m);
	}
	if (currptr == 0) {
		printf("null");
	} else {
		printf("%s",res);
	}
	return 0;
}

/*
6
5 3
1 0 3
-1 1 3
1 -2 2
-2 0 2
1 0 1
*/
