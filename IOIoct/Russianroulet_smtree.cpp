#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

#define sm_ba int c,int s,int e
#define sm_l c<<1,s,mid
#define sm_r c<<1|1,mid+1,e
#define sm_bai 1,1,n

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;

int n,k;

class smtree {
    public:
    vector<int> ret;
    int sm[4000005];
    bool basecase[4000005];
    bool rightend[4000005];
    int E[4000005];

    void build(sm_ba) {
        E[c] = e;
        if (s==e) {
            sm[c] = 1;
            basecase[c] = true;
        } else {
            int mid = (s+e)>>1;
            build(sm_l);
            build(sm_r);
            sm[c] = sm[c<<1]+sm[c<<1|1];
            if (e==n) {
                rightend[c] = true;
            }
        }
    }

    void build() {
        fill(basecase,basecase+4000005,false);
        fill(rightend,rightend+4000005,false);
        build(sm_bai);

    }

    void part(sm_ba,int ts,int te) {
        if (s>=ts && e<=te) {
            //outside return is ok because it isn't a dp function
            //outside return = add current value to global return result variable
            //must clear each run
            //but mang dai ans kae tong te mun end (yung mai dai merge)
            ret.push_back(c);
            return;
        }

        if (e<ts || s>te) return;

        int mid = (s+e)/2;
        part(sm_l,ts,te);
        part(sm_r,ts,te);
    }

    void part(int ts,int te) {
        ret.clear();
        part(sm_bai,ts,te);
    }

    int bs(int s,int kk) { //target : == k ; == -> if = then return index (index is end of current bound)
        part(s,n);
        int curr = 0;
        for1(i,0,ret.size()) {
            curr += sm[ret[i]];
            //cerr<<"aaa "<<curr<<' ';
            if (curr==kk) {
                return E[ret[i]];
            } else if (curr>kk) {
                int cc = ret[i];
                while (curr!=kk) {
                    //cerr<<"aaa "<<cc<<endl;
                    curr -= sm[cc];
                    if (basecase[cc]) return -1;
                    cc = cc<<1;
                    while (curr<kk) {
                        curr += sm[cc];
                        if (curr<kk && rightend[cc]) return -1;
                        cc++;
                    }
                    cc--;
                }
                return E[cc];
            }
        }
        return -1;
    }

    void update(sm_ba,int p,int val) {
        if (s==e) {
            sm[c] = val;
        } else {
            int mid=(s+e)>>1;
            if (p<=mid) update(sm_l,p,val);
            else update(sm_r,p,val);
            sm[c] = sm[c<<1]+sm[c<<1|1];
        }
    }

    void update(int p,int val) {
        update(sm_bai,p,val);
    }

    int query(int ts) {
        part(ts,n);
        int res = 0;
        for1(i,0,ret.size()) {
            res += (int)sm[ret[i]];
        }
        return res;
    }
};

smtree sm;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>k;
    sm.build();
    //for1(i,0,100) cerr<<sm.sm[i]<<' '; cerr<<endl;
    //for1(i,0,n-3) cerr<<sm.bs(i+1)<<' ';
    //cerr<<sm.bs(1,2)<<endl;
    //cerr<<sm.query(2);



    int c = 1;
    int rek = k;
    for1(_,0,n-1) {
        cerr<<c<<' ';
        c = sm.bs(c,rek);
        cerr<<c<<' '<<rek<<" , ";
        if (c!=-1) {
            sm.update(c,0);
            c++;
        } else {
            rek -= sm.query(c);
            c = 1;
            _--;
            continue;
        }
        rek = k;
    }

    cerr<<endl;

    //cerr<<sm.query(1);
    cout<<sm.bs(1,1);
	return 0;
}
