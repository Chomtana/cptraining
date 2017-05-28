#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<int> data;
vector<int> curr(20);
int p10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

void bt(int nd,int d) {
    int start = 1;
    if (d>=nd) {
        int res = 0;
        for1(i,0,nd) {
            res += curr[i]*p10[nd-i-1];
            //cerr<<curr[i]<<' ';
        }
        //cerr<<res<<endl;
        data.push_back(res);
        return;
    }
    if (d!=0) {
        start = curr[d-1]+1;
    }
    for1(i,start,10) {
        curr[d] = i;
        bt(nd,d+1);
        curr[d] = 0;
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;

    data.reserve(1000);

	bt(1,0);
	bt(2,0);
	bt(3,0);
	bt(4,0);
	bt(5,0);
	bt(6,0);
	bt(7,0);
	bt(8,0);
	bt(9,0);

	int q; cin>>q;

	while (q--) {
        ll n; scanf("%lld",&n);
        if(n>data.size()) {
            printf("-1\n");
        } else {
            printf("%d\n",data[n-1]);
        }
	}
	return 0;
}
