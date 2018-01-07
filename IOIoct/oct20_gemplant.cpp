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

int n,m;
int fw[200005];

void update(int pos,int val) {
    for(int i = pos;i<=n;i+=(i&(-i))) {
        fw[i] += val;
    }
}

int query(int pos) {
    int res = 0;
    for(int i = pos;i>0;i-=(i&(-i))) {
        res += fw[i];
    }
    return res;
}

int query(int s,int e) {
    return query(e)-(s>1?query(s-1):0);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;
    while(m--) {
        int type,a,b; scanf("%d%d%d",&type,&a,&b);
        if (type==1) update(b,a);
        else {
            printf("%d\n",query(a,b));
        }

    }
	return 0;
}
