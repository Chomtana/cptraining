#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;
#define debug1(a) cout<<(a)<<endl;
#define debug2(a,b) cout<<(a)<<' '<<(b)<<endl;
#define debug3(a,b,c) cout<<(a)<<' '<<(b)<<' '<<(c)<<endl;
#define debug4(a,b,c,d) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<' '<<(e)<<endl;
#define until(x) while(!x)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector<vector<int>> E;
vector<int> all;
vector<int> avail;
vector<int> used;

int pickrand(vector<int>& v) {
  return v[rand() % v.size()];
}

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
  srand(time(0));

  int n,m; cin>>n>>m;
  E.resize(n+5);
  for1(i,2,n+1) avail.push_back(i);
  used.push_back(1);

  for1(i,1,n+1) all.push_back(i);

  for1(i,1,n) {
    if (i>m) break;
    int a = pickrand(avail);
    int b = pickrand(used);

    avail.erase(find(all(avail), a));
    used.push_back(a);

    E[a].push_back(b);
    //cerr<<a<<' '<<b<<endl;
  }

  for1(i,0,m-(n-1)) {
    int a = pickrand(all);
    int b = pickrand(all);
    while (a==b) b = pickrand(all);

    E[a].push_back(b);
  }

  for1(s, 1, n+1) {
    //cerr<<s<<endl;
    for(auto &e: E[s]) {
      printf("%d %d\n",s,e);
    }
  }


	return 0;
}
