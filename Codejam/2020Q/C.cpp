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

pair<pii, int> a[10000];

int main() {
  cout << fixed;

  int t; cin>>t;
	for1(_,1,t+1) {
    int n; cin>>n;
    
    for1(i,0,n) {
      scanf("%d %d",&a[i].first.first, &a[i].first.second);
      a[i].second = i;
    }

    sort(a,a+n,[](auto a, auto b) {
      if (a.first.second == b.first.second) return a.first.first < b.first.first;
      return a.first.second < b.first.second;
    });

    vector<int> C;
    vector<int> J;
    int ce = 0;
    int je = 0;

    bool impossible = false;

    for1(i,0,n) {
      if (a[i].first.first >= ce && a[i].first.first >= je) {
        if (ce > je) {
          ce = a[i].first.second;
          C.push_back(a[i].second);
        } else {
          je = a[i].first.second;
          J.push_back(a[i].second);
        }
      } else if (a[i].first.first >= ce) {
        ce = a[i].first.second;
        C.push_back(a[i].second);
      } else if (a[i].first.first >= je) {
        je = a[i].first.second;
        J.push_back(a[i].second);
      } else {
        impossible = true;
        break;
      }
    }

    if (impossible) {
      cout<<"Case #"<<_<<": IMPOSSIBLE"<<'\n';
    } else {
      vector<char> res(n);
      for(auto c: C) res[c] = 'C';
      for(auto j: J) res[j] = 'J';
      string ress = "";
      for1(i,0,n) ress += res[i];
      cout<<"Case #"<<_<<": "<<ress<<'\n';
    }
  }

  return 0;
}