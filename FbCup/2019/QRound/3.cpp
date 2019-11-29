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

int currnodeid = 1;
int dp[100000][2];

class node {
  public:
    node* left = NULL;
    node* right = NULL;
    char expr;
    int id;

    node() {
      id = currnodeid++;
    }
};

string expr;
node* root = NULL;

bool isdigit(char x) {
  return x >= '0' && x<='9';
}

bool isx(char x) {
  return x == 'x' || x=='X';
}

bool isbase(char x) {
  return isx(x) || isdigit(x);
}

char fusiondigit(char a,char b,char op) {
  int x;
  if (op == '&') {
    x = (a-'0') & (b-'0');
  } else if (op == '|') {
    x = (a-'0') | (b-'0');
  } else if (op == '^') {
    x = (a-'0') ^ (b-'0');
  }
  return x?'1':'0';
}

void parse(node*& curr,int s,int e) {
  int open = 0;
  if (e-s==0) {
    //base case add num node;
    curr = new node();
    curr->expr = expr[s];
    return;
  }
  for1(i,s,e+1) {
    if (expr[i] == '(') open++;
    else if (expr[i] == ')') open--;
    else if (expr[i] == '&' || expr[i] == '|' || expr[i] == '^') {
      if (open == 1) {
        curr = new node();
        curr->expr = expr[i];
        parse(curr->left,s+1,i-1);
        parse(curr->right,i+1,e-1);
      }
    }
  }
}

void clean(node* curr) {
  if (curr == NULL) {
    return;
  }

  if (curr->left != NULL && curr->right != NULL && isbase(curr->left->expr) && isbase(curr->right->expr)) {
    if ( isdigit(curr->left->expr) && isdigit(curr->right->expr)) {
      curr->expr = fusiondigit(curr->left->expr,curr->right->expr,curr->expr); curr->left = NULL; curr->right = NULL;
    }

    if (curr->expr == '&') {
      if (curr->left->expr == curr->right->expr) {
        curr->expr = curr->left->expr; curr->left = NULL; curr->right = NULL;
      } else if ( (curr->left->expr == 'x' && curr->right->expr == 'X') || (curr->left->expr == 'X' && curr->right->expr == 'x') ) {
        curr->expr = '0'; curr->left = NULL; curr->right = NULL;
      } else if (curr->left->expr == '0' || curr->right->expr == '0') {
        curr->expr = '0'; curr->left = NULL; curr->right = NULL;
      }
    }

    if (curr->expr == '|') {
      if (curr->left->expr == curr->right->expr) {
        curr->expr = curr->left->expr; curr->left = NULL; curr->right = NULL;
      } else if ( (curr->left->expr == 'x' && curr->right->expr == 'X') || (curr->left->expr == 'X' && curr->right->expr == 'x') ) {
        curr->expr = '1'; curr->left = NULL; curr->right = NULL;
      } else if (curr->left->expr == '1' || curr->right->expr == '1') {
        curr->expr = '1'; curr->left = NULL; curr->right = NULL;
      }
    }

    if (curr->expr == '^') {
      if (curr->left->expr == curr->right->expr) {
        curr->expr = '0'; curr->left = NULL; curr->right = NULL;
      } else if ( (curr->left->expr == 'x' && curr->right->expr == 'X') || (curr->left->expr == 'X' && curr->right->expr == 'x') ) {
        curr->expr = '1'; curr->left = NULL; curr->right = NULL;
      }
    }
  }

  clean(curr->left); clean(curr->right);
}

void dbgtree(node* curr) {
  if (curr == NULL) {
    cerr<<"NULL"<<' ';
    return;
  }
  cerr<<(curr->expr)<<' ';
  dbgtree(curr->left); dbgtree(curr->right);
}

int force(node* curr,int target) {
  if (dp[curr->id][target] != -1) return dp[curr->id][target];

  if (curr->expr == '0') {
    if (target == 0) {
      return dp[curr->id][target] = 0;
    } else {
      return dp[curr->id][target] = 1;
    }
  }

  if (curr->expr == '1') {
    if (target == 1) {
      return dp[curr->id][target] = 0;
    } else {
      return dp[curr->id][target] = 1;
    }
  }

  if (curr->expr == 'X') {
    return dp[curr->id][target] = 1;
  }

  if (curr->expr == 'x') {
    return dp[curr->id][target] = 1;
  }

  if (curr->expr == '&') {
    if (target == 0) {
      return dp[curr->id][target] = min(force(curr->left,0),force(curr->right,0));
    } else {
      return dp[curr->id][target] = force(curr->left,1) + force(curr->right,1);
    }
  }

  if (curr->expr == '|') {
    if (target == 0) {
      return dp[curr->id][target] = force(curr->left,0) + force(curr->right,0);
    } else {
      return dp[curr->id][target] = min(force(curr->left,1),force(curr->right,1));
    }
  }

  if (curr->expr == '^') {
    if (target == 1) {
      return dp[curr->id][target] = min( force(curr->left,0) + force(curr->right,1) , force(curr->left,1) + force(curr->right,0) );
    } else {
      return dp[curr->id][target] = min( force(curr->left,0) + force(curr->right,0) , force(curr->left,1) + force(curr->right,1) );

    }
  }

  return dp[curr->id][target] = 1e8;
}

int main() {
  cout << fixed;

  int t; cin>>t;
	for1(_,1,t+1) {
    cin>>expr;
    root = NULL;
    currnodeid = 1;
    memset(dp,-1,sizeof(dp));

    parse(root,0,expr.size()-1);
    //clean(root);

    //dbgtree(root);

    int res = min(force(root,1),force(root,0));

    cout<<"Case #"<<_<<": "<<res<<endl;
  }

  return 0;
}