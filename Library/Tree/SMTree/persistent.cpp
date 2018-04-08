#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

//persistent segment tree 0 based
template<int size,int vercount>
class smtree {
    public:
    
    int basecase = 0;
    int antians = basecase;
    int n = size;
    
    static int merge(int a,int b) {
        return a+b;
    }
    
    struct smnode {
        smnode* l = NULL;
        smnode* r = NULL;
        int val = 0;
        
        smnode() {}
        smnode(int val): l(NULL), r(NULL), val(val) {}
        smnode(smnode* l,smnode* r): l(l), r(r), val(0) {
            if (l) val = merge(val,l->val);
            if (r) val = merge(val,r->val);
        }
        smnode(smnode* l,smnode* r,int val): l(l), r(r), val(val) {}
        
        int query(int s,int e,int ts,int te) {
            if (s>=ts && e<=te) return this->val;
            if (e<ts || s>te) return 0; //antians
            int mid = (s+e)>>1;
            return merge(this->l->query(s,mid,ts,te),this->r->query(mid+1,e,ts,te));
        }
        
        int query () { //best case query (entire range)
            return this->val;
        }
        
        int query (int ts,int te) {
            return query(0,size-1,ts,te);
        }
        
        smnode* update(int s,int e,int pos,int val) {
            if (s==e) return new smnode(val);
            int mid = (s+e)>>1;
            if (pos<=mid) return new smnode(this->l->update(s,mid,pos,val),this->r);
            else return new smnode(this->l,this->r->update(mid+1,e,pos,val));
        }
        
        smnode* update(int pos,int val) {
            return update(0,size-1,pos,val);
        }
    };
    
    smnode* sm[vercount+5];
    
    smnode* buildbase(int s,int e) {
        if (s==e) {
            return new smnode(basecase);
        } else {
            int mid = (s+e)>>1;
            return new smnode(buildbase(s,mid),buildbase(mid+1,e));
        }
    }
    
    smnode* buildbase() {
        return buildbase(0,size-1);
    }
    
    smnode* build(int i,int s,int e,int *data) {
        if (s==e) {
            return new smnode(data[s]);
        } else {
            int mid = (s+e)>>1;
            return new smnode(build(s,mid,data),build(mid+1,e,data));
        }
    }
    
    smnode* build(int *data) {
        return new smnode(build(0,size-1,data));
    }
    
    smnode*& operator [](int i) {
        return sm[i];
    }
};

smtree<1000005,1000005> sm;

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    sm[0] = sm.buildbase();
    while (true) {
        int type; cin>>type;
        if (type==0) {
            int v,s,e; cin>>v>>s>>e;
            printf("%d\n",sm[v]->query(s,e));
        } else if (type==1) {
            int vout,vin,pos,val; cin>>vout>>vin>>pos>>val;
            sm[vout] = sm[vin]->update(pos,val);
        }
    }
    return 0;
}
