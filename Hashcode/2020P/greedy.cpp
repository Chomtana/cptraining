#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int a[1000005];

pii in[1000005];

int main() {
  int n,w; cin>>w>>n;
  for1(i,0,n) scanf("%d", &a[i]);

  for1(i,0,n) in[i] = {a[i], i};
  sort(in, in+n, [] (auto &a, auto &b) {
    return a>b;
  });

  vector<int> res;

  for1(i,0,n) {
    if (in[i].first < w) {
      res.push_back(in[i].second);
      w -= in[i].first;
    }
  }

  cout<<res.size()<<endl;
  for1(i,0,res.size()) {
    printf("%d ", res[i]);
  }

  return 0;
}