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

int data[100005];

int n,t;

bool process(int x) {
    //a = x-b ... brute b -> x-b is constant ... find that is x-b in all possible of a ... if not in then cannot find a that = x-b else can
    for1(i,0,n) {
        int b = data[i];
        int a = x-b;
        if(binary_search(data,data+n,a)) return true;
    }
    return false;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
     cin>>n>>t;
    for1(i,0,n) scanf("%d",data+i);
    sort(data,data+n);
    while(t--) {
        int m; scanf("%d",&m);
        if(process(m)) printf("YES\n"); else printf("NO\n");
    }
	return 0;
}
