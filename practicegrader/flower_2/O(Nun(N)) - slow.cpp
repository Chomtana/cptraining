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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
        int n; scanf("%d",&n);
        vector<vector<int>> r2c(1000001);
        vector<vector<int>> c2r(1000001);
        vector<pii> data(n);
        for1(i,0,n) {
            int r, c; scanf("%d %d",&r,&c);
            r2c[r].push_back(c);
            c2r[c].push_back(r);
            data[i] = mp(r,c);
        }

        int res = 0;

        unordered_set<pii,Hasher> visited(1000000);

        subfunc(void,bfs,(int sr,int sc)) {
            queue<pii> q;
            q.push(mp(sr,sc));
            visited.insert(mp(sr,sc));
            while (!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int &nextc:r2c[r]) {
                    if (visited.find(mp(r,nextc))==visited.end()) {
                        q.push(mp(r,nextc));
                        visited.insert(mp(r,nextc));
                    }
                }
                for(int &nextr:c2r[c]) {
                    if (visited.find(mp(nextr,c))==visited.end()) {
                        q.push(mp(nextr,c));
                        visited.insert(mp(nextr,c));
                    }
                }
            }
        };

        for1(i,0,n) {
            int r = data[i].first;
            int c = data[i].second;
            if (visited.find(mp(r,c))==visited.end()) {
                bfs(r,c);
                res++;
            }
        }

        printf("%d\n",(res%2==0?res/2:res/2+1));

    }
	return 0;
}
