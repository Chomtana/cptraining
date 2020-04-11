
// A Dynamic Programming based solution for 0-1 Knapsack problem
#include <bits/stdc++.h>

#define for1(a, b, c) for (int a = b; a < c; a++)

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

template <typename T, typename U>
class DPTracker {
  public:
    map<T, pair<T, U>> next;

    ll max(T currstate, initializer_list<pair<pair<T, U>, ll>> args) {
      ll currmax = -1e18;
      pair<T, U> maxstate;
      for (auto &x: args) {
        if (x.second > currmax) {
          currmax = x.second;
          maxstate = x.first;
        }
      }

      next[currstate] = maxstate;

      return currmax;
    }

    vector<pair<T, U>> chain(T start) {
      T curr = start;
      vector<pair<T, U>> res;
      while (next.find(curr) != next.end()) {
        pair<T, U>& n = next[curr];
        res.push_back({curr, n.second});
        curr = n.first;
      }

      return res;
    }
};

DPTracker<pair<int,int>, bool> dptracker;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
  int i, w;
  int K[n + 1][W + 1];

  // Build table K[][] in bottom up manner
  for (i = 0; i <= n; i++)
  {
    for (w = 0; w <= W; w++)
    {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (wt[i - 1] <= w)
        K[i][w] = dptracker.max({i, w}, {
          { { {i-1, w-wt[i-1]}, true }, val[i - 1] + K[i - 1][w - wt[i - 1]] },
          { { {i-1, w}, false }, K[i - 1][w] }
        });
      else
        K[i][w] = dptracker.max({i, w}, {
          { { {i-1,w}, false }, K[i - 1][w] }
        });
    }
  }

  return K[n][W];
}

int val[100000];
int wt[100000];

int main()
{
  int W, n;
  cin >> W >> n;
  for1(i, 0, n)
  {
    scanf("%d", val + i);
    wt[i] = val[i];
  }

  int value = knapSack(W, wt, val, n);

  vector<pair<pii, bool>> chain = dptracker.chain({n, W});
  int chaincount = 0;
  for(auto &x: chain) chaincount += x.second;
  cout<<chaincount<<endl;
  for(auto &x: chain) {
    if (x.second) printf("%d ", x.first.first-1);
  }

  //printf("%d", knapSack(W, wt, val, n));
  return 0;
}