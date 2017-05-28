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

bool data[500][500];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t = 2;
	while (t--) {
        int nr,nc; scanf("%d %d",&nr,&nc);
        int nt; scanf("%d",&nt);
        for1(i,0,500) {
            for1(j,0,500) {
                data[i][j] = false;
            }
        }

        while (nt--) {
            int r,c; scanf("%d %d",&r,&c);
            data[r][c] = true;
        }

        /*cout<<"DBG"<<endl;
        for1(i,0,nr) {
            for1(j,0,nc) {
                cout<<data[i][j];
            }
            cout<<endl;
        }*/

        //process
        int vertbar[nc];
        int horibar[nr];

        for(int l = min(nr,nc);l>=1;l--) {
            /*vertbar.clear();
            vertbar.resize(nc,0);
            horibar.clear();
            horibar.resize(nr,0);*/



            for1(j,0,nc) {
                vertbar[j] = 0;
                for1(i,0,l) {
                    vertbar[j] += data[i][j];
                }
            }
            for1(i,0,nr) {
                horibar[i] = 0;
                for1(j,0,l) {
                    horibar[i] += data[i][j];
                }
            }

            for1(i,0,nr-l+1) {
                int oldhoribar1 = horibar[i];
                int oldhoribar2 = horibar[i+l-1];
                bool vertvisited[nc];
                fill(vertvisited,vertvisited+nc,false);
                for1(j,0,nc-l+1) {
                    if (i>0) {
                        if (!vertvisited[j] && data[i-1][j]) vertbar[j]--;
                        if (!vertvisited[j+l-1] && j+l-1!=j && data[i-1][j+l-1]) vertbar[j+l-1]--;
                        if (!vertvisited[j] && data[i+l-1][j]) vertbar[j]++;
                        if (!vertvisited[j+l-1] && j+l-1!=j && data[i+l-1][j+l-1]) vertbar[j+l-1]++;
                        vertvisited[j] = true;
                        vertvisited[j+l-1] = true;
                    }
                    if (j>0) {
                        if (data[i][j-1]) horibar[i]--;
                        if (i+l-1!=i && data[i+l-1][j-1]) horibar[i+l-1]--;
                        if (data[i][j+l-1]) horibar[i]++;
                        if (i+l-1!=i && data[i+l-1][j+l-1]) horibar[i+l-1]++;
                    }
                    if (vertbar[j]==0 && vertbar[j+l-1]==0 && horibar[i]==0 && horibar[i+l-1]==0) {
                        cout<<l<<endl;
                        goto nextcase;
                    }
                }
                horibar[i] = oldhoribar1;
                horibar[i+l-1] = oldhoribar2;
            }
        }
        cout<<0<<endl;

        nextcase:
            //cerr<<"NC"<<endl;
            continue;
	}
	return 0;
}
