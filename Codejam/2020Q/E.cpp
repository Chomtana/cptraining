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

vector<vector<int>> square(100, vector<int>(100));

int n,k;
vector<vector<int>> ans;
bool impossible;

bool check(int r,int c) {
  for1(i,0,n) {
    if (i!=r) {
      if (square[i][c] == square[r][c]) return false;
    }

    if (i!=c) {
      if (square[r][i] == square[r][c]) return false;
    }
  }

  return true;
}

void f(int r,int c) {
  if (!impossible) return;

  if (r == n) {
    int sum = 0;
    for1(i,0,n) {
      sum += square[i][i];
    }

    if (sum == k) {
      ans = square;
      impossible = false;
    }

    return;
  }

  for1(i,1,n+1) {
    square[r][c] = i;
    if (check(r, c)) {
      if (c==n-1) {
        f(r+1,0);
      } else {
        f(r,c+1);
      }
    }
    square[r][c] = 0;
  }
}

int main() {
  cout << fixed;

  int t; cin>>t;
	for1(_,1,t+1) {
    cin>>n>>k;
    impossible = true;
    f(0,0);

    if (impossible) {
      cout<<"Case #"<<_<<": IMPOSSIBLE"<<'\n';
    } else {
      cout<<"Case #"<<_<<": POSSIBLE"<<'\n';
      for1(i,0,n) {
        for1(j,0,n) {
          printf("%d ",ans[i][j]);
        }
        printf("\n");
      }
    }
  }

  return 0;
}