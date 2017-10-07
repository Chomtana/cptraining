/**
queue and custom efficiency is super almost same
*/

#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> type;
typedef vector<int> vi;

int nr,nc;
int data[105][105];
//unordered_map<int,bool> dist[105][105];
bool dist[105][105][5005];

int bfs() {
    int dre[] = {-1,-1,0,0,1,1};
    int dce[] = {0,1,-1,1,0,1};
    int dro[] = {-1,-1,0,0,1,1};
    int dco[] = {-1,0,-1,1,-1,0};

    //if multistart -> push all to queue -> set all dist to start dist (in this case start 1 not 0 -> can use 0 as null)
    queue<type> q;
    if (data[(nr-1)/2-1][0]!=0 && 1%data[(nr-1)/2-1][0]==0) q.push(mp(mp((nr-1)/2-1,0),1));
    if (data[(nr-1)/2][0]!=0 && 1%data[(nr-1)/2][0]==0) q.push(mp(mp((nr-1)/2,0),1));
    if (data[(nr-1)/2+1][0]!=0 && 1%data[(nr-1)/2+1][0]==0) q.push(mp(mp((nr-1)/2+1,0),1));
    if (data[(nr-1)/2-1][0]!=0 && 1%data[(nr-1)/2-1][0]==0) dist[(nr-1)/2-1][0][1] = 1;
    if (data[(nr-1)/2][0]!=0 && 1%data[(nr-1)/2][0]==0) dist[(nr-1)/2][0][1] = 1;
    if (data[(nr-1)/2+1][0]!=0 && 1%data[(nr-1)/2+1][0]==0) dist[(nr-1)/2+1][0][1] = 1;
    while(!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int ck = q.front().second;
        q.pop();

        if(cr==(nr-1)/2&&cc==nc-1) return ck; //law of bfs -> run first time = shortest path

        for1(i,0,6) {
            int ner = cr;
            int nec = cc;
            if ((cr&1)==0) {
                ner += dre[i];
                nec += dce[i];
            } else {
                ner += dro[i];
                nec += dco[i];
            }
            int nek = ck+1;
            if (ner>=0&&nec>=0&&ner<nr&&nec<nc) {
                if (data[ner][nec]!=0 && nek%data[ner][nec]==0)
                if (!dist[ner][nec][nek]) {
                    dist[ner][nec][nek] = true;
                    q.push(mp(mp(ner,nec),nek));
                }
            }
        }
    }
    return -1;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>nr>>nc;
    for1(i,0,nr) for1(j,0,nc) scanf("%d",&data[i][j]);
    cout<<bfs();
	return 0;
}
