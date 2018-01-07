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

int n,k,m;
pii data[100005];
//int res = 0;

void doans(int pos) {
    printf("Yes\n");
    int dpos = data[pos-1].first;
    for1(i,0,pos) {
        if (data[i].first==dpos) {
            printf("%d ",data[i].second);
        }
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>k>>m;
    for1(i,0,n) {
        int x; scanf("%d",&x);
        data[i].second = x;
        x %= m;
        data[i].first = x;
    }
    sort(data,data+n);
    int x = 1;
    for1(i,1,n) {
        if (x==k) {
            doans(i);
            return 0;
        }
        if (data[i].first==data[i-1].first) {
            x++;
        } else {
            x=1;
        }
    }
    if (x==k) {
        doans(n);
        return 0;
    }

    printf("No");

	return 0;
}
