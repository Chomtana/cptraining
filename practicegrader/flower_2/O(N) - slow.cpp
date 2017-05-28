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
typedef vector<int> vi;

class Hasher {
    public:
    size_t operator () (const pii &a) const {
        return a.first * a.second;
    }
};

pii data[1000001];
bool visitedr[1000001];
bool visitedc[1000001];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
        int n; scanf("%d",&n);
        vector<vector<int>> r2c(1000001);
        vector<vector<int>> c2r(1000001);

        /*for1(i,0,1000001) {
            visitedr[i] = false;
            visitedc[i] = false;
        }*/

        for1(i,0,n) {
            int r, c; scanf("%d %d",&r,&c);
            r2c[r].push_back(c);
            c2r[c].push_back(r);
            data[i] = mp(r,c);
            visitedr[r] = false;
            visitedc[c] = false;
        }

        int res = 0;

        subfunc(bool,visited,(int r,int c)) {
            return visitedr[r] || visitedc[c];
        };

        subfunc(void,bfs,(int sr,int sc)) {
            queue<pii> q;
            q.push(mp(sr,sc));
            while (!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                //cerr<<"DBG2 "<<r<<' '<<c<<endl;

                if (!visitedr[r]) {
                    for(int &nextc:r2c[r]) {
                        if (!visited(r,nextc) && nextc!=c) {
                            q.push(mp(r,nextc));
                        }
                    }
                }
                if (!visitedc[c]) {
                    for(int &nextr:c2r[c]) {
                        if (!visited(nextr,c) && nextr!=r) {
                            q.push(mp(nextr,c));
                        }
                    }
                }

                visitedr[r] = true;
                visitedc[c] = true;
            }
        };

        for1(i,0,n) {
            int r = data[i].first;
            int c = data[i].second;
            if (!visited(r,c)) {
                //cerr<<"DBG "<<r<<' '<<c<<endl;
                bfs(r,c);
                res++;
            }
        }

        //printf("DBG%d\n",res);
        printf("%d\n",(res%2==0?res/2:res/2+1));

    }
	return 0;
}
