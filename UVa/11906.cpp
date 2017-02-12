#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);((a)<(b)?(i)<(b):(i)>=(b));(i)+=((a)<(b)?1:-1))
#define for2(i,a,b) for(int (i)=(a);((a)<(b)?(i)<=(b):(i)>=(b));(i)+=((a)<(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int nr,nc;
int m,n;
vector< vector<ll> > res;
vector< vector<bool> > w;
vector< vector<bool> > instack;

int dfs(int r,int c) {
    instack[r][c] = true;
    instack[0][0] = false;

    int nextr,nextc;
    bool cando = true;
    bool hascando = false;

    // ^ ->
    cando = true;
    nextr = r-m;
    nextc = c+n;
    if (nextr>=0 && nextc>=0  && nextr<nr && nextc<nc) {
        for2(i,r,nextr) {
            if (w[i][c]) {
                cando = false;
                break;
            }
        }
        if (cando) {
            for2(i,c,nextc) {
                if (w[nextr][i]) {
                    cando = false;
                    break;
                }
            }
        }
        if (cando && !instack[nextr][nextc]) {
            res[nextr][nextc]++;
            res[nextr][nextc] += dfs(nextr,nextc);
            hascando = true;
        }
    }

    // v ->
    cando = true;
    nextr = r+m;
    nextc = c+n;
    if (nextr>=0 && nextc>=0  && nextr<nr && nextc<nc) {
        for2(i,r,nextr) {
            if (w[i][c]) {
                cando = false;
                break;
            }
        }
        if (cando) {
            for2(i,c,nextc) {
                if (w[nextr][i]) {
                    cando = false;
                    break;
                }
            }
        }
        if (cando && !instack[nextr][nextc]) {
            res[nextr][nextc]++;
            res[nextr][nextc] += dfs(nextr,nextc);
            hascando = true;
        }
    }

    // ^ <-
    cando = true;
    nextr = r-m;
    nextc = c-n;
    if (nextr>=0 && nextc>=0  && nextr<nr && nextc<nc) {
        for2(i,r,nextr) {
            if (w[i][c]) {
                cando = false;
                break;
            }
        }
        if (cando) {
            for2(i,c,nextc) {
                if (w[nextr][i]) {
                    cando = false;
                    break;
                }
            }
        }
        if (cando && !instack[nextr][nextc]) {
            res[nextr][nextc]++;
            res[nextr][nextc] += dfs(nextr,nextc);
            hascando = true;
        }
    }

    // v <-
    cando = true;
    nextr = r+m;
    nextc = c-n;
    if (nextr>=0 && nextc>=0  && nextr<nr && nextc<nc) {
        for2(i,r,nextr) {
            if (w[i][c]) {
                cando = false;
                break;
            }
        }
        if (cando) {
            for2(i,c,nextc) {
                if (w[nextr][i]) {
                    cando = false;
                    break;
                }
            }
        }
        if (cando && !instack[nextr][nextc]) {
            res[nextr][nextc]++;
            res[nextr][nextc] += dfs(nextr,nextc);
            hascando = true;
        }
    }

    //Sperator

    // -> ^
    cando = true;
    nextr = r-n;
    nextc = c+m;
    if (nextr>=0 && nextc>=0  && nextr<nr && nextc<nc) {
        for2(i,r,nextr) {
            if (w[i][nextc]) {
                cando = false;
                break;
            }
        }
        if (cando) {
            for2(i,c,nextc) {
                if (w[r][i]) {
                    cando = false;
                    break;
                }
            }
        }
        if (cando && !instack[nextr][nextc]) {
            res[nextr][nextc]++;
            res[nextr][nextc] += dfs(nextr,nextc);
            hascando = true;
        }
    }

    // -> v
    cando = true;
    nextr = r+n;
    nextc = c+m;
    if (nextr>=0 && nextc>=0  && nextr<nr && nextc<nc) {
        for2(i,r,nextr) {
            if (w[i][nextc]) {
                cando = false;
                break;
            }
        }
        if (cando) {
            for2(i,c,nextc) {
                if (w[r][i]) {
                    cando = false;
                    break;
                }
            }
        }
        if (cando && !instack[nextr][nextc]) {
            res[nextr][nextc]++;
            res[nextr][nextc] += dfs(nextr,nextc);
            hascando = true;
        }
    }

    // <- ^
    cando = true;
    nextr = r-n;
    nextc = c-m;
    if (nextr>=0 && nextc>=0  && nextr<nr && nextc<nc) {
        for2(i,r,nextr) {
            if (w[i][nextc]) {
                cando = false;
                break;
            }
        }
        if (cando) {
            for2(i,c,nextc) {
                if (w[r][i]) {
                    cando = false;
                    break;
                }
            }
        }
        if (cando && !instack[nextr][nextc]) {
            res[nextr][nextc]++;
            res[nextr][nextc] += dfs(nextr,nextc);
            hascando = true;
        }
    }

    // <- v
    cando = true;
    nextr = r+n;
    nextc = c-m;
    if (nextr>=0 && nextc>=0  && nextr<nr && nextc<nc) {
        for2(i,r,nextr) {
            if (w[i][nextc]) {
                cando = false;
                break;
            }
        }
        if (cando) {
            for2(i,c,nextc) {
                if (w[r][i]) {
                    cando = false;
                    break;
                }
            }
        }
        if (cando && !instack[nextr][nextc]) {
            res[nextr][nextc]++;
            res[nextr][nextc] += dfs(nextr,nextc);
            hascando = true;
        }
    }

    //cerr<<r<<' '<<c<<endl;

    instack[r][c] = false;

    if (!hascando) {
        //cerr<<r<<' '<<c<<endl;
        if (r!=0 || c!=0) {
            return -1;
        }
    }

    return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while (t--) {
        cin>>nr>>nc;
        cin>>m>>n;
        res.resize(nr,vector<ll>(nc,0));
        w.resize(nr,vector<bool>(nc,false));
        instack.resize(nr,vector<bool>(nc,false));
        int nw; cin>>nw;
        while (nw--) {
           int x,y; cin>>x>>y;
           w[x][y] = true;
        }

        dfs(0,0);

        for1(i,0,res.size()) { for1(j,0,res[i].size()) cerr<<res[i][j]<<' '; cerr<<endl; }
    }
	return 0;
}
