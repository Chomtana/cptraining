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

class main2 {
public:
    vector<vector<int>> E;
    int T[1000];
    int L[1000];
    bool visited[1000];
    bool A[1000];
    int currt = 0;

    void dfs(int curr,int parent) {
        int necount = 0;
        T[curr] = L[curr] = currt++;
        for1(i,0,E[curr].size()) {
            int ne = E[curr][i];
            if (!visited[ne]) {
                visited[ne] = true;
                necount++;
                dfs(ne,curr);
                if (parent != -1 && T[curr]<=L[ne]) {
                    A[curr] = true;
                }
                L[curr] = min(L[curr],L[ne]);
            } else {
                if (ne!=parent) L[curr] = min(L[curr],T[ne]);
            }
        }

        if (parent==-1 && necount>1) A[curr] = true;
    }


    main2() {

    }

    void operator () (int n) {
        //cerr<<"bbb";
        E.resize(n+5);
        cin.ignore();
        string raw;
        while (getline(cin,raw),raw!="0") {
            //cerr<<raw<<endl;
            stringstream ss(raw);
            int s; ss>>s;
            int e;
            while (ss>>e) {
                E[s].push_back(e);
                E[e].push_back(s);
            }
        }

        for1(i,0,n+5) {
            visited[i] = false;
            A[i] = false;
        }
        visited[1] = true; //ta mai compact tong set ton start duad
        dfs(1,-1);

        int res = 0;
        for1(i,1,n+5) {
            res += A[i];
            //if (A[i]) cerr<<i<<endl;
        }

        cout<<res<<endl;
    }
};

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n;
    while (cin>>n,n!=0) {
        main2()(n);

    }
	return 0;
}
