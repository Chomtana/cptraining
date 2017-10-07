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
vector<vector<int>> E(100005);

int M[100005];
bool filled[100005];
int root = -1;
int P[100005];
ll S[100005];
int curr = 1;

int domax(int c) {
    M[c] = c;
    //cerr<<"aaa "<<c<<endl;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if(!filled[ne]) {
            M[c] = max(M[c],domax(ne));
        }
    }
    return M[c];
}

void fill(int c) {
    bool hasnext = false;
    vector<pii> select;
    int realne = -1;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if(!filled[ne]) {
            hasnext = true;
            select.push_back(mp(M[ne],ne));
        }
    }

    sort(all(select));

    for1(i,0,select.size()) {
        fill(select[i].second);
    }

    filled[c] = true;
    P[curr] = c;
    S[curr] = S[curr-1]+c;
    curr++;


    //return fill(realne);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;
    for1(i,1,n+1) {
        int p; scanf("%d",&p);
        if(p!=0) {
            E[p].push_back(i);
        } else {
            root=i;
        }
    }

    /*domax(root);
    for1(i,1,n+1) {
        cerr<<i<<' '<<M[i]<<endl;
    }*/

    /*for1(i,1,n+1) {
        domax(root);
        P[i] = fill(root);
        filled[P[i]] = true;
        S[i] = S[i-1]+P[i];
    }*/

    domax(root); //O(n)
    fill(root); //O(nlogn)

    /*for1(i,1,n+1) {
        cerr<<P[i]<<' ';
    }*/

    int curr = 0;

    while (m--) {
        int type; scanf("%d",&type);
        if (type==1) {
            int x; scanf("%d",&x);
            curr += x;
            printf("%d\n",P[curr]);
        } else if (type==2) {
            int x; scanf("%d",&x);
            curr -= x;
        } else {
            printf("%lld\n",S[curr]);
        }
    }
	return 0;
}
