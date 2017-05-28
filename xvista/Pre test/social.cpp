#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(a,b,c) for(int (a)=(b);((b)<(c)?(a)<(c):(a)>=(c));a+=((b)<(c)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

struct djnode {
    string parent = ""; //null style -> cannot union element that in same group
    int rank = 0;
    int c = 1;
};

map<string,djnode> djset;

string find(string t) {
    if (djset[t].parent=="") return t;
    return djset[t].parent = find(djset[t].parent);
}

void un(string a,string b) {
    a = find(a);
    b = find(b);
    if (djset[a].rank<djset[b].rank) {
        djset[a].parent = b;
        djset[b].rank++;
        djset[b].c += djset[a].c;
    } else {
        djset[b].parent = a;
        djset[a].rank++;
        djset[a].c += djset[b].c;
    }
}

int main() {
    int t; cin>>t;
    while (t--) {
        int n; scanf("%d",&n);
        while (n--) {
            char _s[25];
            char _e[25];
            scanf("%s %s",_s,_e);
            string s(_s);
            string e(_e);
            if (find(s)==find(e)) {
                printf("%d\n",djset[find(s)].c);
            } else {
                un(s,e);
                printf("%d\n",djset[find(s)].c);
            }
            /*un(s,e);
            printf("%d\n",djset[find(s)].c);*/
        }
    }

    return 0;
}
