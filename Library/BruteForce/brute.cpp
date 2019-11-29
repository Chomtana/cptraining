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

vector<deque<bool>> brute2n(int size) {
  vector<deque<bool>> res;

  for(int i = 0;i<(1<<size);i++) {
    deque<bool> subres(size);
    for(int j = 0;j<size;j++) {
      if (i&(1<<j)) {
        subres[size-j-1] = true;
      } else {
        subres[size-j-1] = false;
      }
    }

    res.push_back(subres);
  }

  return res;
}

vector<vector<int>> brutecnr(vector<int>& v, int size) {
  vector<vector<int>> res;

  vector<deque<bool>> b2n = brute2n(v.size());

  for(auto &x: b2n) {
    int count1 = count(all(x), 1);
    if (size == -1 || size == count1) {
      vector<int> subres;
      for1(i,0,x.size()) {
        if (x[i]) {
          subres.push_back(v[i]);
        }
      }

      res.push_back(subres);
    }
  }

  return res;
}

vector<vector<int>> brutecnr(vector<int>& v) {
  return brutecnr(v, -1);
}

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
  auto b2n = brute2n(5);

  cerr<<b2n.size()<<endl;
  for(auto &x: b2n) {
    debugv1(x);
  }
	return 0;
}
