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
    int n,m; scanf("%d%d",&n,&m);
    int data[n];
    fill(data,data+n,1000000000);
    for1(i,0,m) {
        int id,l; scanf("%d%d",&id,&l);
        id--;
        data[id] = min(data[id],l);
    }
    int sum = 0;
    for1(i,0,n) sum+=data[i];
    printf("%d\n",sum);
    for1(i,0,n) {
        printf("%d %d\n",i+1,data[i]);
    }
	return 0;
}
