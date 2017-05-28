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
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;

pii nextpos(int r,int c,int dir,int n) {
    switch(dir) {
    case 0: r-=n; break;
    case 1: c+=n; break;
    case 2: r+=n; break;
    case 3: c-=n; break;
    }
    return mp(r,c);
}

int nr,nc;
vector<vector<int>> data;

bool checkob(int r,int c) {
    if (r<0 || c<0 || r>=nr || c>=nc) return false;
    return data[r][c];
}

bool checkcon2(int r,int c) {
    if (r<=0 || c<=0 || r>=nr || c>=nc) return false;
    return !checkob(r,c) && !checkob(r-1,c) && !checkob(r,c-1) && !checkob(r-1,c-1);
}

bool checkcon(int r,int c,int dir,int n) {
    pii next = nextpos(r,c,dir,n);
    if (next.first<=0 || next.second<=0 || next.first>=nr || next.second>=nc) return false;
    switch(dir) {
    case 0: for1(i,0,n+1) if (!checkcon2(r-i,c)) return false; break;
    case 1: for1(i,0,n+1) if (!checkcon2(r,c+i)) return false; break;
    case 2: for1(i,0,n+1) if (!checkcon2(r+i,c)) return false; break;
    case 3: for1(i,0,n+1) if (!checkcon2(r,c-i)) return false; break;
    }
    return true;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;

    while (scanf("%d%d",&nr,&nc),nr!=0) {
        data.resize(nr,vi(nc));
        for1(i,0,nr) for1(j,0,nc) scanf("%d",&data[i][j]);
        int sr,sc,er,ec; scanf("%d%d%d%d",&sr,&sc,&er,&ec);
        string sdirs; cin>>sdirs;

        int dir = 0; //nesw
        if (sdirs[0]=='n') {
            dir = 0;
        } else if (sdirs[0]=='e') {
            dir = 1;
        } else if (sdirs[0]=='s') {
            dir = 2;
        } else if (sdirs[0]=='w') {
            dir = 3;
        }

        //-1 0 do scan check con
        map<piii,int> dist;
        queue<piii> q;
        q.push(mp(mp(sr,sc),dir));
        dist[mp(mp(sr,sc),dir)] = 0;
        while (!q.empty()) {
            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int cdir = q.front().second;
            int cdist = dist[q.front()];
            //if (cr==er && cc==ec) break; //cannot do because (er,ec) has 4 vertice ... (er,ec,0...3)
            q.pop();
            //cerr<<cr<<' '<<cc<<' '<<cdir<<endl;

            int rightdir = cdir+1;
            int leftdir = cdir-1;
            if (rightdir>3) { rightdir = 0; }
            if (leftdir<0) { leftdir = 3; }

            //do next
            if (dist.find(mp(mp(cr,cc),rightdir))==dist.end()) {
                dist[mp(mp(cr,cc),rightdir)] = cdist+1;
                q.push(mp(mp(cr,cc),rightdir));
            }
            if (dist.find(mp(mp(cr,cc),leftdir))==dist.end()) {
                dist[mp(mp(cr,cc),leftdir)] = cdist+1;
                q.push(mp(mp(cr,cc),leftdir));
            }
            if (checkcon(cr,cc,cdir,1) && dist.find(mp(nextpos(cr,cc,cdir,1),cdir))==dist.end()) {
                dist[mp(nextpos(cr,cc,cdir,1),cdir)] = cdist+1;
                q.push(mp(nextpos(cr,cc,cdir,1),cdir));
            }
            if (checkcon(cr,cc,cdir,2) && dist.find(mp(nextpos(cr,cc,cdir,2),cdir))==dist.end()) {
                dist[mp(nextpos(cr,cc,cdir,2),cdir)] = cdist+1;
                q.push(mp(nextpos(cr,cc,cdir,2),cdir));
            }
            if (checkcon(cr,cc,cdir,3) && dist.find(mp(nextpos(cr,cc,cdir,3),cdir))==dist.end()) {
                dist[mp(nextpos(cr,cc,cdir,3),cdir)] = cdist+1;
                q.push(mp(nextpos(cr,cc,cdir,3),cdir));
            }

        }

        int currmin = 1E9;
        for1(i,0,4) {
            if (dist.find(mp(mp(er,ec),i))!=dist.end()) {
                currmin = min(currmin,dist[mp(mp(er,ec),i)]);
            }
        }
        if (currmin == 1E9) cout<<-1<<endl; else
        cout<<currmin<<endl;
        /*for1(i,0,nr+1) {
            for1(j,0,nc+1) {
                cerr<<min({dist[mp(mp(i,j),0)],dist[mp(mp(i,j),1)],dist[mp(mp(i,j),2)],dist[mp(mp(i,j),3)]})<<' ';
            }
            cerr<<endl;
        }*/

        data.clear();
    }
	return 0;
}
