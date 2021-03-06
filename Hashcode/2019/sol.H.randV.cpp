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
map<string,int> tagi;
vector<vector<int>> intag;
set<pii,greater<pii>> avail;
vector<int> Vavail;
deque<string> tagorder;
map<int,int> Vpair;
vector<bool> isH;

vector<pii> ans;

ll totalvalue = 0;

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

vector<int> intersect(100000);
vector<int> un(100000);

ll calValue(int a,int b) {
  //cerr<<"test"<<endl;

  vector<int>& atag = intag[a]; //foreach(x,intag[a]) atag.push_back(x);
  vector<int>& btag = intag[b]; //foreach(x,intag[b]) btag.push_back(x);
  //vector<int> intersect(max(atag.size(),btag.size())); //we define outer instead to make it fast by don't need to initial new vector each time (fast by 2 time)
  //vector<int> adif(max(atag.size(),btag.size()));
  //vector<int> bdif(max(atag.size(),btag.size()));

  //sort(all(atag));
  //sort(all(btag));

  //cerr<<atag.size()<<endl;
  //cerr<<btag.size()<<endl;

  ll intersectscore = set_intersection(all(atag),all(btag),intersect.begin()) - intersect.begin();
  //ll adifscore = set_difference(all(atag),all(btag),adif.begin()) - adif.begin();
  //ll bdifscore = set_difference(all(btag),all(atag),bdif.begin()) - bdif.begin();

  //cerr<<intersectscore<<' '<<adifscore<<' '<<bdifscore<<endl;
  return min(atag.size()-intersectscore,min(intersectscore,btag.size()-intersectscore));
}

int lastpic = 0;

ll solveOneSlide() {
  ll currmax = -1;
  int maxa = 0;
  int maxb = 0;
  
  int bloop = 0;

  //if (ans.size()%1000 == 0) 
  if(ans.size()%1000==0) cerr<<avail.size()<<endl;

  foreach(bb,avail) {
    int a = lastpic;
    int b = bb.second;
    //vardump(intag[b]);
    if(bb.first<currmax) break;

    if (a!=b) {
      ll value = calValue(a,b);
      if (value>=currmax) {
        currmax = value;
        maxa = a;
        maxb = b;
      }
    }

    bloop++;

    if (bloop>1000) {
      break;
    }
  }

  //cerr<<maxa<<' '<<maxb<<endl;

  /*vardump(intag[maxa]);
  vardump(intag[maxb]);*/
  //if (ans.size()%1000 == 0)
  if(ans.size()%1000==0) cerr<<"Value "<<currmax<<endl;

  totalvalue += currmax;

  if (maxa != maxb) {
    //ans.push_back({maxa,-1});
    ans.push_back({maxb,-1});
    //avail.erase(find(all(avail),maxa));
    avail.erase(avail.find({intag[maxb].size(),maxb}));
    lastpic = maxb;
  }
}

void fusionOneV() {
  int a = Vavail.back();
  Vavail.pop_back();
  int b = Vavail.back();
  Vavail.pop_back();

  auto un_end = set_union(all(intag[a]),all(intag[b]),un.begin());
  ll currmax = un_end - un.begin();
  int maxa = a;
  int maxb = b;

  intag[maxa] = vector<int>(un.begin(),un_end);
  avail.insert({intag[maxa].size(),maxa});
  isH[maxa] = true;
  Vpair[maxa] = maxb;
}

int main() {
  cout<<fixed;

  string _filename; cin>>_filename;
  ll bestvalue = 0;

  std::srand ( unsigned ( std::time(0) ) );

  while (true) {

    //reset
    totalvalue = 0; 
    avail.clear();
    Vavail.clear();
    intag.clear();
    ans.clear();
    isH.clear();

    int lastV = -1;
    int tagicurr = 1;

    ifstream infile(_filename+".txt");
    ifstream prevoutfile(_filename+".out");
    
    infile >> n;
    
    for1(i,0,n) {
      char type; infile>>type;
      int ntag; infile>>ntag;
      intag.push_back(vector<int>());
      //if (i%1000 == 0) cerr<<i<<endl;
      for1(j,0,ntag) {
        string tag; infile>>tag;
        if (tagi.find(tag) == tagi.end()) tagi[tag] = tagicurr++;
        //in[tag].push_back(i);
        //tagorder.push_back(tag);
        intag[i].push_back(tagi[tag]);
      }

      sort(all(intag[i]));

      if (type=='H') {
        avail.insert({intag[i].size(),i});
        isH.push_back(true);
      } else {
        //avail.insert(i);
        Vavail.push_back(i);
        isH.push_back(false);
      }
    }

    random_shuffle(all(Vavail));

    while (Vavail.size()>1) {
      fusionOneV();
    }

    ll begincurrmax = 0;
    ll begini = 0;
    
    foreach(xx,avail) {
      int x = xx.second;
      if (intag[x].size()>begincurrmax) {
        begincurrmax = intag[x].size();
        begini = x;
      }
    }

    cerr<<"Initial avail size : "<<avail.size()<<endl;

    ans.push_back({begini,-1});
    avail.erase(avail.find({intag[begini].size(),begini}));

    /*foreach(x,avail) {
      vardump(intag[x.second]);
    }*/

    /*foreach(x,tagi) {
      cerr<<x.first<<' '<<x.second<<endl;
    }*/

    //sort(all(tagorder));
    //tagorder.resize(unique(all(tagorder))-tagorder.begin());

    //vardump(tagorder);

    while(avail.size()>1) {
      solveOneSlide();
    }

    cerr<<"================ Finished ========================="<<endl;

    if (avail.size()==1) {
      ans.push_back({avail.begin()->second,-1});
      totalvalue += calValue(ans.back().first,avail.begin()->second);
    }

    cerr<<"Total value : "<<totalvalue<<endl;
    
    if (totalvalue>bestvalue) {
      ofstream resfile (_filename+"_grandmaster"+to_string(totalvalue)+".out");
      bestvalue = totalvalue;
      resfile<<ans.size()<<endl;
      foreach(x,ans) {
        resfile<<x.first;
        if (Vpair.find(x.first) != Vpair.end()) {
          resfile<<' '<<Vpair[x.first];
        }
        resfile<<endl;
      }
      resfile.close();
    }

    infile.close();
    
    prevoutfile.close();
    

    cerr<<"Best value : "<<bestvalue<<endl;

    /*vector<int> bestavail;
    ll valuemax = -1;

    for1(_,0,100) {
      ll value = 0;

      //cerr<<"dasasdasd"<<endl;
      //cerr<<avail.size()<<endl;
      cerr<<"Random "<<_<<endl;

      random_shuffle(all(avail));

      bestavail = avail;

      for1(i,0,avail.size()-1) {
        value += calValue(avail[i],avail[i+1]);
      }

      cerr<<"Value : "<<value<<endl;
    }*/

    /*cout<<avail.size()<<endl;
    foreach(x,avail) {
      printf("%d",x);
      if (Vpair.find(x) != Vpair.end()) {
        printf(" %d",Vpair[x]);
      }
      printf("\n");
    }*/



    //calValue(1,2);


  }

    
  return 0;
}