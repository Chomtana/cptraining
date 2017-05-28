#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

string p1,p2;
string x;

class Hasher {
public:
    size_t operator () (const pii &a) const {
        return a.first*a.second;
    }
};

unordered_map<pii,bool,Hasher> dp[2005]; //global auto init

bool recur(int c,int c1,int c2) {
    //find to end : if out of bound -> ok
    if (c>=x.size()) return true;

    //if cached -> return cache : before do next
    if (dp[c].find(mp(c1,c2))!=dp[c].end()) return dp[c][mp(c1,c2)];

    //do next
    bool res = false;

    if (c1<p1.size() && x[c]==p1[c1]) {
        //select 1 dai
        res = res | recur(c+1,c1+1,c2);
    }

    if (res) return dp[c][mp(c1,c2)] = true; //tua dai tua nueng -> always check  if res -> return true  after do next

    if (c2<p2.size() && x[c]==p2[c2]) {
        //select 2 dai
        res = res | recur(c+1,c1,c2+1);
    }

    return dp[c][mp(c1,c2)] = res;
}

bool main2() {
    cin>>x;
    return recur(0,0,0);
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>p1>>p2;
    int t; cin>>t;
    while (t--) {
        if(main2()) printf("Yes\n"); else printf("No\n");
        for1(i,0,x.size()+3) {
            dp[i].clear();
        }
    }
	return 0;
}
