#include <bits/stdc++.h>

typedef int intonly;
#define int long long

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(), x.end()

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

int n, nl, days;
int scores[100005];
bool have_scores[100005];

class Lib {
  public:
    int id;
    int signup;
    int ship;
    int bookn;
    vector<int> books;

    vector<int> scan_books;
    int round_scan_books = 0;

    int currday = 0;

    void addBook(int bookid) {
      books.push_back(bookid);
    }

    int signUp(int lastSignup) {
      currday = lastSignup + signup + 1;
      return currday - 1;
    }

    int scanBook(int bookid) {
      if (currday >= days) return currday;

      scan_books.push_back(bookid);
      round_scan_books++;

      if (round_scan_books == ship) {
        currday++;
        round_scan_books = 0;
      }
    }
};

vector<Lib> lib(100005);

vector<int> signupOrder;

vector<int> book2lib[100005];

intonly main() {
  cin>>n>>nl>>days;
  for1(i,0,n) {
    scanf("%lld", scores+i);
    //cerr<<"I "<<i<<endl;
  }
  for1(li,0,nl) {
    Lib l;
    l.id = li;
    int bookn, signup, ship;
    scanf("%lld %lld %lld", &bookn, &signup, &ship);
    l.bookn = bookn;
    l.signup = signup;
    l.ship = ship;
    //cerr<<"LI "<<li<<' '<<bookn<<' '<<l.bookn<<endl;
    for1(i,0,l.bookn) {
      int bookid;
      scanf("%lld", &bookid);

      l.addBook(bookid);

      book2lib[bookid].push_back(li);
    }

    lib[li] = l;
  }

  
  
  // start code
  for1(i,0,nl) {
    signupOrder.push_back(i);
  }

  sort(all(signupOrder), [](auto a, auto b) {
    // if (lib[a].signup == lib[b].signup)
    // {
    // return lib[a].ship < lib[b].ship;
    // }
    return lib[a].signup - (double)lib[a].fullscore / (double)lib[a].signup) /*lib[a].bookn / lib[a].ship*/ < lib[b].signup - (double)lib[a].fullscore / (double)lib[a].signup) /*lib[b].bookn / lib[b].ship*/;
  });

  // Simulate signup
  int lastSignup = -1;
  for(auto &li: signupOrder) {
    lastSignup = lib[li].signUp(lastSignup);
  }

  vector<int> booki_byrare; for1(i,0,n) booki_byrare.push_back(i);
  sort(all(booki_byrare), [] (auto a, auto b) {
    return scores[a] > scores[b];
    //return book2lib[a].size() < book2lib[b].size();
  });

  for(auto booki: booki_byrare) {
    ll currmin = 1e18;
    int minli = -1;
    for(auto li: book2lib[booki]) {
      if (lib[li].currday < currmin) {
        currmin = lib[li].currday;
        minli = li;
      }
    }

    if (minli == -1) continue;

    lib[minli].scanBook(booki);
  }



  // Output system
  int signupOrderCount = 0;
  for(auto li: signupOrder) if (lib[li].scan_books.size() > 0) signupOrderCount++;
  cout<<signupOrderCount<<endl;
  for(auto li: signupOrder) {
    //printf("%lld\n", li, lib[li].scan_books.size());
    if (lib[li].scan_books.size() == 0) continue;
    cout<<li<<' '<<lib[li].scan_books.size()<<'\n';

    for(auto &x: lib[li].scan_books) {
      //printf("%lld ", x);
      cout<<x<<' ';
      have_scores[x] = true;
    }

    //printf("\n");
    cout<<'\n';
  }

  // Show score
  int total_score = 0;
  for1(i,0,n) {
    if (have_scores[i]) total_score += scores[i];
  }
  cerr<<"SCORE "<<total_score<<endl;
  return 0;
}