#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int nv,ne; cin>>nv>>ne;
    vector<string> i2v(nv);
    map<string,int> v2i;
    for1(i,0,nv) {
        cin>>i2v[i];
        v2i[i2v[i]] = i;
    }

    vector<vector<int>> E(nv);

    for1(i,0,ne) {
        int s,e; cin>>s>>e;
        E[s].push_back(e);
        E[e].push_back(s);
    }

    while (true) {
        string in; cin>>in;
        int vi = v2i[in];
        for1(i,0,E[vi].size()) {
            cout<<in<<" "<<i2v[E[vi][i]]<<endl;
        }
    }


	return 0;
}
