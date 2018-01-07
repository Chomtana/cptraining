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

int nr,nc,m;

int sm[305][20005];
int lazy[305][20005];

void update(int r,int c,int s,int e,int ts,int te,int val) {
    if (lazy[r][c]) {
        sm[r][c] = lazy[r][c];
        if (s!=e) {
            lazy[r][c<<1] = lazy[r][c];
            lazy[r][c<<1|1] = lazy[r][c];
        }
        lazy[r][c] = 0;
    }
    if (e<ts || s>te) return;
    if (s>=ts && e<=te) {
        sm[r][c] = val;
        if (s!=e) {
            lazy[r][c<<1] = val;
            lazy[r][c<<1|1] = val;
        }
        return;
    }

    int mid = (s+e)/2;
    update(r,c<<1,s,mid,ts,te,val);
    update(r,c<<1|1,mid+1,e,ts,te,val);
    sm[r][c] = min(sm[r][c<<1],sm[r][c<<1|1]);
}

void update(int r,int cs,int ce,int val) {
    update(r,1,0,nc-1,cs,ce,val);
}

int query(int r,int c,int s,int e,int ts,int te) {
    if (lazy[r][c]) {
        sm[r][c] = lazy[r][c];
        if (s!=e) {
            lazy[r][c<<1] = lazy[r][c];
            lazy[r][c<<1|1] = lazy[r][c];
        }
        lazy[r][c] = 0;
    }
    if (e<ts || s>te) return 1E9;
    if (s>=ts && e<=te) return sm[r][c];
    int mid = (s+e)/2;
    return min(query(r,c<<1,s,mid,ts,te),query(r,c<<1|1,mid+1,e,ts,te));
}

int query(int r,int cs,int ce) {
    return query(r,1,0,nc-1,cs,ce);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>nr>>nc>>m;
    while(m--) {
        int type; scanf("%d",&type);
        if (type==1) {
            int r,c,x; scanf("%d%d%d",&r,&c,&x); r--; c--;
            update(r,c,c,x);
        } else if (type==2) {
            int r,x; scanf("%d%d",&r,&x); r--;
            update(r,0,nc-1,x);
        } else if (type==3) {
            int r,c; scanf("%d%d",&r,&c); r--; c--;
            printf("%d\n",query(r,c,c));
        } else if (type==4) {
            int currmin = 1E9;
            for1(i,0,nr) {
                currmin = min(currmin,query(i,0,nc-1));
            }
            printf("%d\n",currmin);
        }
    }
	return 0;
}
