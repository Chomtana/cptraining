#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define mt make_tuple
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

typedef pair<tuple<int,int,int>,tuple<int,int,int>> type;

int calcost(int x,int y,int z) {
    x = abs(x);
    y = abs(y);
    z = abs(z);
    //return powl(x,2) + powl(y,2) + powl(z,2);
    return x*x+y*y+z*z;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int want; cin>>want; //don't forget changing of variable name
    int sx,sy,sz; cin>>sx>>sy>>sz;
    int n; cin>>n;
    type data[n];
    for1(i,0,n) {
        int x,y,z,a,b,c; cin>>x>>y>>z>>a>>b>>c;
        data[i] = mp(mt(x,y,z),mt(a,b,c));
    }

    sort(data,data+n);

    int mincost = 1E9;

    do {
        //sort(data,data+n) -> next_permutation(data,data+n) -> here data keep all permutation of data (process one each loop)
        int cx=sx,cy=sy,cz=sz;
        int ca=0,cb=0,cc=0;
        int cost = 0;
        for1(i,0,n) {
            int x = get<0>(data[i].first);
            int y = get<1>(data[i].first);
            int z = get<2>(data[i].first);
            int a = get<0>(data[i].second);
            int b = get<1>(data[i].second);
            int c = get<2>(data[i].second);
            cost += calcost(x-cx,y-cy,z-cz);
            cx = x; cy=y;cz=z;
            ca += a; cb+= b; cc+=c;
            if (ca>=want && cb>=want && cc>=want) {
                break;
            }
        }
        mincost = min(mincost,cost);
    } while (next_permutation(data,data+n));

    cout<<mincost;
	return 0;
}
