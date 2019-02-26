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

int n;
int data[1000005];

//0 based
template<int size> //size for reservation only ... must larger than real size
class smtree {
    public:
    
    int basecase = 0;
    int antians = basecase;
    int sm[4*size+5];
    
    int merge(int a,int b) {
        return a+b;
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
        build(1,0,n-1,data);
    }
    
    int query(int i,int s,int e,int ts,int te) {
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
    
    void update(int i,int s,int e,int pos,int val) {
        if (s==e) {
            //cerr<<i<<' '<<val<<endl;
            sm[i] = val;
        } else {
            int mid = (s+e)>>1;
            if (pos<=mid) update(i<<1,s,mid,pos,val);
            else update(i<<1|1,mid+1,e,pos,val);
            sm[i] = merge(sm[i<<1],sm[i<<1|1]);
        }
    }
    
    void update(int pos,int val) {
        return update(1,0,n-1,pos,val);
    }
};

smtree<1000005> sm;

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    cin>>n;
    for1(i,0,n) {
        cin>>data[i];
    }
    
    //sm.buildbase(n);
    sm.build(data,n);
    
    while(true) {
        int q; cin>>q;
        if (q==0) { //sum
            int s,e; cin>>s>>e;
            printf("%d\n",sm(s,e));
        } else if (q==1) {
            int pos,val; cin>>pos>>val;
            sm.update(pos,val);
        }
    }
    return 0;
}
