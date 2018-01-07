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

int n;
int pos[100005];
int currg = 0;
vector<int> G[5];
vector<int> E[100005];
bool visited[100005];
vector<int> pos1;
vector<int> pos2;


void dfs(int c) {
    if (visited[c]) return;
    visited[c] = true;
    G[currg].push_back(c);
    for1(i,0,E[c].size()) dfs(E[c][i]);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    for1(i,0,n) {
        int p ; scanf("%d",&p);
        //pos[i] = mp(p,i+1);
        pos[i+1] = p;
    }

    for1(i,0,n-2) {
        int s,e; scanf("%d%d",&s,&e);
        E[s].push_back(e);
        E[e].push_back(s);
    }

    //sort(pos,pos+n);
    for1(i,1,n+1) {
        if (!visited[i]) {
            dfs(i);
            currg++;
        }
    }

    for1(i,0,G[0].size()) {
        pos1.push_back(pos[G[0][i]]);
        //cerr<<pos1.back()<<' ';
    }
    //cerr<<endl;
    for1(i,0,G[1].size()) {
        pos2.push_back(pos[G[1][i]]);
        //cerr<<pos2.back()<<' ';
    }
    //cerr<<endl;

    sort(all(pos1));
    sort(all(pos2));

    int res = 1E9;
    for1(i,0,pos1.size()) {
        //int sub = 1E9;
        auto lb = lower_bound(all(pos2),pos1[i]);
        if (lb!=pos2.end()) {
            res = min(res,abs(*lb-pos1[i]));
        }

        auto ub = upper_bound(all(pos2),pos1[i]);
        if (ub!=pos2.begin()) {
            ub--;
            res = min(res,abs(*ub-pos1[i]));
        }
    }

    cout<<res;

	return 0;
}
