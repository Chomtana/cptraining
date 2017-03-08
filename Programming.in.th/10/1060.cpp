#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;
	int maxh = 0;
	int maxc = 0;
	vector< pair<int,int> > data;
	for1(i,0,n) {
        int s,h; cin>>s>>h;
        s--;
        maxh = max(maxh,h);
        maxc = max(maxc,s+2*h);
        data.push_back(mp(s,h));
	}
	sort(all(data));

	vector< vector<char> > res(20,vector<char>(100,'.'));
	for1(i,0,data.size()) {
        int s = data[i].first;
        int h = data[i].second;
        for (int c = s,nc = h-1,r = 0;nc>=0;c++,nc--,r++) {
            if (res[19-r][c] == '.') {
                res[19-r][c] = '/';
            } else if (res[19-r][c] == '\\') {
                res[19-r][c] = 'v';
            }
            for1(j,0,2*nc) {
                res[19-r][c+j+1] = 'X';
            }
            if (res[19-r][c+2*nc+1] == '.') {
                res[19-r][c+2*nc+1] = '\\';
            } else if (res[19-r][c+2*nc+1] == '/') {
                res[19-r][c+2*nc+1] = 'v';
            }
        }
	}

	for1(i,0,maxh) {
	    for1(j,0,maxc) {
            cout<<res[20-(maxh-i)][j];
	    }
	    cout<<endl;
	}
	return 0;
}
