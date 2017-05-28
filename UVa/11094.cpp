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
    while(cin>>nr>>nc) {
        string data[nr];
        for1(i,0,nr) {
            cin>>data[i];
        }
        int lr,lc; cin>>lr>>lc;
        char l = data[lr][lc];
        int currmap = 0;

        vector<vector<int>> gid(nr,vector<int>(nc,-1));

        for1(sr,0,nr) {
            for1(sc,0,nc) {
                if (data[sr][sc]==l && gid[sr][sc]==-1) {
                    queue<pii> q;
                    q.push(mp(sr,sc));
                    gid[sr][sc] = currmap;
                    while (!q.empty()) {
                        int cr = q.front().first;
                        int cc = q.front().second;
                        q.pop();
                        int dr[] = {0,0,1,-1};
                        int dc[] = {1,-1,0,0};
                        for1(i,0,4) {
                            int ner = cr+dr[i];
                            int nec = cc+dc[i];
                            if (nec>=nc) {
                                nec = 0;
                            } else if (nec<0) {
                                nec = nc-1;
                            }
                            if (ner>=0&&ner<nr&&nec>=0&&nec<nc&&gid[ner][nec]==-1&&data[ner][nec]==l) {
                                gid[ner][nec] = currmap;
                                q.push(mp(ner,nec));
                            }
                        }
                    }

                    currmap++;
                }
            }
        }

        vector<int> gcount(currmap,0);
        for1(i,0,nr) {
            for1(j,0,nc) {
                if (gid[i][j]!=-1 && gid[i][j]!=gid[lr][lc]) {
                    gcount[gid[i][j]]++;
                }
            }
        }

        int currmax = 0;

        for1(i,0,currmap) {
            currmax = max(currmax,gcount[i]);
        }

        cout<<currmax<<endl;
    }

	return 0;
}
