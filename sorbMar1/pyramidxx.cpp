#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//0 based
template<int size> //size for reservation only ... must larger than real size
class smtree {
    public:
    
    int basecase = 0;
    int antians = basecase;
    int sm[4*size+5];
    int lazy[4*size+5];
    int n = size;
    
    int merge(int a,int b) {
        return a+b;
    }
    
    void lazy_update(int i,int s,int e) {
        //customize here
        if (lazy[i]!=basecase) {
            //update original segment tree
            sm[i] += lazy[i]*(e-s+1);
            
            //update lazy segment tree
            if ((i<<1) < 4*size+5) lazy[i<<1] += lazy[i];
            if ((i<<1|1) < 4*size+5) lazy[i<<1|1] += lazy[i];
            lazy[i] = 0;
        }
    }
    
    void buildbase(int i,int s,int e) {
        if (s==e) {
            sm[i] = basecase;
        } else {
            int mid = (s+e)>>1;
            buildbase(i<<1,s,mid);
            buildbase(i<<1|1,mid+1,e);
            sm[i] = merge(sm[i<<1],sm[i<<1|1]);
        }
    }
    
    void buildbase(int n) {
        this->n = n;
        buildbase(1,0,n-1);
    }
    
    void build(int i,int s,int e,int *data) {
        if (s==e) {
            sm[i] = data[s];
        } else {
            int mid = (s+e)>>1;
            build(i<<1,s,mid,data);
            build(i<<1|1,mid+1,e,data);
            sm[i] = merge(sm[i<<1],sm[i<<1|1]);
        }
    }
    
    void build(int *data,int n) {
        this->n = n;
        build(1,0,n-1,data);
    }
    
    int query(int i,int s,int e,int ts,int te) {
        lazy_update(i,s,e);
        
        if (s>=ts && e<=te) return sm[i];
        if (e<ts || s>te) return antians;
        int mid = (s+e)>>1;
        return merge(query(i<<1,s,mid,ts,te),query(i<<1|1,mid+1,e,ts,te));
    }
    
    int operator () () { //best case query (entire range)
        return sm[1];
    }
    
    int operator () (int ts,int te) {
        return query(1,0,n-1,ts,te);
    }
    
    void update(int i,int s,int e,int ts,int te,int val) {
        lazy_update(i,s,e);
        
        if (s>=ts && e<=te) {
            lazy[i] += val;
            lazy_update(i,s,e);
            return;
        }
        if (e<ts || s>te) return;
    
        int mid = (s+e)>>1;
        update(i<<1,s,mid,ts,te,val);
        update(i<<1|1,mid+1,e,ts,te,val);
        sm[i] = merge(sm[i<<1],sm[i<<1|1]);
    }
    
    void update(int ts,int te,int val) {
        return update(1,0,n-1,ts,te,val);
    }
};

int main() {
    
    return 0;
}