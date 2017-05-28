#include <iostream>
#include <cstdio>
#include <queue>

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

int data[1000000];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m; cin>>n>>m;

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for1(i,0,n) {
        scanf("%d",data+i);
        pq.push(mp(data[i],i));
        if (i<m) {
            printf("0\n");
        } else return 0;
    }
    m-=n;
    while (m--) {
        printf("%d\n",pq.top().first);
        int ne = pq.top().first+data[pq.top().second];
        int i = pq.top().second;
        pq.pop();
        pq.push(mp(ne,i));
    }
	return 0;
}
