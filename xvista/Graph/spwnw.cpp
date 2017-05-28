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
typedef pair<pii,int> piii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m,s; cin>>n>>m>>s;
    piii El[m];
    for1(i,0,m) {
        int s,e,w; scanf("%d%d%d",&s,&e,&w);
        El[i].first = mp(s,e);
        El[i].second = w;
    }

    int dist[n];
    for1(i,0,n) dist[i] = 1E9;
    dist[s] = 0;

    for1(_,0,n-1) { //do n-1 times but not use for loop variable to process
        for1(i,0,m) {
            int s = El[i].first.first;
            int e = El[i].first.second;
            int w = El[i].second;
            dist[e] = min(dist[e],dist[s]+w);
        }
    }

    //bool negcy = false;

    for1(i,0,m) {
        int s = El[i].first.first;
        int e = El[i].first.second;
        int w = El[i].second;
        if (dist[s]+w<dist[e]) {
            cout<<-1; return 0;
        }
    }

    for1(i,0,n) {
        printf("%d ",dist[i]);
    }


	return 0;
}
