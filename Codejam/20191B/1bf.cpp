#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define foreach(i,a) for (auto const& (i) : (a))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args
#define vardump(name, ...) vardump_(#name, name, ##__VA_ARGS__)

#define vardump_func_const(type) \
inline void vardump_(string name,type a) { \
  vardump_printname(name);\
  cout<<a; \
  if (name!="-") cout<<endl; \
}

#define vardump_func_arr1D(type) \
inline void vardump_(string name,type* a,int size) { \
  vardump_printname(name);\
  for1(i,0,size) {\
    vardump_("-",*(a+i));\
    cout<<" "; \
  }\
  if (name!="-") cout<<endl; \
}

#define vardump_func_arr2D(type) \
inline void vardump_(string name,type a[][1000],int nr,int nc) { \
  vardump_printname(name);\
  cout<<endl;\
  for1(i,0,nr) { \
    cout<<"   ";\
    vardump_("-",a[i],nc);\
    cout<<endl; \
  }  \
  if (name!="-") cout<<endl; \
}

#define vardump_func_cpp_arr1D(type,ds) \
inline void vardump_(string name,ds<type> a) { \
  vardump_printname(name);\
  for1(i,0,a.size()) { \
    vardump_("-",a[i]);\
    cout<<" "; \
  }\
  if (name!="-") cout<<endl; \
}\
\
inline void vardump_(string name,ds<type> a,int size) { \
  vardump_printname(name);\
  for1(i,0,size) { \
    vardump_("-",a[i]);\
    cout<<" "; \
  }\
  if (name!="-") cout<<endl; \
}\

#define vardump_func_cpp_arr2D(type,ds) \
inline void vardump_(string name,ds<ds<type>> a) { \
  vardump_printname(name);\
  cout<<endl;\
  for1(i,0,a.size()) { \
    cout<<"   ";\
    vardump_("-",a[i],a[i].size());\
    cout<<endl; \
  }  \
  if (name!="-") cout<<endl; \
}\
\
inline void vardump_(string name,ds<ds<type>> a,int nr,int nc) { \
  vardump_printname(name);\
  cout<<endl;\
  for1(i,0,nr) { \
    cout<<"   ";\
    vardump_("-",a[i],nc);\
    cout<<endl; \
  }  \
  if (name!="-") cout<<endl; \
}\

#define vardump_func(type) \
  vardump_func_const(type)\
  vardump_func_arr1D(type)\
  vardump_func_arr2D(type)\
  vardump_func_cpp_arr1D(type,vector)\
  vardump_func_cpp_arr2D(type,vector)\
  vardump_func_cpp_arr1D(type,deque)\
  vardump_func_cpp_arr2D(type,deque)\

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

inline void vardump_printname(string& name) {
  if (name=="-") return;
  cout<<"   $ "<<name<<"\t: ";
}

vardump_func(char)
vardump_func(int)
vardump_func(ll)
vardump_func(string)

struct type {
  int x,y;
  char dir;
  int i;
};

map<pii,set<int>> res;
int p,q;
vector<type> dataN;
vector<type> dataS;
vector<type> dataE;
vector<type> dataW;
vector<vector<int>> mup(1000,vector<int>(1000,0));

int main() {
  cout<<fixed;
  int t; cin>>t;
	for1(_,1,t+1) {
    res.clear();
    dataN.clear();
    dataS.clear();
    dataE.clear();
    dataW.clear();
    mup.clear();
    mup.resize(1000,vector<int>(1000,0));

    
    cin>>p>>q;
    for1(i,0,p) {
      type d;
      cin>>d.x>>d.y>>d.dir;
      d.i = i;
      if (d.dir == 'N') {
        //d.x = 0;
        dataN.push_back(d);
        res[{0,d.y+1}].insert(i);
        for1(y,d.y+1,q+1) {
          for1(x,0,q+1) {
            mup[x][y]++;
          }
        }
      } else if (d.dir == 'S') {
        //d.x = 0;
        dataS.push_back(d);
        //res[{d.x,d.y-1}]++;
        res[{0,0}].insert(i);
        for1(y,0,d.y) {
          for1(x,0,q+1) {
            mup[x][y]++;
          }
        }
      } else if (d.dir == 'E') {
        //d.y = 0;
        dataE.push_back(d);
        res[{d.x+1,0}].insert(i);
        for1(x,d.x+1,q+1) {
          for1(y,0,q+1) {
            mup[x][y]++;
          }
        }
      } else if (d.dir == 'W') {
        //d.y = 0;
        dataW.push_back(d);
        //res[{d.x-1,d.y}]++;
        res[{0,0}].insert(i);
        for1(x,0,d.x) {
          for1(y,0,q+1) {
            mup[x][y]++;
          }
        }
      }
      

    }

    foreach(a,dataE) {
      set<pii> point;
      foreach(b,dataN) {
        //type& a = data[i];
        //type& b = data[j];
        //if (a.x<b.x && a.y>b.y) {
          res[{a.x+1,b.y+1}].insert(a.i);
          res[{a.x+1,b.y+1}].insert(b.i);
          //point.insert({b.x,a.y});
        /*} else if (a.x>b.x && a.y<b.y) {
          res[{a.x,b.y}]++;
        }*/
      }
      foreach(p,point) {
        //res[p]++;
      }
    }

    foreach(a,dataE) {
      set<pii> point;
      foreach(b,dataS) {
        //type& a = data[i];
        //type& b = data[j];
        //if (a.x<b.x && a.y<b.y) {
          res[{a.x+1,b.y-1}].insert(a.i);
          res[{a.x+1,b.y-1}].insert(b.i);
          //point.insert({b.x,a.y});
        /*} else if (a.x>b.x && a.y>b.y) {
          res[{a.x,b.y}]++;
        }*/
      }
      foreach(p,point) {
        //res[p]++;
      }
    }

    foreach(a,dataW) {
      set<pii> point;
      foreach(b,dataN) {
        //type& a = data[i];
        //type& b = data[j];
        //if (a.x>b.x && a.y>b.y) {
          res[{a.x-1,b.y+1}].insert(a.i);
          res[{a.x-1,b.y+1}].insert(b.i);
          //point.insert({b.x,a.y});
        /*} else if (a.x>b.x && a.y<b.y) {
          res[{a.x,b.y}]++;
        }*/
      }
      foreach(p,point) {
        //res[p]++;
      }
    }

    foreach(a,dataW) {
      set<pii> point;
      foreach(b,dataS) {
        //type& a = data[i];
        //type& b = data[j];
        //if (a.x>b.x && a.y<b.y) {
          res[{a.x-1,b.y-1}].insert(a.i);
          res[{a.x-1,b.y-1}].insert(b.i);
          //point.insert({b.x,a.y});
        /*} else if (a.x>b.x && a.y>b.y) {
          res[{a.x,b.y}]++;
        }*/
      }
      foreach(p,point) {
        //res[p]++;
      }
    }

    foreach(a,dataE) {
      foreach(b,dataW) {
        if (b.x > a.x+1 && b.y==a.y) {
          res[{a.x+1,0}].insert(a.i);
          res[{a.x+1,0}].insert(b.i);
        }
      }
    }

    foreach(a,dataN) {
      foreach(b,dataS) {
        if (b.y > a.y+1 && b.x==a.x) {
          res[{0,a.y+1}].insert(a.i);
          res[{0,a.y+1}].insert(b.i);
        }
      }
    }

    int currmax = 0;
    pii ans = {0,0};



    /*foreach(x,res) {
      //cerr<<"aaa "<<x.first.first<<' '<<x.first.second<<' '<<x.second.size()<<endl;
      if (x.second.size() > currmax) {
        currmax = x.second.size();
        ans = x.first;
      } else if (x.second.size() == currmax) {
        if (x.first.first < ans.first) {
          ans = x.first;
        } else if (x.first.first == ans.first) {
          if (x.first.second < ans.second) {
            ans = x.first;
          }
        }
      }
    }*/

    for1(i,0,q+1) {
      for1(j,0,q+1) {
        if (mup[i][j]>currmax) {
          currmax = mup[i][j];
          ans = {i,j};
        }
      }
    }

    cout<<"Case #"<<_<<": ";
    cout<<ans.first<<' '<<ans.second<<endl;
  }
}