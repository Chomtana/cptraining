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

ll lcm(ll a,ll b) {
  return (a*b)/__gcd(a,b);
}

string data[10005];
ll realsize[10005];
bool isout[10005];
int n; 

void out(int pos,char c) {
  for1(i,0,n) {
    if (data[i][pos] == c) {
      isout[i] = true;
    }
  }
}

int main() {
  cout << fixed; 

  int t; cin>>t;
	for1(_,1,t+1) {
    cin>>n;
    for1(i,0,n+5) isout[i] = false;
    ll maxlen = 500;
    for1(i,0,n) {
      cin>>data[i];
      //maxlen = max((ll)data[i].size(),maxlen);
      //maxlen = lcm((ll)data[i].size(),maxlen);
    }
    for1(i,0,n) {
      int j = 0;
      realsize[i] = data[i].size();
      while(data[i].size()<maxlen) {
        data[i] += data[i][j];
        j++;
        j%=realsize[i];
      }
    }
    /*for1(i,0,n) {
      vardump(data[i]);
    }*/

    string ans = "";
    bool possible = true;
    bool hasalwayswin = false;

    for1(i,0,maxlen) {
      bool hass = false;
      bool hasr = false;
      bool hasp = false;
      bool allout = true;
      for1(j,0,n) {
        if (isout[j]) continue;
        allout = false;
        if (data[j][i] == 'S') hass = true;
        if (data[j][i] == 'P') hasp = true;
        if (data[j][i] == 'R') hasr = true;
      }
      if (allout) break;
      if (hass && hasr && hasp) {
        possible = false;
        break;
      }
      if (hass && hasr) {
        ans += "R";
        out(i,'S');
        continue;
      }
      if (hass && hasp) {
        ans += "S";
        out(i,'P');
        continue;
      }
      if (hasr && hasp) {
        ans += "P";
        out(i,'R');
        continue;
      }
      if (hass) {
        ans += "R";
        out(i,'S');
        hasalwayswin = true;
        continue;
      }
      if (hasr) {
        ans += "P";
        out(i,'R');
        hasalwayswin = true;
        continue;
      }
      if (hasp) {
        ans += "S";
        out(i,'P');
        hasalwayswin = true;
        continue;
      }
    }

    bool allout = true;
    for1(j,0,n) {
      if (isout[j]) continue;
      allout = false;
    }

    if (!allout) possible = false;

    if (!possible) {
      cout<<"Case #"<<_<<": IMPOSSIBLE"<<endl;
    } else {
      cout<<"Case #"<<_<<": "<<ans<<endl;
    }
  }

  return 0;
}