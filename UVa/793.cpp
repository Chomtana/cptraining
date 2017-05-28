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

struct djnode {
    int parent;
    int rank = 0;
};

vector<djnode> djset;

int find(int i) {
    if(djset[i].parent==i)return i;
    return djset[i].parent = find(djset[i].parent);
}

void un(int a,int b) {
    a = find(a);
    b = find(b);
    if (djset[a].rank<djset[b].rank) {
        djset[a].parent = b;
        djset[b].rank++;
    } else {
        djset[b].parent = a;
        djset[a].rank++;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	bool first = true;
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        djset.resize(n+10);
        for1(i,0,n+5) {
            djset[i].rank = 0;
            djset[i].parent = i;
        }
        cin.ignore();
        string raw;
        int okcount = 0;
        int failcount = 0;
        while(getline(cin,raw)&&raw!="") {
            stringstream ss(raw);
            char c; int a,b; ss>>c>>a>>b;
            if (c=='c') {
                un(a,b);
            } else {
                if (find(a)==find(b)) {
                    okcount++;
                } else failcount++;
            }
        }

        if(!first) cout<<endl;
        cout<<okcount<<','<<failcount<<endl;
        first = false;
    }
	return 0;
}
