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

vector<int> E[300005];
int data[300005];
int ans[105];

void getans(int c) {
    ans[data[c]]++;
    for(int ne:E[c]) {
        getans(ne);
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,q; cin>>n>>q;
    //E.resize(n+5);
    for1(i,1,n+1) {
        scanf("%d",data+i);
    }

    for1(i,2,n+1) {
        int p; scanf("%d",&p);
        //E[i].push_back(p);
        E[p].push_back(i);
    }

    while (q--) {
        int a,b; scanf("%d %d",&a,&b);
        if (a==0) {
            fill(ans,ans+105,0);
            getans(b);

            int res = 0;

            for1(i,0,105) {
                res += ((ans[i]&1)==1);
            }

            printf("%d\n",res);
        } else {
            data[b] = a;
        }
    }


	return 0;
}
