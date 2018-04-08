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

void tsort(vector<int> &L) {
    bool done = false;
    while (!done) {
        done = true;
        for(int i = 0;i<L.size()-2;i++) {
            if (L[i]>L[i+2]) {
                done = false;
                swap(L[i],L[i+2]);
            }
        }
    }
}

int check(vector<int> &a) {
    int res = 0;
    for1(i,0,a.size()-1) {
        if (a[i]>a[i+1]) {
            return i;
        }
    }
    return -1;
}

int main() {
	//ios::sync_with_stdio(false);
    srand(time(0));
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        printf("Case #%d: \n",_);
        int n=99; //scanf("%d",&n);
        vector<int> a(n,0);
        vector<int> a1;
        vector<int> a2;
        for1(i,0,n) {
            //scanf("%d",&a[i]);
            a[i] = rand()%1000000;
            //printf("%d ",a[i]);
            if (i%2==0) a1.push_back(a[i]); else a2.push_back(a[i]);
        }
        /*printf("\n");
        tsort(a);
        for1(i,0,n) printf("%d ",a[i]);
        printf("\n");

        for1(i,0,a1.size()) printf("%d ",a1[i]);
        sort(all(a1));
        printf("-> ");
        for1(i,0,a1.size()) printf("%d ",a1[i]);
        printf("\n");

        for1(i,0,a2.size()) printf("%d ",a2[i]);
        sort(all(a2));
        printf("-> ");
        for1(i,0,a2.size()) printf("%d ",a2[i]);
        printf("\n");*/

        vector<int> am(n,0);
        for1(i,0,a1.size()) {
            am[2*i] = a1[i];
        } 
        for1(i,0,a2.size()) {
            am[2*i+1] = a2[i];
        }

        if (am!=a) {
            printf("===> Fail!!! <===");
        }

        /*for1(i,0,n) printf("%d ",am[i]);
        printf("\n");*/

        int res = check(a);
        if (res==-1) printf("OK\n"); else printf("%d\n",res);
    }
	return 0;
}
