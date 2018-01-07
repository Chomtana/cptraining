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
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;

int n;
int data[50005];
int qs[50005];
int sm[200005];
int smmaxqs[200005];
int smminqs[200005];

piii fusion(piii a,piii b) {
    piii res;
    res.first.first = max(a.first.first,b.first.first);
    res.first.second = min(a.first.second,b.first.second);
    res.second = max(max(a.second,b.second),b.first.first-a.first.second);
    return res;
}

void buildsm(int c,int s,int e) {
    if (s==e) {
        sm[c] = data[s];
    } else {
        int mid = (s+e)/2;
        build(2*c,s,mid);
        build(2*c+1,mid+1,e);
        sm[c] = max(max(sm[2*c],sm[2*c+1]),querymaxqs(s,e)-queryminqs((s>0?s-1:0),e));
        if (s==0) {
            sm[c] = max(sm[c],querymaxqs(s,e));
        }
    }
}

piii query(int c,int s,int e,int ts,int te) {
    if (e<ts || s>te) {
        return mp(mp(-1E9,1E9),-1E9);
    }

    if (s>=ts && e<=te) {
        return sm[c];
    }

    int mid = (s+e)/2;

    return fusion(query(2*c,s,mid,ts,te),query(2*c+1,mid+1,e,ts,te));
}

int query(int ts,int te) {
    return query(1,0,n-1,ts,te).second;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    for1(i,0,n) {
        scanf("%d",data+i);
    }

    qs[0] = data[0];
    for1(i,1,n) qs[i]=qs[i-1]+data[i];

    build(1,0,n-1);

    //for1(i,1,

    int m; cin>>m;
    while (m--) {
        int x,y; scanf("%d%d",&x,&y);
        x--; y--;
        printf("%d\n",query(x,y));
    }
	return 0;
}
