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

int m;
vector<int> E[300005];
//int root;
bool visited[300005];
//bool inst[300005];
stack<int> st;
int currg = 1;
int G[300005];

int docycle(int c,int p) {
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!visited[ne]) {
            visited[ne] = true;
            int cyroot = docycle(ne,c);
            if (cyroot!=-1) {
                G[c] = currg;
                if (c==cyroot) {
                    return -1;
                } else return cyroot;
            }
        } else if (ne!=p && (G[ne]==0)) {
            G[c] = currg;
            return ne;
        }
    }

    return -1;
}

int docount(int c) {
    int res = 1;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!visited[ne] && G[ne]==0) {
            visited[ne] = true;
            res += docount(ne);
        }
    }
    return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>m;
	for1(i,0,m) {
		int s,e;
		scanf("%d %d",&s,&e);
		E[s].push_back(e);
		E[e].push_back(s);
		//root = s;
	}

	for1(i,0,300005) {
		if (!visited[i]){
            visited[i] = true;
            docycle(i,-1);
            currg++;
		}
	}
	//docycle(14,-1);

	//cerr<<"bbb";
	//cerr<<"bbb "<<currg<<endl;

	fill(visited,visited+300005,false);

	for1(i,0,300005) {
		if (G[i]!=0 && !visited[i]) {
			//cerr<<i<<' ';
            visited[i] = true;
            printf("%d %d\n",i,docount(i)-1);
		}
	}
	return 0;
}
