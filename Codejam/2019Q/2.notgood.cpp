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
typedef pair<bool,bool> pbb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int n;
string rival;
map<pii,pbb> cannot; //cannot[{0,0}][0] = cannot go to right, [{0,0}][1] = cannot go down

void resolveCannot() {
  int cr = 0;
  int cc = 0;
  for1(i,0,rival.size()) {
    if (rival[i] == 'E') {
      cannot[{cr,cc}].first = true;
      cc++;
    } else if (rival[i] == 'S') {
      cannot[{cr,cc}].second = true;
      cr++;
    }
  }
}

string tocol(int col) {
  if (col<0) {cerr<<"BUGGED "<<n<<endl; return "BUGGED";}
  string res = "";
  int cr = 0;
  int cc = 0;
  while (cr<n-1 || cc<n-1) {
    //cerr<<cr<<' '<<cc<<endl;
    if (cr>n-1 || cc>n-1) break;
    if (cannot.find({cr,cc}) != cannot.end()) {
      if (cannot[{cr,cc}].first) {
        cr++;
        res += "S";
      } else if (cannot[{cr,cc}].second) {
        cc++;
        res += "E";
      } else {
        //cerr<<"BUGGED "<<n<<' '<<cr<<' '<<cc<<endl; return "BUGGED";
        if (cc<col) {
          cc++;
          res += "E";
        } else {
          if (cr < n-1) {
            cr++;
            res += "S";
          } else {
            cc++;
            res += "E";
          }
        }
      }
    } else {
      if (cc<col) {
        cc++;
        res += "E";
      } else {
        if (cr < n-1) {
          cr++;
          res += "S";
        } else {
          cc++;
          res += "E";
        }
      }
    }
  }
  
  if (cr != n-1 || cc != n-1) {
    return tocol(col-1);
  }
  
  return res;
}

string torow(int row) {
  if (row<0) {cerr<<"BUGGED "<<n<<endl; return "BUGGED";}
  string res = "";
  int cr = 0;
  int cc = 0;
  while (cr<n-1 || cc<n-1) {
    //cerr<<cr<<' '<<cc<<endl;
    if (cr>n-1 || cc>n-1) break;
    if (cannot.find({cr,cc}) != cannot.end()) {
      if (cannot[{cr,cc}].first) {
        cr++;
        res += "S";
      } else if (cannot[{cr,cc}].second) {
        cc++;
        res += "E";
      } else {
        //cerr<<"BUGGED "<<n<<' '<<cr<<' '<<cc<<endl; return "BUGGED";
        if (cr<row) {
          cr++;
          res += "S";
        } else {
          if (cc<n-1) {
            cc++;
            res += "E";
          } else {
            cr++;
            res += "S";
          }
        }
      }
    } else {
      if (cr<row) {
        cr++;
        res += "S";
      } else {
        if (cc<n-1) {
          cc++;
          res += "E";
        } else {
          cr++;
          res += "S";
        }
      }
    }
  }
  
  if (cr != n-1 || cc != n-1) {
    return torow(row-1);
  }
  
  return res;
}

string performrightright() {
  return tocol(n-2);
}

string performrightdown() {
  return tocol(n-1);
}

string performdownright() {
  return torow(n-1);
}

string performdowndown() {
  return torow(n-2);
}

int main() {
    cout<<fixed;
    int t; cin>>t;
    for1(_,1,t+1) {
      cannot.clear();
      cin>>n;
      cin>>rival;
      resolveCannot();
      cout<<"Case #"<<_<<": ";
      if (cannot[{0,0}].first && cannot[{n-1,n-2}].first) cout << performdowndown(); //down down
      else if (cannot[{0,0}].first && cannot[{n-2,n-1}].second) cout << performdownright();
      else if (cannot[{0,0}].second && cannot[{n-1,n-2}].first) cout << performrightdown();
      else if (cannot[{0,0}].second && cannot[{n-2,n-1}].second) cout << performrightright();
      cout<<endl;
    }
    return 0;
}