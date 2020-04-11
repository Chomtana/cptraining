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

    int fullscore = 0;

    void addBook(int bookid) {
      books.push_back(bookid);
    }

    int signUp(int lastSignup) {
      currday = lastSignup + signup + 1;
      return currday - 1;
    }

    int scanBook(int bookid) {
      if (currday >= days) return -1;

      scan_books.push_back(bookid);
      round_scan_books++;

      if (round_scan_books == ship) {
        currday++;
        round_scan_books = 0;
      }

      return currday;
    }

    void calfullscore() {
      sort(all(books), [] (auto a, auto b) {
        return scores[a] > scores[b];
      });

      for(auto i: books) {
        if (scanBook(i) != -1) {
          fullscore += scores[i];
        }
      }

      reset();
    }

    void reset() {
      currday = 0;
      scan_books.clear();
      round_scan_books = 0;
    }
};

vector<Lib> lib(100005);

vector<int> signupOrder;

vector<int> book2lib[100005];

int overall_max = 0;

template<typename T>
void sorter(vector<T>& v, initializer_list<double(T)> support, initializer_list<double(T)> anti) {
  vector<double> support_w(support.size(), 0);
  vector<double> anti_w(anti.size(), 0);

  for1(i,0,support_w.size()) support_w[i] = rand();
  for1(i,0,anti_w.size()) anti_w[i] = rand();

  sort(all(v), [&](auto a, auto b) {
    
  });
}

intonly main() {
  srand(time(0));
  int uniqid = rand()%1000;
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

    l.calfullscore();
    lib[li] = l;
  }

  while (true) {

    // Sort book2lib[bookid] by uniqueness value = lib[...].bookn
    for1(i,0,n) {
      sort(all(book2lib[i]), [] (int a, int b) {
        return lib[a].bookn < lib[b].bookn;
      });
    }
    
    
    // start code
    for1(i,0,nl) {
      signupOrder.push_back(i);
    }

    double mysw = ((double) rand() / (RAND_MAX));
    mysw *= 10;

    double mysw2 = ((double) rand() / (RAND_MAX));
    mysw2 *= 10;

    double mysw3 = ((double) rand() / (RAND_MAX));
    mysw3 *= 1.5;

    sort(all(signupOrder), [mysw, mysw2, mysw3](auto a, auto b) {
      // if (lib[a].signup == lib[b].signup)
      // {
      // return lib[a].ship < lib[b].ship;
      // }
      return mysw3*(double)lib[a].signup - mysw * ((double)lib[a].fullscore / (double)lib[a].signup) - mysw2 * ((double)lib[a].bookn / (double)lib[a].ship) < mysw3*(double)lib[b].signup - mysw * ((double)lib[b].fullscore / (double)lib[b].signup) - mysw2 * ((double)lib[b].bookn / (double)lib[b].ship);
    });

    //random swap
    for1(i,0,signupOrder.size()) {
      if (rand() % 101 < 25) {
        swap(signupOrder[i], signupOrder[max(0ll, i - rand()%((i+2)/2))]);
      }
    }

    vector<int> postSignup;

    // Simulate signup
    int lastSignup = -1;
    for(auto &li: signupOrder) {
      if (rand() % 101 < rand() % 5) {
        postSignup.push_back(li);
        continue;
      }
      lastSignup = lib[li].signUp(lastSignup);
    }
    for(auto &li: postSignup) {
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
    for1(i,0,n) have_scores[i] = false;

    // Show score
    for(auto li: signupOrder) {
      if (lib[li].scan_books.size() == 0) continue;

      for(auto &x: lib[li].scan_books) {
        have_scores[x] = true;
      }
    }

    int total_score = 0;
    for1(i,0,n) {
      if (have_scores[i]) total_score += scores[i];
    }
    cerr<<"SCORE "<<total_score<<endl;

    if (total_score > overall_max) {
      overall_max = total_score;
      cerr<<"MAX "<<overall_max<<endl;

      stringstream fname;
      fname<<uniqid<<"out"<<total_score<<".out";

      ofstream outfile;
      outfile.open(fname.str());

      int signupOrderCount = 0;
      for(auto li: signupOrder) if (lib[li].scan_books.size() > 0) signupOrderCount++;
      outfile<<signupOrderCount<<endl;
      for(auto li: signupOrder) {
        //printf("%lld\n", li, lib[li].scan_books.size());
        if (lib[li].scan_books.size() == 0) continue;
        outfile<<li<<' '<<lib[li].scan_books.size()<<'\n';

        for(auto &x: lib[li].scan_books) {
          //printf("%lld ", x);
          outfile<<x<<' ';
          have_scores[x] = true;
        }

        //printf("\n");
        outfile<<'\n';
      }
    }

    for1(i,0,nl) lib[i].reset();
    signupOrder.clear();
  }


  return 0;
}