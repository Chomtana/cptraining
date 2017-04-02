#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int currmap = 1000;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int nr,nc; scanf("%d %d",&nc,&nr);
    char dataraw[nr][nc];
    for1(i,0,nr) scanf("%s",dataraw[i]);

    int data[nr][nc];
    bool visited[nr][nc];

    for1(i,0,nr) for1(j,0,nc) {
        visited[i][j] = false;
        data[i][j] = dataraw[i][j];
    }

    for1(i,0,nr) {
        for1(j,0,nc) {
            if (dataraw[i][j]=='P' && !visited[i][j]) {
                queue<pii> q;
                q.push(mp(i,j));
                visited[i][j] = true;
                while (!q.empty()) {
                    int currr = q.front().first;
                    int currc = q.front().second;
                    q.pop();

                    data[currr][currc] = currmap;

                    int dr [] = {0,0,1,-1};
                    int dc [] = {1,-1,0,0};
                    for1(i,0,4) {
                        int nextr = currr + dr[i];
                        int nextc = currc + dc[i];

                        if (nextr>=0 && nextr<nr && nextc>=0 && nextc<nc && !visited[nextr][nextc] && data[nextr][nextc]=='P') {
                            q.push(mp(nextr,nextc));
                            visited[nextr][nextc] = true;

                        }
                    }

                }

                currmap++;
            }
        }
    }

    /*for1(i,0,nr) {
        for1(j,0,nc) {
            cout<<data[i][j]<<' ';
        }
        cout<<endl;
    }*/


    int water[min(nr,nc)+1][nr][nc];
    bool possible[min(nr,nc)+1][nr][nc];
    int maxsize = 0;
    int minpool[min(nr,nc)+1];

    for1(i,0,min(nr,nc)+1) {
        minpool[i] = 1E9;
    }

    for1(size,1,min(nr,nc)+1) {
        for1(i,0,nr-size+1) {

            set<pii> tpos;
            map<int,int> poolcount;

            for1(j,0,nc-size+1) {
                possible[size][i][j] = true;
                water[size][i][j] = 0;
            }
            //if (i==0) {
                //int wcount = 0;
                for1(a,i,i+size) {
                    for1(b,i,i+size) {
                        //water[size][i][0] += (data[a][b]=='P');
                        if (data[a][b]>=1000) {
                            poolcount[data[a][b]]++;
                        }
                        if (data[a][b] == 'T') {
                            //possible[size][i][0] = false;
                            tpos.insert(mp(a,b));
                        }
                    }
                }

            /*} else {
                water[size][i][0] = water[size][i-1][0];
                for1(a,0,size) {
                    water[size][i][0] -= (data[i-1][a]=='P');
                    water[size][i][0] += (data[i+size-1][a]=='P');
                    if (data[i-1][a]=='T') {
                        tpos.erase(mp(i-1,a));
                    }
                    if (data[i+size-1][a]=='T') {
                        tpos.insert(mp(i+size-1,a));
                    }
                }
            }*/

            if (tpos.size()==0) {
                //set max size
                //set min pool count
                maxsize = max(maxsize,size);
                int pool = 0;
                for(auto it = poolcount.begin();it!=poolcount.end();it++) {
                    if (it->second != 0) pool++;
                }
                minpool[size] = min(minpool[size],pool);
            }

            for1(j,1,nc-size+1) {
                water[size][i][j] = water[size][i][j-1];
                for1(a,0,size) {
                    //water[size][i][j] -= (data[a+i][j-1]=='P');
                    if (data[a+i][j-1] >= 1000) {
                        poolcount[data[a+i][j-1]]--;
                    }
                    //water[size][i][j] += (data[a+i][j+size-1]=='P');
                    if (data[a+i][j+size-1] >= 1000) {
                        poolcount[data[a+i][j+size-1]]++;
                    }
                    if (data[a+i][j-1]=='T') {
                        tpos.erase(mp(a+i,j-1));
                    }
                    if (data[a+i][j+size-1]=='T') {
                        tpos.insert(mp(a+i,j+size-1));
                    }
                }

                /*if (size==4 && i==0 && j==1) {
                    cout<<tpos.size()<<' '<<"aaa"<<endl;
                    for(auto it = tpos.begin();it!=tpos.end();it++) {
                        cout<<'('<<it->first<<','<<it->second<<')';
                    }
                    cout<<endl;
                }*/

                if (tpos.size()==0) {
                    //set max size
                    //set min pool count
                    maxsize = max(maxsize,size);
                    int pool = 0;
                    for(auto it = poolcount.begin();it!=poolcount.end();it++) {
                        if (it->second != 0) pool++;
                    }
                    minpool[size] = min(minpool[size],pool);
                }
            }
        }
    }

    if (maxsize == 0) {
        cout<<"0 0"; return 0;
    }

    cout<<maxsize*maxsize<<' '<<minpool[maxsize];

	return 0;
}
