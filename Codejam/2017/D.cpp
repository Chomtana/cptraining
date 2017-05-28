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
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        int n,m; cin>>n>>m;
        vector<vector<int>> weight(n,vector<int>(n,0));

        vector<vector<char>> data(n,vector<char>(n,'.'));

        vector<vector<bool>> edited(n,vector<bool>(n,false));

        while (m--) {
            char cc; int r,c; cin>>cc>>r>>c;
            r--; c--;
            data[r][c] = cc;
        }

        //key is 'x' it make diagonal fill possible

        subfunc(bool,pk,(int r,int c)) { //is it possible to place key at (r,c)
            if (data[r][c]!='.') return false;

            int i = 1;
            while (true) {
                bool nextok = false;
                int dr[] = {0,0,i,-i};
                int dc[] = {i,-i,0,0};
                //bool foundsth = false;
                for1(j,0,4) {
                    int nextr = r + dr[j];
                    int nextc = c + dc[j];
                    if (nextr>=0 && nextc>=0 && nextr<n && nextc<n) {
                        nextok = true;
                        if (data[nextr][nextc]!='.' && data[nextr][nextc]!='+') return false;
                    }
                }
                if (!nextok) break;
                i++;
            }
            return true;
        };

        subfunc(bool,fp,(int r,int c)) { //is it possible to fill plus at (r,c)
            if (data[r][c]!='.') return false;

            int i = 1;
            /*bool hask1 = false;
            bool hask2 = false;

            i = 1;
            bool first = true;
            while (true) {
                bool nextok = false;
                int dr[] = {i,-i};
                int dc[] = {i,-i};
                //bool foundsth = false;
                for1(j,0,2) {
                    int nextr = r + dr[j];
                    int nextc = c + dc[j];
                    if (nextr>=0 && nextc>=0 && nextr<n && nextc<n) {
                        nextok = true;
                        if (data[nextr][nextc]=='x') {
                            hask1 = true;
                            break;
                        }
                    }
                }
                if (!nextok) {
                    if (first) {
                        hask1 = true;
                    }
                    break;
                }
                first = false;
                i++;
            }

            i = 1;
            first = true;
            while (true) {
                bool nextok = false;
                int dr[] = {i,-i};
                int dc[] = {-i,i};
                //bool foundsth = false;
                for1(j,0,2) {
                    int nextr = r + dr[j];
                    int nextc = c + dc[j];
                    if (nextr>=0 && nextc>=0 && nextr<n && nextc<n) {
                        nextok = true;
                        if (data[nextr][nextc]=='x') {
                            hask2 = true;
                            break;
                        }
                    }
                }
                if (!nextok) {
                    if (first) {
                        hask2 = true;
                    }
                    break;
                }
                first = false;
                i++;
            }

            if (hask1 && hask2) return true; //else return false;*/

            i = 1;
            while (true) {
                bool nextok = false;
                int dr[] = {i,i,-i,-i};
                int dc[] = {i,-i,i,-i};
                //bool foundsth = false;
                for1(j,0,4) {
                    int nextr = r + dr[j];
                    int nextc = c + dc[j];
                    if (nextr>=0 && nextc>=0 && nextr<n && nextc<n) {
                        nextok = true;
                        if (data[nextr][nextc]!='.' && data[nextr][nextc]!='x') return false;
                    }
                }
                if (!nextok) break;
                i++;
            }
            return true;
        };

        //upgrade to O
        subfunc(bool,fo,(int r,int c)) { //is it possible to fill o at (r,c)
            //if (data[r][c]!='.') return false;

            int i = 1;

            subfunc(bool,dorc,()) {
                i = 1;
                while (true) {
                    bool nextok = false;
                    int dr[] = {0,0,i,-i};
                    int dc[] = {i,-i,0,0};
                    //bool foundsth = false;
                    for1(j,0,4) {
                        int nextr = r + dr[j];
                        int nextc = c + dc[j];
                        if (nextr>=0 && nextc>=0 && nextr<n && nextc<n) {
                            nextok = true;
                            if (data[nextr][nextc]!='.' && data[nextr][nextc]!='+') return false;
                        }
                    }
                    if (!nextok) break;
                    i++;
                }
                return true;
            };

            subfunc(bool,dodiag,()) {
                /*bool hask1 = false;
                bool hask2 = false;

                i = 1;
                bool first = true;
                while (true) {
                    bool nextok = false;
                    int dr[] = {i,-i};
                    int dc[] = {i,-i};
                    //bool foundsth = false;
                    for1(j,0,2) {
                        int nextr = r + dr[j];
                        int nextc = c + dc[j];
                        if (nextr>=0 && nextc>=0 && nextr<n && nextc<n) {
                            nextok = true;
                            if (data[nextr][nextc]=='x') {
                                hask1 = true;
                                break;
                            }
                        }
                    }
                    if (!nextok) {
                        if (first) {
                            hask1 = true;
                        }
                        break;
                    }
                    first = false;
                    i++;
                }

                i = 1;
                first = true;
                while (true) {
                    bool nextok = false;
                    int dr[] = {i,-i};
                    int dc[] = {-i,i};
                    //bool foundsth = false;
                    for1(j,0,2) {
                        int nextr = r + dr[j];
                        int nextc = c + dc[j];
                        if (nextr>=0 && nextc>=0 && nextr<n && nextc<n) {
                            nextok = true;
                            if (data[nextr][nextc]=='x') {
                                hask2 = true;
                                break;
                            }
                        }
                    }
                    if (!nextok) {
                        if (first) {
                            hask2 = true;
                        }
                        break;
                    }
                    first = false;
                    i++;
                }

                if (hask1 && hask2) return true; //else return false;*/

                i = 1;
                while (true) {
                    bool nextok = false;
                    int dr[] = {i,i,-i,-i};
                    int dc[] = {i,-i,i,-i};
                    //bool foundsth = false;
                    for1(j,0,4) {
                        int nextr = r + dr[j];
                        int nextc = c + dc[j];
                        if (nextr>=0 && nextc>=0 && nextr<n && nextc<n) {
                            nextok = true;
                            if (data[nextr][nextc]!='.' && data[nextr][nextc]!='x') return false;
                        }
                    }
                    if (!nextok) break;
                    i++;
                }
                return true;
            };

            return dorc() && dodiag();
        };


        for1(i,0,n) {
            for1(k,0,n-i) {
                weight[i+k][k]+=n-i;
                weight[k][i+k]+=n-i;
            }
        }

        for1(i,0,n) {
            weight[i][i]-=n;
        }

        for2(i,n-1,0) {
            for1(k,0,i+1) {
                weight[k][i-k]+=i+1;
                weight[n-1-i+k][n-1-k]+=i+1;
            }
        }

        for1(i,0,n) {
            weight[i][n-1-i]-=n;
        }

        weight[0][0]--;
        weight[0].back()--;
        weight.back()[0]--;
        weight.back().back()--;

        //set<pii> O;
        //set<pii> P;
        //set<pii> X;

        //do o,o main diag
        /*int oomaxw = -1;
        int ooi = -1;
        char bf1 = data[0][0];
        char bf2 = data.back().back();
        data[0][0] = '.';
        data.back().back() = '.';
        for1(i,1,n-1) {
            if (pk(i,i) || data[i][i]=='x') {
                if (weight[i][i]>oomaxw) {
                    oomaxw = weight[i][i];
                    ooi = i;
                }
            }
        }
        if (ooi!=-1) {
            if (data[ooi][ooi] != 'x') {
                X.push_back(mp(ooi,ooi));
            }
            data[ooi][ooi] = 'x';
            if (bf1!='o') {
                O.push_back(mp(0,0));
            }
            if (bf2!='o') {
                O.push_back(mp(n-1,n-1));
            }
            data[0][0] = 'o';
            data.back().back() = 'o';
        } else {
            //do o,o secondary diag

            //reverse value
            data[0][0] = bf1;
            data.back().back() = bf2;
            oomaxw = -1;
            ooi = -1;

            bf1 = data[0][n-1];
            bf2 = data.back()[0];
            data[0][n-1] = '.';
            data.back()[0] = '.';
            for1(i,1,n-1) {
                if (pk(i,n-1-i) || data[i][n-1-i]=='x') {
                    if (weight[i][n-1-i]>oomaxw) {
                        oomaxw = weight[i][n-1-i];
                        ooi = i;
                    }
                }
            }
            if (ooi!=-1) {
                if (data[ooi][n-1-ooi] != 'x') {
                    X.push_back(mp(ooi,n-1-ooi));
                }
                data[ooi][n-1-ooi] = 'x';
                if (bf1!='o') {
                    O.push_back(mp(0,n-1));
                }
                if (bf2!='o') {
                    O.push_back(mp(n-1,0));
                }
                data[0][n-1] = 'o';
                data.back()[0] = 'o';
            } else {
                //reverse value
                data[0][n-1] = bf1;
                data.back()[0] = bf2;
            }
        }*/

        /*priority_queue<piii,vector<piii>> pq;
        for1(i,0,n) {
            for1(j,0,n) {
                pq.push(mp(weight[i][j],mp(i,j)));
            }
        }

        while (!pq.empty()) {
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (pk(r,c)) {
                data[r][c] = 'x';
                edited[r][c] = true;
            } else {
                if (fp(r,c)) {
                    data[r][c] = '+';
                    edited[r][c] = true;
                }
            }

        }*/

        for1(i,0,n) {
            for1(j,0,n) {
                if (data[i][j]!='o' && fo(i,j)) {
                    data[i][j] = 'o';
                    edited[i][j] = true;
                } else {
                    if (fp(i,j)) {
                        data[i][j] = '+';
                        edited[i][j] = true;
                    } else {
                        if (pk(i,j)) {
                            data[i][j] = 'x';
                            edited[i][j] = true;
                        }
                    }
                }
            }
        }

        int totalscore = 0;
        int totaledit = 0;

        for1(i,0,n) {
            for1(j,0,n) {
                if (data[i][j] == '+' || data[i][j]=='x') totalscore++;
                else if (data[i][j] == 'o') totalscore+=2;
                totaledit += edited[i][j];
            }
            //cerr<<endl;
        }

        cout<<"Case #"<<_<<": "<<totalscore<<' '<<totaledit<<endl;

        for1(i,0,n) {
            for1(j,0,n) {
                if (edited[i][j]) {
                    cout<<data[i][j]<<' '<<i+1<<' '<<j+1<<endl;
                }
            }
        }

        /*if (O.size()>0) {
            for(auto &p:O) {
                cout<<'o'<<' '<<p.first+1<<' '<<p.second+1<<endl;
            }
        }

        if (P.size()>0) {
            for(auto &p:P) {
                cout<<'+'<<' '<<p.first+1<<' '<<p.second+1<<endl;
            }
        }

        if (X.size()>0) {
            for(auto &p:X) {
                cout<<'x'<<' '<<p.first+1<<' '<<p.second+1<<endl;
            }
        }*/

        /*for1(i,0,n) {
            for1(j,0,n) {
                cerr<<data[i][j];
            }
            cerr<<endl;
        }*/




        /*for1(i,0,n) {
            for1(j,0,n) {
                cerr<<weight[i][j]<<' ';
            }
            cerr<<endl;
        }*/
    }
	return 0;
}
