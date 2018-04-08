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

string s;
vector<int> qs[50005];

vector<int> query(int s,int e) {
    if (s==0) {
        return qs[e];
    } else {
        vector<int> res(40);
        for1(i,0,40) {
            res[i] = qs[e][i]-qs[s-1][i];
        }
        return res;
    }
}


int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    cin>>s;
    qs[0].resize(40);
    qs[0][s[0]-'a'] = 1;
    for1(i,1,s.size()) {
        for1(j,0,40) {
            qs[i].push_back(qs[i-1][j]);
        }
        qs[i][s[i]-'a'] = qs[i][s[i]-'a']+1;
    }
    
    /*for1(i,0,s.size()) {
        for1(j,0,40) {
            cerr<<"aaa "<<i<<' '<<j<<" : "<<qs[i][j]<<endl;
        }
    }*/
    
    int q; cin>>q;
    while(q--) {
        int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
        a--; b--; c--; d--;
        vector<int> x = query(a,b);
        vector<int> y = query(c,d);
        //for1(i,0,x.size()) cerr<<x[i]<<' '; cerr<<endl;
        //for1(i,0,y.size()) cerr<<y[i]<<' '; cerr<<endl;
        if (x==y) {
            printf("DA\n");
        } else {
            printf("NE\n");
        }
        
    }
    return 0;
}
