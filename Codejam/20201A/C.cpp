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

vvi data(105, vector<ll>(105));
int nr,nc;

ll score() {
  ll res = 0;
  for1(i,0,nr) {
    for1(j,0,nc) {
      //cerr<<data[i][j]<<' ';
      if (data[i][j] != -1) res += data[i][j];
    }
  }

  return res;
}

double g(int r,int c) {
  if (r<0 || c<0 || r>=nr || c>=nc) return -1;
  return data[r][c];
}

double avg(int r, int c) {
  double sum = 0;
  double div = 0;
  for1(i,r+1,nr) {
    if (g(i,c) != -1) { sum += g(i,c); div++; break; }
  }
  for1(i,c+1,nc) {
    if (g(r,i) != -1) { sum += g(r,i); div++; break; }
  }
  for(int i = r-1;i>=0;i--) {
    if (g(i,c) != -1) { sum += g(i,c); div++; break; }
  }
  for(int i = c-1;i>=0;i--) {
    if (g(r,i) != -1) { sum += g(r,i); div++; break; }
  }

  if (div == 0) return -1;
  return sum/div;
}

int main() {
  cout << fixed;

  int t; cin>>t;
	for1(_,1,t+1) {
    cin>>nr>>nc;
    for1(i,0,nr) {
      for1(j,0,nc) {
        scanf("%lld", &data[i][j]);
      }
    }

    ll res = 0;
    bool next_round = true;
    while (next_round) {
      res += score();
      next_round = false;

      //cerr<<score()<<' '<<nr<<' '<<nc<<endl;

      vvi next = data;

      for1(i,0,nr) {
        for1(j,0,nc) {
          if (data[i][j] == -1) continue;
          double a = avg(i,j);
          //cerr<<i<<' '<<j<<' '<<a<<endl;
          if (a!=-1 && next[i][j] < a) {
            //printf("%d %d %d\n", i, j, data[i][j]);
            next[i][j] = -1;
            next_round = true;
          }
        }
      }

      data = next;
    }

    cout<<"Case #"<<_<<": "<<res<<'\n';
  }

  return 0;
}