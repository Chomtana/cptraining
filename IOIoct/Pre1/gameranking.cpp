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

int n,m;
vector<int> E[5005];
vector<int> Et[5005];
bool visited1[5005];
bool visited2[5005];
pii f[5005];
int currf = 0;
int G[5005];
int Gc[5005];

int prevmax = -1;

set<int> inc;

void doscc(int c,int r) {
    //if (visited2[c]) return;
    //visited2[c] = true;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!visited2[ne]) {
            visited2[ne] = true;
            doscc(ne,r);
        } else if (ne!=r) {
            //prevmax = min(prevmax,G[ne]);
            //G[ne]++;
            inc.insert(ne);
        }
    }

    /*if (prevmax==1E9) G[c] = n; else
    G[c] = prevmax-1;*/
    G[c] = 0;
}

void dof(int c) {
    if (visited1[c]) return;
    visited1[c] = true;
    for1(i,0,Et[c].size()) dof(Et[c][i]);
    f[c] = mp(currf++,c);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;
    fill(G,G+5005,1E9);
    for1(i,0,m) {
        int s,e; scanf("%d%d",&s,&e);
        E[s].push_back(e);
        Et[e].push_back(s);
    }

    for1(i,0,n) {
        if (!visited1[i]) {
            dof(i);
        }
    }

    sort(f,f+n,greater<pii>());

    prevmax = 1E9;

    for1(i,0,n) {
        int c = f[i].second;
        if(!visited2[c]) {
            visited2[c] = true;
            doscc(c,c);
            prevmax = 1E9;
            for(auto j:inc) {
                G[j]++;
            }
            inc.clear();
        }
    }

    for1(i,0,n) {
        cerr<<i<<" : "<<f[i].first<<' '<<f[i].second<<endl;
    }

    int Gm = *min_element(G,G+5005);

    for1(i,0,n) {
        cerr<<i<<" : "<<G[i]<<endl;
        Gc[G[i]]++;
    }

    for1(i,0,5005) {
        if (Gc[i]<=0) return 0;
        printf("%d ",Gc[i]);
    }

	return 0;
}
