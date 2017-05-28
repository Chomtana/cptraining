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

vector<vector<int>> W;
int n;

int mst() {
    int minw[n+5];
    bool visited[n+5];
    for1(i,0,n+5) {
        minw[i] = 1E9;
        visited[i] = false;
    }

    int c = 0;
    visited[c] = true;
    int res = 0;
    for1(_,0,n-1) {
        int currmin = 1E9;
        int mini = -1;
        for1(ne,0,n) {
            if (!visited[ne]) {
                if (W[c][ne]<minw[ne]) {
                    minw[ne] = W[c][ne];
                }
                if (minw[ne]<currmin) {
                    currmin = minw[ne];
                    mini = ne;
                }
            }
        }

        visited[mini] = true;
        c = mini;
        res += currmin;
    }

    return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    W.resize(n,vector<int>(n));
    for1(i,0,n-1) {
        for1(j,0,n-i-1) {
            int x; scanf("%d",&x);
            W[i][i+j+1] = x;
            W[i+j+1][i] = x;
        }
    }

    cout<<mst();
	return 0;
}
