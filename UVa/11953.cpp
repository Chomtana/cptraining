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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc;
    int t; cin>>t;
    for1(_,1,t+1) {
        int n; cin>>n;
        nr = n; nc = n;
        string data[nr];
        for1(i,0,nr) {
            cin>>data[i];
        }
        int currmap = 0;

        vector<vector<int>> gid(nr,vector<int>(nc,-1));
        vector<bool> gdisable;

        for1(sr,0,nr) {
            for1(sc,0,nc) {
                if ((data[sr][sc]=='x'||data[sr][sc]=='@') && gid[sr][sc]==-1) {
                    bool disable = true;
                    queue<pii> q;
                    q.push(mp(sr,sc));
                    gid[sr][sc] = currmap;
                    while (!q.empty()) {
                        int cr = q.front().first;
                        int cc = q.front().second;
                        q.pop();
                        int dr[] = {0,0,1,-1};
                        int dc[] = {1,-1,0,0};
                        if (data[cr][cc]=='x') {
                            disable = false;
                        }
                        for1(i,0,4) {
                            int ner = cr+dr[i];
                            int nec = cc+dc[i];
                            if (ner>=0&&ner<nr&&nec>=0&&nec<nc&&gid[ner][nec]==-1&&(data[ner][nec]=='x'||data[ner][nec]=='@')) {
                                gid[ner][nec] = currmap;
                                q.push(mp(ner,nec));
                            }
                        }
                    }

                    currmap++;
                    gdisable.push_back(disable);
                }
            }
        }

        int res = 0;
        for1(i,0,currmap) {
            res += !gdisable[i];
        }

        cout<<"Case "<<_<<": "<<res<<endl;
    }

	return 0;
}
