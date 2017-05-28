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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m; cin>>n>>m;
    int data[n];
    for1(i,0,n) scanf("%d",data+i);
    while (m--) {
        int s,e; scanf("%d%d",&s,&e);
        int mindif = 1E9;
        int res = 0;
        for1(i,0,n) {
            int dif = abs(s-data[i]);
            if (dif<mindif) {
                mindif = dif;
                res = i;
            }
        }

        printf("%d\n",res+1);
        data[res] = e;
    }
	return 0;
}
