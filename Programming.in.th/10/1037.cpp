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
typedef pair<pii,int> piii;
typedef vector<int> vi;

int nr,nc;
char data[55][55];
int has[55][55];
bool visited1[55][55];
bool visited2[55][55];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>nr>>nc;
    for(int i = 0;i<=nr+1;i++) {
        if (i==0||i==nr+1) {
            for(int j=0;j<=nc+1;j++) {
                data[i][j]='X';
            }
            continue;
        }
        scanf("%s",data[i]+1);
        data[i][0] = data[i][nc+1] = 'X';
    }

    /*for1(i,0,nr+2) {
        for1(j,0,nc+2) {
            cerr<<data[i][j];
        }
        cerr<<endl;
    }*/

    int sr,sc;

    queue<piii> q;
    for(int i = 1;i<=nr;i++) {
        for(int j=1;j<=nc;j++) {
            has[i][j] = 1E9;
            if (data[i][j]=='*') {
                q.push({{i,j},0});
                visited1[i][j] = true;
            }
            else if (data[i][j]=='S') {
                sr = i; sc=j;
            }
        }
    }
    while(!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int ct = q.front().second;
        q.pop();

        //cerr<<cr<<' '<<cc<<' '<<ct<<' '<<endl;

        has[cr][cc] = min(has[cr][cc],ct);

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        for(int i = 0;i<4;i++) {
            int ner = cr+dr[i];
            int nec = cc+dc[i];
            if (!visited1[ner][nec] && data[ner][nec]!='X' && data[ner][nec]!='D') {
                visited1[ner][nec] = true;
                q.push({{ner,nec},ct+1});
            }
        }
    }

    /*for1(i,1,nr+1) {
        for1(j,1,nc+1) {
            cerr<<has[i][j]<<' ';
        }
        cerr<<endl;
    }*/

    q.push({{sr,sc},0});
    visited2[sr][sc] = true;
    while(!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int ct = q.front().second;
        q.pop();

        //cerr<<"aaa "<<cr<<' '<<cc<<' '<<ct<<' '<<endl;

        if (data[cr][cc]=='D') {
            cout<<ct<<endl; return 0;
        }

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        for(int i = 0;i<4;i++) {
            int ner = cr+dr[i];
            int nec = cc+dc[i];
            if (!visited2[ner][nec] && data[ner][nec]!='X' && has[ner][nec]>ct+1) {
                visited2[ner][nec] = true;
                q.push({{ner,nec},ct+1});
            }
        }
    }

    cout<<"KAKTUS"<<endl;

	return 0;
}
