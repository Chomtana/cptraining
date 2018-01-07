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

int n,l1,l2;
int data1[300005];
int data2[300005];
int i1[300005];
int c[300005];
vector<int> lis;


int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; while(t--) {
        scanf("%d%d%d",&n,&l1,&l2);
        memset(i1,0,sizeof(i1));
        for1(i,1,l1+1) {
            scanf("%d",data1+i);
            i1[data1[i]] = i;
        }
        for1(i,1,l2+1) {
            scanf("%d",data2+i);
        }

        for1(i,1,l2+1) {
            c[i] = i1[data2[i]];
        }

        for1(i,1,l2+1) {
            if (c[i]==0) continue;
            auto it = lower_bound(all(lis),c[i]);
            if (it==lis.end()) {
                lis.push_back(c[i]);
            } else {
                *it = c[i];
            }
        }

        printf("%d\n",lis.size());
        lis.clear();
	}
	return 0;
}
