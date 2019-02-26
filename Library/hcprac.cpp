#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args
#define vardump(name, ...) vardump_(#name, name, ##__VA_ARGS__)

#define vardump_func_const(type) \
inline void vardump_(string name,type a,int size) { \
  vardump_printname(name);\
  cout<<a; \
  cout<<endl; \
}

#define vardump_func_arr1D(type) \
inline void vardump_(string name,type* a,int size) { \
  vardump_printname(name);\
  for1(i,0,size) cout<<*(a+i)<<" "; \
  cout<<endl; \
}

#define vardump_func_arr2D(type) \
inline void vardump_(string name,type a[][1000],int nr,int nc) { \
  vardump_printname(name);\
  cout<<endl;\
  for1(i,0,nr) { \
    cout<<"   ";\
    for1(j,0,nc) { \
      cout<<*(*(a+i)+j)<<" "; \
    } \
    cout<<endl; \
  }  \
  cout<<endl; \
}

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

inline void vardump_printname(string& name) {
  cout<<"   $ "<<name<<"\t: ";
}

vardump_func_arr1D(char)
vardump_func_arr2D(char)

class Num1D: public vector<ll> {
  private:
    typedef vector<ll> super;
    
  public:
    vector<ll> qs;
    vector<ll> qmaxl; //quick max start from left (index 0)
    vector<ll> qmaxr; //quick max start from right
    vector<ll> qminl;
    vector<ll> qminr;
    
    Num1D() {
      refresh();
    }
    
    Num1D(vector<ll> v): super(v) {
      refresh();
    }
    
    Num1D(int size): super(size) {
      refresh();
    }
    
    Num1D(int size,ll initval): super(size,initval) {
      refresh();
    }
    
    void refresh_qs() {
      qs.clear();
      qs.resize(size());
      qs[0] = 0;
      for1(i,1,size()) {
        qs[i] = qs[i-1]+at(i);
      }
    }
    
    void refresh_qmaxl() {
      qmaxl.clear();
      qmaxl.resize(size());
      qmaxl[0] = at(0);
      for1(i,1,size()) {
        qmaxl[i] = max(qmaxl[i-1],at(i));
      }
    }
    
    void refresh_qmaxr() {
      qmaxr.clear();
      qmaxr.resize(size());
      qmaxr[size()-1] = back();
      for(int i = size()-2;i>=0;i--) {
        qmaxr[i] = max(qmaxr[i+1],at(i));
      }
    }
    
    void refresh_qminl() {
      qminl.clear();
      qminl.resize(size());
      qminl[0] = at(0);
      for1(i,1,size()) {
        qminl[i] = min(qminl[i-1],at(i));
      }
    }
    
    void refresh_qminr() {
      qminr.clear();
      qminr.resize(size());
      qminr[size()-1] = back();
      for(int i = size()-2;i>=0;i--) {
        qminr[i] = min(qminr[i+1],at(i));
      }
    }
    
    void refresh() {
      refresh_qs();
      refresh_qmaxl();
      refresh_qmaxr();
      refresh_qminl();
      refresh_qminr();
    }
    
    ll sum(int start,int end) {
      if (start==0) return qs.at(end);
      return qs.at(end)-qs.at(start-1);
    }
    
    ll maxl(int right) {
      return qmaxl.at(right);
    }
    
    ll maxr(int left) {
      return qmaxr.at(left);
    }
    
    ll minl(int right) {
      return qminl.at(right);
    }
    
    ll minr(int left) {
      return qminr.at(left);
    }
};

class Num2D: public vector<vector<ll>> {
  private:
    typedef vector<vector<ll>> super;
    
  public:
    vector<vector<ll>> qs;
  
    Num2D() {
      refresh();
    }
    
    Num2D(vector<vector<ll>> v): super(v) {
      refresh();
    }
    
    Num2D(int row,int col): super(row,vector<ll>(col)) {
      refresh();
    }
    
    Num2D(int row,int col,ll initval): super(row,vector<ll>(col,initval)) {
      refresh();
    }
    
    void refresh_qs() {
      int nr = size();
      int nc = at(0).size();
      qs.clear();
      qs.resize(nr,vector<ll>(nc,0));
      qs[0][0] = 0;
      for1(i,1,nr) {
        qs[i][0] = qs[i-1][0]+at(i).at(0);
      }
      for1(i,1,nc) {
        qs[0][i] = qs[0][i-1]+at(0).at(i);
      }
      for1(i,1,nr) {
        for1(j,1,nc) {
          qs[i][j] = qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1] + at(i).at(j);
        }
      }
    }
    
    void refresh() {
      refresh_qs();
    }
    
    ll sum(int sr,int sc,int er,int ec) {
      if (sr==0 && sc==0) {
        return qs.at(er).at(ec);
      } else if (sr==0) {
        return qs.at(er).at(ec) - qs.at(er).at(sc-1);
      } else if (sc==0) {
        return qs.at(er).at(ec) - qs.at(sr-1).at(ec);
      } else {
        return qs.at(er).at(ec) - qs.at(er).at(sc-1) - qs.at(sr-1).at(ec) + qs.at(sr-1).at(sc-1);
      }
    }
};

char in[1000][1000];
int nr,nc,mininb,maxinb;

int main() {
  cout<<fixed;
  
  cin >> nr >> nc >> mininb >> maxinb;
  
  for1(i,0,nr) {
    for1(j,0,nc) {
      cin>>in[i][j];
    }
  }
  
  vardump(in,nr,nc);
  
  
    
  return 0;
}