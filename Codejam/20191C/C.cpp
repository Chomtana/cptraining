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

int nr,nc;
string data[105];
vector<string> initdata;
string currstate[105];

void restorestate() {
  for1(i,0,nr) {
    data[i] = currstate[i];
  }
}

void storestate() {
  for1(i,0,nr) {
    currstate[i] = data[i];
  }
}

//type = 0 : H else V
//0 for me return player <return value> win
bool recur(int r,int c,int type,int turn,vector<string> state) {
  //storestate();
  if (state[r][c] == '.') {
    state[r][c] = turn*2+type;
    for1(i,0,nr) {
      for1(j,0,nc) {
        if (state[i][j]<5) {
          if (state[i][j]%2 == 0) { //H
            if (j-1>=0) {
              if (state[i][j-1] == '.') {
                state[i][j-1] = state[i][j];
              } else if (state[i][j-1] == '#') {
                int cellplayer = state[i][j]/2;
                //restorestate();
                return (cellplayer==1?0:1);
              }
            }

            if (j+1 < nc) {
              if (state[i][j+1] == '.') {
                state[i][j+1] = state[i][j];
              } else if (state[i][j+1] == '#') {
                int cellplayer = state[i][j]/2;
                //restorestate();
                return (cellplayer==1?0:1);
              }
            }
          }

          if (state[i][j]%2 == 1) { //V
            if (i-1>=0) {
              if (state[i-1][j] == '.') {
                state[i-1][j] = state[i][j];
              } else if (state[i-1][j] == '#') {
                int cellplayer = state[i][j]/2;
                //restorestate();
                return (cellplayer==1?0:1);
              }
            }

            if (i+1 < nr) {
              if (state[i+1][j] == '.') {
                state[i+1][j] = state[i][j];
              } else if (state[i+1][j] == '#') {
                int cellplayer = state[i][j]/2;
                //restorestate();
                return (cellplayer==1?0:1);
              }
            }
          }
        }

      }
    }

    //donext
    bool hasempty = false;
    int res = turn;
    for1(i,0,nr) {
      for1(j,0,nc) {
        if (state[i][j]=='.') {
          hasempty = true;
        }
        for1(k,0,2) {
          int winplayer = recur(i,j,k,(turn==1?0:1),state);
          if (winplayer == (turn==1?0:1)) {
            res = (turn==1?0:1);
          }
        }
      }
    }

    if (!hasempty) { 
      /*for1(i,0,nr) {
        for1(j,0,nc) {
          if(state[i][j]>5) {
            cerr<<state[i][j];
          } else {
            cerr<<(int)state[i][j];
          }
        }
        cerr<<endl;
        
      }
      cerr<<endl;*/
      //restorestate();
      return turn;
    }

    return res;

  } else if (state[r][c] == '#') {
    return (turn==1?0:1);
  } else {
    return -1;
  }
  return -1;
}

int main() {
  cout << fixed;

  int t; cin>>t;
	for1(_,1,t+1) {
    cin>>nr>>nc;
    initdata.clear();
    initdata.resize(nr);
    for1(i,0,nr) {
      cin>>data[i];
      initdata[i] = data[i];
    }

    int wincount = 0;

    for1(i,0,nr) {
      for1(j,0,nc) {
        for1(k,0,nr) {
          data[i] = initdata[i];
        }
        if (data[i][j] == '.') {
          int doh = recur(i,j,0,0,initdata);
          int dov = recur(i,j,1,0,initdata);
          wincount += doh == 0;
          wincount += dov == 0;

          cerr<<i<<' '<<j<<' '<<doh<<' '<<dov<<endl;
        }
      }
    }


    cout<<"Case #"<<_<<": "<<wincount<<endl;
  }

  return 0;
}