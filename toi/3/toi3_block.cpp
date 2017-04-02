#include <stdio.h>
#include <queue>
#define for1(a,b,c) for((a)=(b);(a)<(c);(a)++)
#define for2(a,b,c) for((a)=(b);((b)<(c)?(a)<=(c):(a)>=(c));(a)+=((b)<(c)?1:-1))
#define bool int
#define true 1
#define false 0
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int nr,nc;
char data[10][10];
int score = 0;

int countbomb(int sr,int sc) {
	int i,j;
	char temp = data[sr][sc];
	if (data[sr][sc]=='-' or data[sr][sc] =='#') return 0;
	int bombcount=0;
	bool visited[10][10];
	for1(i,0,10) for1(j,0,10) visited[i][j]=false;
	queue<pii> q;
	q.push(mp(sr,sc));
	visited[sr][sc] = true;
	while(!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		data[r][c] = '-';
		bombcount++;
		score+=5;
		int dr[] = {0,0,1,-1};
		int dc[] = {1,-1,0,0};
		for1(i,0,4) {
			int nextr = r+dr[i];
			int nextc = c+dc[i];
			if (!visited[nextr][nextc] && data[nextr][nextc]==temp) {
				q.push(mp(nextr,nextc));
				visited[nextr][nextc] = true;
			}
		}
	}

	if (bombcount<=1) {
		data[sr][sc] = temp;
		score-=5;
		return 0;
	}

	return bombcount;
}

void makedown() {
    int i,j,r,c;
    for2(r,nr,1) {
        for1(c,1,nc+1) {
            if (data[r][c] != '#' && data[r][c]!='-') {
                for1(i,r+1,nr+1) {
                    if (data[i][c]=='-') {
                        data[i][c] = data[i-1][c];
                        data[i-1][c] = '-';
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

int bombtest(int r,int c,char x) {
    int i,j;
	int res = 0;
	if (data[r][c]!=x) return 0;
    bool del = false;
    if (data[r][c] == data[r][c-1]) {
        del = true;
        res++;
        //score += 5;
        //data[r][c-1] = '-';
    }
    if (data[r][c] == data[r][c+1]) {
        del = true;
        res++;
        //score += 5;
        //data[r][c+1] = '-';
    }
    if (data[r][c] == data[r-1][c]) {
        del = true;
        res++;
        //score += 5;
        //data[r-1][c] = '-';
    }
    if (data[r][c] == data[r+1][c]) {
        del = true;
        res++;
        //score += 5;
        //data[r+1][c] = '-';
    }

    if (del) {
        //data[r][c] = '-';
        //score += 5;
        res++;
        //hasdel = true;
        return res;
    } else return 0;
}

bool makedel() {
    int i,j,r,c;
    bool hasdel = false;
    for1(r,1,nr+1) {
        for1(c,1,nc+1) {
            if (data[r][c]!='-' && data[r][c]!='#') if(countbomb(r,c)!=0) hasdel=true;
        }
    }
    return hasdel;
}

int main() {
     scanf("%d %d ",&nr,&nc);

    int i,j,k;
    for1(i,0,nr+2) {
        for1(j,0,nc+2) {
            data[i][j] = '#';
        }
    }
    for1(i,1,nr+1) {
        for1(j,1,nc+1) {
            scanf("%c ",&data[i][j]);
        }
    }

    makedown();


    int t; scanf("%d",&t); while(t--) {
        int r,c; char op; scanf("%d %d %c",&r,&c,&op);
        //printf("%d %d %c\n",r,c,op);
        r++; c++;
        if (data[r][c]=='#' || data[r][c]=='-') {
            score -= 5;
            continue;
        }
        switch (op) {
        case 'L': {
            if (data[r][c-1]!='-') {
                score -= 5;
                continue;
            }
            data[r][c-1] = data[r][c];
            data[r][c] = '-';
			while(makedown(),makedel());

        }
            break;
        case 'R': {
            if (data[r][c+1]!='-') {
                score -= 5;
                continue;
            }
            data[r][c+1] = data[r][c];
            data[r][c] = '-';
			while(makedown(),makedel());
        }
            break;
        }
        makedown();
    }

    printf("%d\n",score);
    for1(i,1,nr+1) {
        for1(j,1,nc+1) {
            printf("%c ",data[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
4 5
# A - - #
# # - B #
# A B # #
# # # # #
2
1 3 L
0 1 R
*/
