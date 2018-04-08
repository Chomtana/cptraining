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
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<vector<bool>> plottype;

int sr = 20;
int sc = 20;
int a;

plottype plot(105,vector<bool>(105,false));
vector<vi> plotprofit(105,vector<int>(105,9));

int calprofit(int r,int c) {
    int res = 0;
    for1(i,r-1,r+2) {
        for1(j,c-1,c+2) {
            if (!plot[i][j]) res++;
        }
    }
    return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t;
    while(t--) {
        cin>>a;
        cout<<sr+1<<' '<<sc+1<<endl;

        double _sz = sqrt((double)a);
        int sz = ceil(_sz);

        if (sz==1) continue;

        plot.clear();
        plotprofit.clear();
        plot.resize(105,vector<bool>(105,false));
        plotprofit.resize(105,vector<int>(105,9));

        while(true) {
            int r,c; cin>>r>>c;
            if (r==0 && c==0) {
                break;
            }
            if (r==-1 && c==-1) {
                return 0;
            }

            plot[r][c] = true;


            /*for1(i,sr,sr+sz) {
                for1(j,sc,sc+sz) {
                    cerr<<plot[i][j]<<' ';
                }
                cerr<<endl;
            }
            cerr<<endl;*/

            for1(i,r-1,r+2) {
                for1(j,c-1,c+2) {
                    if (i>sr && j>sc && i<sr+sz-1 && j<sc+sz-1) {
                        int profit = calprofit(i,j);
                        //cerr<<plot[i][j]<<' ';
                        plotprofit[i][j] = profit;
                    }
                }
                //cerr<<endl;
            }
            //cerr<<endl;

            /*for1(i,sr,sr+sz) {
                for1(j,sc,sc+sz) {
                    cerr<<plotprofit[i][j]<<' ';
                }
                cerr<<endl;
            }
            cerr<<endl;*/

            int maxprofit = -1;
            int maxi = -1;
            int maxj = -1;

            for1(i,sr+1,sr+sz-1) {
                for1(j,sc+1,sc+sz-1) {
                    if (plotprofit[i][j]>maxprofit) {
                        maxprofit = plotprofit[i][j];
                        maxi = i;
                        maxj = j;
                    }
                }
            }

            cout<<maxi<<' '<<maxj<<endl;
        }
    }
	return 0;
}
