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
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;

int n,m;

piii sm[400005];

piii fusion(piii &a,piii &b) {
    return {a.first+b.first,{a.second.first+b.second.first,a.second.second+b.second.second}};

}

void update(int p,int val,int c=1,int s=1,int e=n+1) {
    if (s==e) {
            //cerr<<"aaa "<<c<<' '<<p<<' '<<val<<endl;
        sm[c].first += val;
        if(sm[c].first>0) {
            sm[c].second = mp(1,0);
        } else if (sm[c].first<0) {
            sm[c].second = mp(0,1);
        } else {
            sm[c].second = mp(0,0);
        }
    } else {
        int mid = (s+e)/2;
        if (p<=mid) update(p,val,c<<1,s,mid);
        if (p>mid) update(p,val,c<<1|1,mid+1,e);
        sm[c] = fusion(sm[c<<1],sm[c<<1|1]);
    }
}

int query1(int ts,int te,int c=1,int s=1,int e=n+1) {
    if (s>=ts&&e<=te) {
        return sm[c].first;
    }
    if (e<ts || s>te) return 0;
    int mid = (s+e)/2;
    return query1(ts,te,c<<1,s,mid) +
    query1(ts,te,c<<1|1,mid+1,e);
}

pii query2(int ts,int te,int c=1,int s=1,int e=n+1) {
    if (s>=ts&&e<=te) {
        return sm[c].second;
    }
    if (e<ts || s>te) return mp(0,0);
    int mid = (s+e)/2;
    pii a = query2(ts,te,c<<1,s,mid);
    pii b = query2(ts,te,c<<1|1,mid+1,e);
    return {a.first+b.first,a.second+b.second};
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;
    for1(i,0,m) {
        int t; scanf("%d",&t);
        if (t==1) {
            int s,e; scanf("%d%d",&s,&e);
            update(s,1);
            update(e+1,-1);
            /*for1(i,0,25) {
                cerr<<sm[i].first<<' ';
            }
            cerr<<endl;*/
        } else if (t==2) {
            int s,e; scanf("%d%d",&s,&e);
            printf("%d %d\n",query1(0,s),query1(0,e));
        } else if (t==3) {
            int s,e; scanf("%d%d",&s,&e);
            pii res = mp(0,0);
            if (s<n) res = query2(s+1,e);
            printf("%d %d %d %d\n",query1(0,s),query1(0,e),res.first,res.second);
        }
    }
	return 0;
}
