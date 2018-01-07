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
typedef pair<pair<int,int>,pair<int,int>> piiii;
typedef vector<int> vi;

int nr,nc;
int data[1005][1005];
int dist[1005][1005][3];



int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>nr>>nc;
    for1(i,0,nr) for1(j,0,nc) scanf("%d",&data[i][j]);

    for1(i,0,1005) for1(j,0,1005) for1(k,0,3) dist[i][j][k] = -1E9;
    priority_queue<piiii> pq;
    pq.push({{0,0},{0,0}});
    pq.push({{data[0][0],1},{0,0}});
    dist[0][0][0] = 0;
    dist[0][0][1] = data[0][0];
    while (!pq.empty()) {
        int cr = pq.top().second.first;
        int cc = pq.top().second.second;
        int ce = pq.top().first.second;
        pq.pop();

        int dr[] = {0,1};
        int dc[] = {1,0};
        for1(i,0,2) {
            int ner = cr+dr[i];
            int nec = cc+dc[i];

            if (ner<0 || nec<0 || ner>=nr || nec>=nc) continue;
            int w = data[ner][nec];
            if (ce<2) {
                if (dist[cr][cc][ce]+w>dist[ner][nec][ce+1]) {
                    dist[ner][nec][ce+1] = dist[cr][cc][ce]+w;
                    pq.push({{dist[ner][nec][ce+1],ce+1},{ner,nec}});
                }
            }

            if (dist[cr][cc][ce]>dist[ner][nec][0]) {
                dist[ner][nec][0] = dist[cr][cc][ce];
                pq.push({{dist[ner][nec][0],0},{ner,nec}});
            }
        }
    }

    cout<<*max_element(dist[nr-1][nc-1],dist[nr-1][nc-1]+3);
	return 0;
}
