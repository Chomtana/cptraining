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

vector<vector<int>> E;
vector<bool> visited;
vector<bool> btvisited;
vector<bool> C; //f white , b black
vector<bool> ans;
int currmax = -1;
int n,m;

bool check(int p) {
    //if(p==5) { cerr<<p<<" | ";for1(i,1,n+1) if(btvisited[i] || i==p) cerr<<C[i]<<' '; else cerr<<"F "; }
    bool res = true;
    for1(i,0,E[p].size()) {
        int ne = E[p][i];
        if (btvisited[ne]) {
            if (C[ne]) {
                res = false;
                break;
            }
        }
    }
    //if(p==5)cerr<<" | "<<res<<endl;
    return res;
}

void chooseans() {
    //cerr<<"aaa";
    int c = 0;
    for1(i,1,n+1) c+=C[i];
    if(c>currmax) {
        currmax = c;
        ans=C;
    }
}

void bt(int curr) {
    //if (visited[curr]) return;
    visited[curr] = true;
    btvisited[curr] = true;
    ///bf check visited only for use outside of bf

    ///if want check has next must use standard -> if find not visited -> has next
    /*if (E[curr].size()==0) {
        chooseans();
        return;
    }*/

    ///fill
    ///if can fill (check must include newly filled node) ->  do next (if multi do all)
    ///reverse

    ///fill other ...
    ///if can fill (check must include newly filled node) ->  do next (if multi do all)
    ///reverse

    ///...

    bool hasnext = false;

    //fill black
    C[curr] = true;
    if(check(curr)) {
        for1(i,0,E[curr].size()) {
            int ne = E[curr][i];
            if (!btvisited[ne]) {
                hasnext = true;
                //visited[ne] = true;
                //btvisited[ne] = true;
                bt(ne);
                //btvisited[ne] = false;
            }
        }
    }
    C[curr] = false;

    //fill white
    C[curr] = false;
    for1(i,0,E[curr].size()) {
        int ne = E[curr][i];
        if (!btvisited[ne]) {
            hasnext = true;
            //visited[ne] = true;
            //btvisited[ne] = true;
            bt(ne);
            //btvisited[ne] = false;
        }
    }
    C[curr] = false;


    btvisited[curr] = false;

    if(!hasnext) {
        chooseans();
        return;
    }

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
         scanf("%d%d",&n,&m);
        E.resize(n+1);
        C.resize(n+1,false);
        //memset(visited,false,sizeof(visited));
        visited.resize(n+1,false);
        btvisited.resize(n+1,false);
        currmax=-1;
        for1(i,0,m) {
            int s,e; scanf("%d%d",&s,&e);
            E[s].push_back(e);
            E[e].push_back(s);
        }

        for1(i,1,n+1) if(!visited[i]) {
            //visited[i] = true;
            bt(i);
        }

        printf("%d\n",currmax);
        bool first = true;
        for1(i,1,n+1) {
            if(ans[i]) {
                if(first) printf("%d",i); else printf(" %d",i);
                first = false;
            }
        }

        E.clear();
        C.clear();
        visited.clear();
        btvisited.clear();
        ans.clear();
    }
	return 0;
}
