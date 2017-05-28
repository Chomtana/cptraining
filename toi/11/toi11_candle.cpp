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

char data[2000][2001];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int nr,nc; cin>>nr>>nc;
    for1(i,0,nr) scanf("%s",data+i);

    int count = 0;

    for1(i,0,nr) {
        for1(j,0,nc) {
            if (data[i][j]=='1') {
                count++;
                queue<pii> q;
                q.push(mp(i,j));
                data[i][j] = 'A';
                while(!q.empty()) {
                    int cr = q.front().first;
                    int cc =q.front().second;
                    q.pop();

                    int dr[] = {0,0,1,-1,1,1,-1,-1};
                    int dc[] = {1,-1,0,0,1,-1,1,-1};
                    for1(k,0,8) {
                        int ner = cr+dr[k];
                        int nec = cc+dc[k];
                        if (ner>=0 and nec>=0 and ner<nr and nec<nc and data[ner][nec]=='1') {
                            q.push(mp(ner,nec));
                            data[ner][nec] = 'A';
                        }
                    }
                }
            }
        }
    }

    cout<<count;
	return 0;
}
