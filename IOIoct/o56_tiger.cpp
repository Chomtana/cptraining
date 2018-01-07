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
pii fire[1005];
pii tiger[1005];
int dist[1005];
map<int,int> c;

int caldist(int i,int j) {
    return abs(tiger[i].first-fire[j].first)+abs(tiger[i].second-fire[j].second);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;
    fill(dist,dist+1005,1E9);
    for1(i,0,n) {
        scanf("%d%d",&fire[i].first,&fire[i].second);
    }
    for1(i,0,m) {
        scanf("%d%d",&tiger[i].first,&tiger[i].second);
    }
    for1(i,0,m) {
        for1(j,0,n) {
            dist[i] = min(dist[i],caldist(i,j));
        }
    }
    int res = 0;
    for1(i,0,m) {
        //cerr<<i<<' '<<dist[i]<<endl;
        res=max(res,++c[dist[i]]);
    }
    cout<<res;
	return 0;
}
