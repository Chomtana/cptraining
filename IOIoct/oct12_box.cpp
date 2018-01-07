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

int nr,nc;
char data[40][40];
bool visited[40][40];

char get(int i,int j) {
    if (i<0||j<0||i>=nr||j>=nc) return '#';
    return data[i][j];
}

bool isok(int i,int j) {
    return data[i][j]=='.' && data[i+1][j]=='.' && data[i][j+1]=='.' && data[i+1][j+1]=='.';
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>nr>>nc;
    for1(i,0,nr) {
        scanf("%s",data[i]);
    }

    queue<pii> q;
    for1(j,0,nc-1) {
        if(isok(0,j)) {
            visited[0][j] = true;
            q.push(mp(0,j));
        }
    }
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        if (cr==nr-2) {
            cout<<"yes"; return 0;
        }

        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        for1(i,0,4) {
            int ner = cr+dr[i];
            int nec = cc+dc[i];
            if (ner>=0&&nec>=0&&ner<nr&&nec<nc&&!visited[ner][nec]&&isok(ner,nec)) {
                visited[ner][nec] = true;
                q.emplace(ner,nec);
            }
        }

    }

    cout<<"no";
	return 0;
}
