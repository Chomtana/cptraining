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
typedef pair<ll,ll> pii;
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

class FlexBi {
  public:
    double s;
    double mid;
    double e;
    double losslevel;

    FlexBi(double mid) {
      this->s = this->e = this->mid = mid;
      losslevel = 0.1;
    }

    move(bool moveup) {
      double pmid = this->mid;
      //console.log(s,e,mid);
      if (moveup) {
        mid = (pmid+e)/2;
        s = (s+mid)/2;
      } else {
        mid = (pmid+s)/2;
        e = (e+mid)/2;
      }
      
      double dists = abs(s-mid);
      double diste = abs(e-mid);
      double distse = abs(s-e);
      if (dists <= mid*losslevel) {
        s /= 2;
      }
      if (diste <= mid*losslevel) {
        e *= 2;
      }
      
      pmid = mid;
    }

    up() {
      move(true);
    }

    down() {
      move(false);
    }

    up(int percent) {
      if (rand()%100 < percent) {
        up();
      } else {
        down();
      }
    }

    down(int percent) {
      if (rand()%100 < percent) {
        down();
      } else {
        up();
      }
    }
    
};

class Bi {
  public:
    ll s;
    ll mid;
    ll e;

    Bi(ll s,ll e) {
      this->s = s;
      this->e = e;
      this->mid = (s+e)/2;
    }

    move(bool moveup) {
      mid = (s+e)/2;
      if (moveup) {
        s = mid+1;
      } else {
        e = mid-1;
      }
    }

    up() {
      move(true);
    }

    down() {
      move(false);
    }

    up(int percent) {
      if (rand()%100 < percent) {
        up();
      } else {
        down();
      }
    }

    down(int percent) {
      if (rand()%100 < percent) {
        down();
      } else {
        up();
      }
    }
    
};


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

int n;
map<string,vector<int>> in;
vector<vector<string>> intag;
vector<int> avail;
deque<string> tagorder;
map<int,int> Vpair;

vector<pii> ans;

/*ll solveOneSlide() {
  if (tagorder.size() >= 3) {
    string common = tagorder[0];
    vector<int> piclist;
    foreach(x,in[common]) {
      if (avail.find(x) != avail.end()) {
        piclist.push_back(x);
      }
    }

    vardump(piclist);
  }
}*/

ll calValue(int a,int b) {
  //cerr<<"test"<<endl;

  vector<string>& atag = intag[a]; //foreach(x,intag[a]) atag.push_back(x);
  vector<string>& btag = intag[b]; //foreach(x,intag[b]) btag.push_back(x);
  vector<string> intersect(max(atag.size(),btag.size()));
  vector<string> adif(max(atag.size(),btag.size()));
  vector<string> bdif(max(atag.size(),btag.size()));

  sort(all(atag));
  sort(all(btag));

  //cerr<<atag.size()<<endl;
  //cerr<<btag.size()<<endl;

  ll intersectscore = set_intersection(all(atag),all(btag),intersect.begin()) - intersect.begin();
  ll adifscore = set_difference(all(atag),all(btag),adif.begin()) - adif.begin();
  ll bdifscore = set_difference(all(btag),all(atag),bdif.begin()) - bdif.begin();

  //cerr<<intersectscore<<' '<<adifscore<<' '<<bdifscore<<endl;
  return min(min(intersectscore,adifscore),bdifscore);
}

ll solveOneSlide() {
  ll currmax = 0;
  int maxa = 0;
  int maxb = 0;
  
  int bloop = 0;

  cerr<<avail.size()<<endl;

  for1(i,0,min(100,(int)avail.size())) {
    for1(j,0,min(100,(int)avail.size())) {
      int a = avail[i];
      int b = avail[j];
      if (a!=b) {
        ll value = calValue(a,b);
        if (value>=currmax) {
          currmax = value;
          maxa = a;
          maxb = b;
        }
      }
    }
  }

  //cerr<<maxa<<' '<<maxb<<endl;

  if (maxa != maxb) {
    ans.push_back({maxa,-1});
    ans.push_back({maxb,-1});
    avail.erase(find(all(avail),maxa));
    avail.erase(find(all(avail),maxb));
  }
}

int main() { 
  cout<<fixed;

  int lastV = -1;
  
  cin >> n;
  for1(i,0,n) {
    char type; cin>>type;
    int ntag; scanf("%d",&ntag);
    intag.push_back(vector<string>());
    if (i%1000 == 0) cerr<<i<<endl;
    for1(j,0,ntag) {
      string tag; cin>>tag;
      //in[tag].push_back(i);
      //tagorder.push_back(tag);
      intag[i].push_back(tag);
    }

    if (type=='H') {
      avail.push_back(i);
    } else {
      if (lastV == -1) {
        lastV = i;
      } else {
        foreach(x, intag[i]) intag[lastV].push_back(x);
        avail.push_back(lastV);
        Vpair[lastV] = i;
        lastV = -1;
      }
    }
  }

  //sort(all(tagorder));
  //tagorder.resize(unique(all(tagorder))-tagorder.begin());

  //vardump(tagorder);

  /*while(avail.size()>0) {
    solveOneSlide();
  }*/

  

  //while(true) {
    ll value = 0;

    //cerr<<"dasasdasd"<<endl;
    //cerr<<avail.size()<<endl;

    //random_shuffle(all(avail));

    

    for1(i,0,avail.size()-1) {
      value += calValue(avail[i],avail[i+1]);
    }

    cerr<<"Value : "<<value<<endl;
  //}

  cout<<avail.size()<<endl;
  foreach(x,avail) {
    printf("%d",x);
    if (Vpair.find(x) != Vpair.end()) {
      printf(" %d",Vpair[x]);
    }
    printf("\n");
  }



  //calValue(1,2);




    
  return 0;
}