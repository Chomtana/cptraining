//very strange : pq faster than q

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
typedef pair<pii,pii> piiii;
typedef pair<int,piiii> piiiii;
typedef vector<int> vi;

int nr,nc,sr;
vector<string> data;
vector<vector<int>> dist[3]; //0 -> , 1 v , 2 ^

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    cin>>nr>>nc>>sr; sr--;
    data.resize(nr);
    cin.ignore();
    for1(i,0,nr) {
        getline(cin,data[i]);
    }
    
    dist[0].resize(nr,vector<int>(nc,1E9));
    dist[1].resize(nr,vector<int>(nc,1E9));
    dist[2].resize(nr,vector<int>(nc,1E9));
    
    queue<piiii/*,vector<piiii>,greater<piiii>*/> q;
    q.push({{0,0},{sr,0}});
    dist[0][sr][0] = 0;
    while (!q.empty()) {
        int cr = q.front().second.first;
        int cc = q.front().second.second;
        int dir = q.front().first.second;
        q.pop();
        
        //cerr<<cr<<' '<<cc<<endl;
        
        int dr[] = {0,1,-1};
        int dc[] = {1,0,0};
        for1(i,0,3) {
            int ner = cr+dr[i];
            int nec = cc+dc[i];
            if (ner>=0 && ner<nr && nec>=0 && nec<nc && data[ner][nec]=='.') {
                int newdist = dist[dir][cr][cc];
                int newdir = 0;
                if (dir==0) {
                    if (ner==cr-1 || ner==cr+1) newdist++;
                } else {
                    if (ner==cr) newdist++;
                }
                if (ner==cr && nec==cc+1) newdir = 0;
                else if (ner==cr-1 && nec==cc) newdir = 2;
                else if (ner==cr+1 && nec==cc) newdir = 1;
                if (newdist<dist[newdir][ner][nec]) {
                    dist[newdir][ner][nec] = newdist;
                    q.push({{dist[newdir][ner][nec],newdir},{ner,nec}});
                }
            }
        }
    }
    
    int res = 1e9;
    for1(i,0,nr) {
        for1(j,0,3) {
            res = min(res,dist[j][i][nc-1]);
        }
    }
    if (res!=1e9) cout<<res; else cout<<-1;
    return 0;
}
