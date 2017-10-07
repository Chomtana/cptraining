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
typedef vector<int> vi;

vector<vector<char>> correct(4,vector<char>(4));
map<vector<vector<char>>,int> dist;
int startraw[4][4];

pii find0(vector<vector<char>> &c) {
    for1(i,0,4) {
        for1(j,0,4) if(c[i][j]==0) return mp(i,j);
    }
}

int process() {
    vector<vector<char>> start(4,vector<char>(4));
    for1(i,0,4) for1(j,0,4) start[i][j] = startraw[i][j];
    dist[start] = 0;
    queue<vector<vector<char>>> q;
    q.push(start);
    while (!q.empty()) {
        vector<vector<char>> c = q.front();
        if (c==correct) return dist[c]; //bfs -> nae jai wa ta tum leaw tong dai dist te took
        pii crc = find0(c);
        int cr = crc.first;
        int cc = crc.second;
        q.pop();

        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};
        for1(i,0,4) {
            int ner = cr+dr[i];
            int nec = cc+dc[i];
            if (ner>=0&&nec>=0&&ner<4&&nec<4) {
                vector<vector<char>> ne(c);
                swap(ne[cr][cc],ne[ner][nec]);
                if (dist.find(ne)==dist.end()) {
                    dist[ne] = dist[c]+1;
                    q.push(ne);
                }
            }
        }

    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	correct[0][0] = 1;
	correct[0][1] = 2;
	correct[0][2] = 3;
	correct[0][3] = 4;
	correct[1][0] = 5;
	correct[1][1] = 6;
	correct[1][2] = 7;
	correct[1][3] = 8;
	correct[2][0] = 9;
	correct[2][1] = 10;
	correct[2][2] = 11;
	correct[2][3] = 12;
	correct[3][0] = 13;
	correct[3][1] = 14;
	correct[3][2] = 15;
	correct[3][3] = 0;

    for1(i,0,4) {
        for1(j,0,4) {
            scanf("%d",&startraw[i][j]);
        }
    }

    cout<<process();
	return 0;
}
